using System;
using System.Collections.Generic;
using System.Text;

namespace DataOneLib
{
    public abstract class BaseHardwareReader
    {
        public delegate void TagEvent(OneTag t);
        public delegate void DisconnectEvent();
        public virtual event TagEvent OnTag;
        public virtual event DisconnectEvent OnDisconnect;
        public abstract bool Connected { get;}
        public abstract bool CanWrite { get;}

        public abstract void Connect(string addr, int port);
        public abstract List<OneTag> Query(double secs);
        public abstract void Start();
        public abstract void Stop();
        public abstract bool WriteTag(string oldEpc, string newEpc);

        public virtual object GetSettings() { return null; }
        public virtual void SetSettings(object settings) { }
        public virtual void ResetSettings() { }
    }
}
