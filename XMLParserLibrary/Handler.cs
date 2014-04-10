using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml.Linq;

namespace Syntax.XMLParserLibrary
{
    public abstract class Handler<S> : IHandler where S : XMLData
    {
        #region abstract methods
        
        public abstract XElement Document {set;}
        public abstract string XMLItemTag { get; }
        public abstract XElement CollectionElement { get; }
        public abstract XMLData BuildData(XElement element);
        public abstract void UpdateElement(XElement element,XMLData data);

        #endregion

        #region IHandler Members

        public Type Handles
        {
            get { return typeof(S); }
        }

        public List<T> GetAll<T>() where T : class
        {
            List<T> result = new List<T>();
            foreach (XElement element in from c in CollectionElement.Elements(XMLItemTag) orderby c.Element("name") select c)
            {
                XMLData temp = BuildData(element);
                result.Add(temp as T);
            }

            return result;
        }

        public T Get<T>(string name) where T : class
        {
            var result = from c in CollectionElement.Elements(XMLItemTag) where c.Attribute("name").Value == name select c;
            foreach (var item in result)
            {
                return BuildData(item) as T;
            }
            return null;
        }

        public void Save<T>(T item) where T : class
        {
            S data = item as S;
            XMLData old = Get<S>(data.Name);
            if (old == null)
            {
                XElement newFont = BuildElement(data);
                CollectionElement.Add(newFont);
            }
            else
            {
                var elements = from c in CollectionElement.Elements() where c.Attribute("name").Value == data.Name select c;
                foreach (var element in elements)
                {
                    UpdateElement(element, data);
                    return;
                }
            }
        }

        public void Delete<T>(T item) where T : class
        {
            var elements = from c in CollectionElement.Elements() where c.Attribute("name").Value == (item as S).Name select c;
            elements.Remove();
        }

        #endregion


        public XElement BuildElement(XMLData data)
        {
            XElement newElement = new XElement(XMLItemTag,
                new XAttribute("name", data.Name));
            UpdateElement(newElement, data);
            return newElement;
        }
    }
}
