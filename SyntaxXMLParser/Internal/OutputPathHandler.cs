using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Syntax.XMLParserLibrary;
using System.Xml.Linq;

namespace Syntax.XMLParser.Internal
{
    internal class OutputPathHandler : IHandler
    {
        #region IHandler Members

        public Type Handles
        {
            get { return typeof(OutputPath); }
        }

        public XElement Document
        {
            set
            {
                settings = value.Element("compiler-settings");
            }
        }

        public List<T> GetAll<T>() where T : class
        {
            List<T> result = new List<T>();
            foreach (XElement element in settings.Elements("output-path"))
            {
                OutputPath temp = new OutputPath();
                temp.Path = element.Attribute("path").Value;
                result.Add(temp as T);
            }

            return result;
        }

        public T Get<T>(string name) where T : class
        {
            return null;
        }

        public void Save<T>(T item) where T : class
        {
            OutputPath path = item as OutputPath;
            var elements = from c in settings.Elements() where c.Attribute("path").Value == path.Path select c;
            foreach (var element in elements)
            {
                element.SetAttributeValue("path", path.Path);
                return;
            } 
            XElement newFont = new XElement("output-path",
                new XAttribute("path", path.Path));
            settings.Add(newFont);
        }

        public void Delete<T>(T item) where T : class
        {
            var elements = from c in settings.Elements() where c.Attribute("path").Value == (item as OutputPath).Path select c;
            elements.Remove();
        }

        #endregion

        private XElement settings;
    }
}
