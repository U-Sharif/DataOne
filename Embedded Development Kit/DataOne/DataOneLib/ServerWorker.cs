using System;
using System.Collections.Generic;
using System.Text;
using System.Net.Sockets;
using System.IO;
using System.Threading;

namespace DataOneLib
{
    public class ServerWorker
    {
        public event DataOneLib.Server.ServerEvent OnRequest;

        public Logger mLogger;
        private Socket mSocket;
        private int mStart;
        private string mDescription;
        private NetworkStream mStream;
        private StreamReader mReader;
        private StreamWriter mWriter;
        public bool Stable = true;

        private Queue<string> mDataQueue = new Queue<string>();

        public ServerWorker() { }

        public ServerWorker(Logger l)
        {
            mLogger = l;
        }

        public void Work(object o)
        {
            mSocket = (Socket)o;

            mStream = new NetworkStream(mSocket);
            mReader = new StreamReader(mStream);
            mWriter = new StreamWriter(mStream);

            try
            {
                string req = mReader.ReadLine();
                req = req.Substring(1);
                req = req.Trim('\r', '\n', ' ', '\t', '\b');
                mStart = int.Parse(req);

                if (OnRequest != null)
                    OnRequest(mSocket.RemoteEndPoint, mStart);

                List<FileInfo> files = new List<FileInfo>();
                files.AddRange(new DirectoryInfo(mLogger.LogPath).GetFiles());
                files.Sort((Comparison<FileInfo>)delegate(FileInfo one, FileInfo two)
                {
                    return one.Name.CompareTo(two.Name);
                });

                mDescription = Config.Data["description"];

                foreach (FileInfo f in files)
                {
                    FileInfo next = null;
                    if (files.IndexOf(f) < files.Count - 1)
                        next = files[files.IndexOf(f) + 1];
                    if (next == null || mStart <= int.Parse(next.Name.Split(' ')[0]))
                        try
                        {
                            FileStream fs = f.Open(FileMode.Open, FileAccess.Read, FileShare.Read);
                            StreamReader fsr = new StreamReader(fs);
                            while (!fsr.EndOfStream)
                            {
                                string l = fsr.ReadLine();
                                if (!l.StartsWith("#"))
                                    SendString(l);
                                else if (l.Contains("description"))
                                    mDescription = l.Split('=')[1].Trim();
                            }
                            fsr.Close();
                        }
                        catch { }
                }

                lock (mLogger.LiveStream) lock (mDataQueue)
                    {
                        foreach (string ss in mLogger.LiveStream)
                            mDataQueue.Enqueue(ss);
                    }

                mLogger.OnLog += new Logger.LogEvent(mLogger_OnLog);

                while (true)
                {
                    mDescription = Config.Data["description"];
                    if (mDataQueue.Count > 0)
                        lock (mDataQueue)
                            try
                            {
                                SendString(mDataQueue.Dequeue());
                            }
                            catch {
                                if (!Stable)
                                    throw;
                            }
                    else
                        Thread.Sleep(100);
                }
            }
            catch { }
        }

        public void mLogger_OnLog(string l)
        {
            lock (mDataQueue)
                mDataQueue.Enqueue(l);
        }

        void SendString(string l)
        {
            bool disconnect = false;
            try
            {
                if (int.Parse(l.Split(',')[0]) >= mStart)
                    lock (mSocket)
                    {
                        string[] csv = l.Split(',');
                        mWriter.WriteLine(csv[0] + "," + ((csv[2] != "") ? csv[2] : "0") + "," + csv[3] + "," + mDescription);
                        mWriter.Flush();
                    }
                if (mStream.DataAvailable)
                {
                    disconnect = true;
                    throw new SocketException();
                }
            }
            catch (SocketException e)
            {
                if (e.SocketErrorCode == SocketError.ConnectionAborted || disconnect)
                    OnRequest(mSocket.RemoteEndPoint, -1);
                mLogger.OnLog -= new Logger.LogEvent(mLogger_OnLog);
                try
                {
                    mSocket.Disconnect(false);
                }
                catch { }
                throw;
            }
            catch { }
        }
    }
}
