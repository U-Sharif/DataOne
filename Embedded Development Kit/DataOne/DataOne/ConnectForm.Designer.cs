namespace DataOne
{
    partial class ConnectForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.ConnectButton = new System.Windows.Forms.Button();
            this.Progress = new System.Windows.Forms.ProgressBar();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton3 = new System.Windows.Forms.RadioButton();
            this.PortBox = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.AddressBox = new System.Windows.Forms.ComboBox();
            this.OBModeP = new System.Windows.Forms.RadioButton();
            this.OBModeI = new System.Windows.Forms.RadioButton();
            this.panel1 = new System.Windows.Forms.Panel();
            this.CreateButton = new System.Windows.Forms.Button();
            this.NewNameBox = new System.Windows.Forms.TextBox();
            this.ConfigList = new System.Windows.Forms.ListView();
            this.columnHeader1 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader2 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader3 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader4 = new System.Windows.Forms.ColumnHeader();
            this.FilesGB = new System.Windows.Forms.GroupBox();
            this.StartCreatingButton = new System.Windows.Forms.Button();
            this.SelectButton = new System.Windows.Forms.Button();
            this.ConnectionGB = new System.Windows.Forms.GroupBox();
            this.panel1.SuspendLayout();
            this.FilesGB.SuspendLayout();
            this.ConnectionGB.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(152, 21);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(85, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Reader address:";
            // 
            // ConnectButton
            // 
            this.ConnectButton.Location = new System.Drawing.Point(297, 65);
            this.ConnectButton.Name = "ConnectButton";
            this.ConnectButton.Size = new System.Drawing.Size(95, 36);
            this.ConnectButton.TabIndex = 2;
            this.ConnectButton.Text = "Connect";
            this.ConnectButton.UseVisualStyleBackColor = true;
            this.ConnectButton.Click += new System.EventHandler(this.ConnectButton_Click);
            // 
            // Progress
            // 
            this.Progress.Location = new System.Drawing.Point(297, 107);
            this.Progress.Name = "Progress";
            this.Progress.Size = new System.Drawing.Size(94, 11);
            this.Progress.TabIndex = 3;
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Checked = true;
            this.radioButton1.Location = new System.Drawing.Point(6, 19);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(86, 17);
            this.radioButton1.TabIndex = 4;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "DS DataOne";
            this.radioButton1.UseVisualStyleBackColor = true;
            this.radioButton1.CheckedChanged += new System.EventHandler(this.radioButton_CheckedChanged);
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(6, 42);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(121, 17);
            this.radioButton2.TabIndex = 5;
            this.radioButton2.Text = "DateOne orangebox";
            this.radioButton2.UseVisualStyleBackColor = true;
            this.radioButton2.CheckedChanged += new System.EventHandler(this.radioButton_CheckedChanged);
            // 
            // radioButton3
            // 
            this.radioButton3.AutoSize = true;
            this.radioButton3.Location = new System.Drawing.Point(6, 65);
            this.radioButton3.Name = "radioButton3";
            this.radioButton3.Size = new System.Drawing.Size(81, 17);
            this.radioButton3.TabIndex = 6;
            this.radioButton3.Text = "Handreader";
            this.radioButton3.UseVisualStyleBackColor = true;
            this.radioButton3.CheckedChanged += new System.EventHandler(this.radioButton_CheckedChanged);
            // 
            // PortBox
            // 
            this.PortBox.Location = new System.Drawing.Point(332, 37);
            this.PortBox.Name = "PortBox";
            this.PortBox.Size = new System.Drawing.Size(60, 20);
            this.PortBox.TabIndex = 8;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(329, 21);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(26, 13);
            this.label2.TabIndex = 7;
            this.label2.Text = "Port";
            // 
            // AddressBox
            // 
            this.AddressBox.FormattingEnabled = true;
            this.AddressBox.Location = new System.Drawing.Point(155, 36);
            this.AddressBox.Name = "AddressBox";
            this.AddressBox.Size = new System.Drawing.Size(171, 21);
            this.AddressBox.TabIndex = 9;
            this.AddressBox.SelectedIndexChanged += new System.EventHandler(this.AddressBox_SelectedIndexChanged);
            // 
            // OBModeP
            // 
            this.OBModeP.AutoSize = true;
            this.OBModeP.Checked = true;
            this.OBModeP.Location = new System.Drawing.Point(3, 0);
            this.OBModeP.Name = "OBModeP";
            this.OBModeP.Size = new System.Drawing.Size(32, 17);
            this.OBModeP.TabIndex = 10;
            this.OBModeP.TabStop = true;
            this.OBModeP.Text = "P";
            this.OBModeP.UseVisualStyleBackColor = true;
            // 
            // OBModeI
            // 
            this.OBModeI.AutoSize = true;
            this.OBModeI.Location = new System.Drawing.Point(41, 0);
            this.OBModeI.Name = "OBModeI";
            this.OBModeI.Size = new System.Drawing.Size(28, 17);
            this.OBModeI.TabIndex = 11;
            this.OBModeI.Text = "I";
            this.OBModeI.UseVisualStyleBackColor = true;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.OBModeP);
            this.panel1.Controls.Add(this.OBModeI);
            this.panel1.Location = new System.Drawing.Point(155, 65);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(83, 21);
            this.panel1.TabIndex = 12;
            // 
            // CreateButton
            // 
            this.CreateButton.Location = new System.Drawing.Point(316, 133);
            this.CreateButton.Name = "CreateButton";
            this.CreateButton.Size = new System.Drawing.Size(75, 23);
            this.CreateButton.TabIndex = 16;
            this.CreateButton.Text = "Create";
            this.CreateButton.UseVisualStyleBackColor = true;
            this.CreateButton.Visible = false;
            this.CreateButton.Click += new System.EventHandler(this.CreateButton_Click);
            // 
            // NewNameBox
            // 
            this.NewNameBox.Location = new System.Drawing.Point(5, 135);
            this.NewNameBox.Name = "NewNameBox";
            this.NewNameBox.Size = new System.Drawing.Size(305, 20);
            this.NewNameBox.TabIndex = 15;
            this.NewNameBox.Visible = false;
            // 
            // ConfigList
            // 
            this.ConfigList.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3,
            this.columnHeader4});
            this.ConfigList.FullRowSelect = true;
            this.ConfigList.Location = new System.Drawing.Point(6, 19);
            this.ConfigList.Name = "ConfigList";
            this.ConfigList.Size = new System.Drawing.Size(386, 108);
            this.ConfigList.TabIndex = 17;
            this.ConfigList.UseCompatibleStateImageBehavior = false;
            this.ConfigList.View = System.Windows.Forms.View.Details;
            this.ConfigList.DoubleClick += new System.EventHandler(this.ConfigList_DoubleClick);
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "Name";
            this.columnHeader1.Width = 70;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "Device";
            this.columnHeader2.Width = 96;
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "Description";
            this.columnHeader3.Width = 99;
            // 
            // columnHeader4
            // 
            this.columnHeader4.Text = "Address";
            this.columnHeader4.Width = 99;
            // 
            // FilesGB
            // 
            this.FilesGB.Controls.Add(this.StartCreatingButton);
            this.FilesGB.Controls.Add(this.CreateButton);
            this.FilesGB.Controls.Add(this.SelectButton);
            this.FilesGB.Controls.Add(this.ConfigList);
            this.FilesGB.Controls.Add(this.NewNameBox);
            this.FilesGB.Location = new System.Drawing.Point(12, 12);
            this.FilesGB.Name = "FilesGB";
            this.FilesGB.Size = new System.Drawing.Size(400, 180);
            this.FilesGB.TabIndex = 18;
            this.FilesGB.TabStop = false;
            this.FilesGB.Text = "Present configs";
            // 
            // StartCreatingButton
            // 
            this.StartCreatingButton.Location = new System.Drawing.Point(195, 135);
            this.StartCreatingButton.Name = "StartCreatingButton";
            this.StartCreatingButton.Size = new System.Drawing.Size(95, 36);
            this.StartCreatingButton.TabIndex = 19;
            this.StartCreatingButton.Text = "Create new";
            this.StartCreatingButton.UseVisualStyleBackColor = true;
            this.StartCreatingButton.Click += new System.EventHandler(this.StartCreatingButton_Click);
            // 
            // SelectButton
            // 
            this.SelectButton.Location = new System.Drawing.Point(296, 135);
            this.SelectButton.Name = "SelectButton";
            this.SelectButton.Size = new System.Drawing.Size(95, 36);
            this.SelectButton.TabIndex = 18;
            this.SelectButton.Text = "Select";
            this.SelectButton.UseVisualStyleBackColor = true;
            this.SelectButton.Click += new System.EventHandler(this.SelectButton_Click);
            // 
            // ConnectionGB
            // 
            this.ConnectionGB.Controls.Add(this.radioButton1);
            this.ConnectionGB.Controls.Add(this.label1);
            this.ConnectionGB.Controls.Add(this.panel1);
            this.ConnectionGB.Controls.Add(this.ConnectButton);
            this.ConnectionGB.Controls.Add(this.AddressBox);
            this.ConnectionGB.Controls.Add(this.Progress);
            this.ConnectionGB.Controls.Add(this.PortBox);
            this.ConnectionGB.Controls.Add(this.radioButton2);
            this.ConnectionGB.Controls.Add(this.label2);
            this.ConnectionGB.Controls.Add(this.radioButton3);
            this.ConnectionGB.Enabled = false;
            this.ConnectionGB.Location = new System.Drawing.Point(12, 198);
            this.ConnectionGB.Name = "ConnectionGB";
            this.ConnectionGB.Size = new System.Drawing.Size(400, 129);
            this.ConnectionGB.TabIndex = 19;
            this.ConnectionGB.TabStop = false;
            this.ConnectionGB.Text = "Config details";
            // 
            // ConnectForm
            // 
            this.AcceptButton = this.ConnectButton;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(417, 333);
            this.Controls.Add(this.ConnectionGB);
            this.Controls.Add(this.FilesGB);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "ConnectForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "DataOne";
            this.Load += new System.EventHandler(this.ConnectForm_Load);
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.ConnectForm_FormClosing);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.FilesGB.ResumeLayout(false);
            this.FilesGB.PerformLayout();
            this.ConnectionGB.ResumeLayout(false);
            this.ConnectionGB.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button ConnectButton;
        private System.Windows.Forms.ProgressBar Progress;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton radioButton3;
        private System.Windows.Forms.TextBox PortBox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox AddressBox;
        private System.Windows.Forms.RadioButton OBModeP;
        private System.Windows.Forms.RadioButton OBModeI;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button CreateButton;
        private System.Windows.Forms.TextBox NewNameBox;
        private System.Windows.Forms.ListView ConfigList;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.ColumnHeader columnHeader4;
        private System.Windows.Forms.GroupBox FilesGB;
        private System.Windows.Forms.Button SelectButton;
        private System.Windows.Forms.GroupBox ConnectionGB;
        private System.Windows.Forms.Button StartCreatingButton;
    }
}