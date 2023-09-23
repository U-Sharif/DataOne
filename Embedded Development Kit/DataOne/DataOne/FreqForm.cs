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
    public partial class FreqForm : Form
    {
        public D1Client Client;
        bool Got = false;


        public FreqForm()
        {
            InitializeComponent();
        }

        private void button5_Click(object sender, EventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (!Got && Client.HasFreq)
            {
                label1.Text = "Frequency: " + Client.Freq;
                Got = true;
            }
        }

        private void FreqForm_Load(object sender, EventArgs e)
        {
            Client.RequestFreq();
        }
    }
}