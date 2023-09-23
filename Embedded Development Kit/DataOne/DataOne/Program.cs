using System;
using System.Collections.Generic;
using System.Windows.Forms;
using DataOneLib;
using System.Globalization;
using System.IO;

namespace DataOne
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            try
            {
                Application.Run(new ConnectForm());
            }
            catch (Exception e)
            {
                File.WriteAllText(Application.StartupPath + "\\error.log", e.ToString() + "\n\n\n");
            }
        }
    }
}