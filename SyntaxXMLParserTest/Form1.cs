using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Syntax.NETUtility;
using Syntax.XMLParser;
using System.Reflection;
using Syntax.XMLParserLibrary;
using Syntax.Graphics.Handlers;
using Syntax.Graphics;

namespace SyntaxXMLParserTest
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            string currentFolder = Environment.CurrentDirectory;
            List<IHandler> handlers = GraphicsHandlers.Instance.GetHandlers();
            XMLDataManager.Instance.RegisterHandlers(handlers);
            fontGrid.AutoGenerateColumns = true;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (dataFileDialog.ShowDialog() == DialogResult.OK)
            {
                dataFileBox.Text = dataFileDialog.FileName;
                XMLDataManager.Instance.LoadDataFile(dataFileDialog.FileName);
                List<OutputPath> paths = XMLDataManager.Instance.GetAll<OutputPath>();
                
                pathsBox.DataSource = paths;
                pathsBox.DisplayMember = "Path";

                List<Syntax.Graphics.Font> fonts = XMLDataManager.Instance.GetAll<Syntax.Graphics.Font>();
                fontGrid.DataSource = fonts;
            }
        }
    }
}
