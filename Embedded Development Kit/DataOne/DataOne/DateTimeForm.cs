using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using DataOneLib;

namespace DataOne
{
    public partial class DateTimeForm : Form
    {
        public D1Client Client;
        bool GotTime = false;

        public DateTimeForm()
        {
            InitializeComponent();
        }

        private void DateTimeForm_Load(object sender, EventArgs e)
        {
            Client.RequestTime();
        }

        private void QueryTimer_Tick(object sender, EventArgs e)
        {
            if (!GotTime && Client.HasTime)
            {
                dateTimePicker1.Value = Client.Time;
                GotTime = true;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Client.SetTime(dateTimePicker1.Value);
            Close();
        }
    }
}