namespace SyntaxXMLParserTest
{
    partial class Form1
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
            this.dataFileBox = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.dataFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.pathsBox = new System.Windows.Forms.ListBox();
            this.fontGrid = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.fontGrid)).BeginInit();
            this.SuspendLayout();
            // 
            // dataFileBox
            // 
            this.dataFileBox.AcceptsTab = true;
            this.dataFileBox.Location = new System.Drawing.Point(13, 24);
            this.dataFileBox.Name = "dataFileBox";
            this.dataFileBox.ReadOnly = true;
            this.dataFileBox.Size = new System.Drawing.Size(184, 22);
            this.dataFileBox.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(203, 22);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 1;
            this.button1.Text = "Data File";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // dataFileDialog
            // 
            this.dataFileDialog.FileName = "openFileDialog1";
            // 
            // pathsBox
            // 
            this.pathsBox.FormattingEnabled = true;
            this.pathsBox.ItemHeight = 16;
            this.pathsBox.Location = new System.Drawing.Point(13, 53);
            this.pathsBox.Name = "pathsBox";
            this.pathsBox.Size = new System.Drawing.Size(744, 68);
            this.pathsBox.TabIndex = 2;
            // 
            // fontGrid
            // 
            this.fontGrid.AllowUserToAddRows = false;
            this.fontGrid.AllowUserToDeleteRows = false;
            this.fontGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.fontGrid.Location = new System.Drawing.Point(13, 128);
            this.fontGrid.Name = "fontGrid";
            this.fontGrid.ReadOnly = true;
            this.fontGrid.RowTemplate.Height = 24;
            this.fontGrid.Size = new System.Drawing.Size(744, 258);
            this.fontGrid.TabIndex = 3;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(784, 398);
            this.Controls.Add(this.fontGrid);
            this.Controls.Add(this.pathsBox);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.dataFileBox);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.fontGrid)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox dataFileBox;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.OpenFileDialog dataFileDialog;
        private System.Windows.Forms.ListBox pathsBox;
        private System.Windows.Forms.DataGridView fontGrid;
    }
}

