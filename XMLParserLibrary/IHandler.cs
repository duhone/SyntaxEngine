using System;
using System.Collections.Generic;
using System.Text;
using System.Xml.Linq;

namespace Syntax.XMLParserLibrary
{
    public interface IHandler
    {
        Type Handles { get; }
        XElement Document { set; }
        List<T> GetAll<T>() where T : class;
        T Get<T>(string name) where T : class;
        void Save<T>(T item) where T : class;
        void Delete<T>(T item) where T : class;
    }
}
