using System;
using System.Collections.Generic;
using System.Text;
using Syntax.NETUtility;
using Syntax.XMLParserLibrary;
using System.Reflection;
using System.IO;
using System.Xml.Linq;
using Syntax.XMLParser.Internal;

namespace Syntax.XMLParser
{
    public class XMLDataManager : Singleton<XMLDataManager>
    {
        public void LoadDataFile(string fileName)
        {
            document = XElement.Load(fileName);
            foreach(var item in handlers)
            {
                item.Value.Document = document;
            }
            this.fileName = fileName;
        }

        public void Commit()
        {
            if(fileName != null)
                document.Save(fileName);
        }

        public void RegisterHandlers(List<IHandler> handlers)
        {
            foreach (IHandler handler in handlers)
            {
                this.handlers.Add(handler.Handles, handler);
            }
        }

        public List<T> GetAll<T>() where T : class
        {
            Type type = typeof(T);
            if (!handlers.ContainsKey(type))
                throw new Exception("There was no handler for type " + type.Name);
            return handlers[type].GetAll<T>();
        }

        public T Get<T>(string name) where T : class
        {
            Type type = typeof(T);
            if (!handlers.ContainsKey(type))
                throw new Exception("There was no handler for type " + type.Name);
            return handlers[type].Get<T>(name);
        }

        public void Save<T>(T item) where T : class
        {
            Type type = typeof(T);
            if (!handlers.ContainsKey(type))
                throw new Exception("There was no handler for type " + type.Name);
            handlers[type].Save<T>(item);
        }

        public void Delete<T>(T item) where T : class
        {
            Type type = typeof(T);
            if (!handlers.ContainsKey(type))
                throw new Exception("There was no handler for type " + type.Name);
            handlers[type].Delete<T>(item);
        }

        protected XMLDataManager()
        {
            //built in handlers
            IHandler builtInHandler = new OutputPathHandler();
            this.handlers.Add(builtInHandler.Handles, builtInHandler);
        }

        private Dictionary<Type, IHandler> handlers = new Dictionary<Type, IHandler>();
        private XElement document;
        private string fileName = null;
    }
}
