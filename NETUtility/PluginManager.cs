using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Reflection;

namespace Syntax.NETUtility
{
    // dont use. doesnt work too well.
    class PluginManager : Singleton<PluginManager>
    {
        public List<T> GetImplementors<T>()
        {
            List<T> result = new List<T>();

            foreach (KeyValuePair<string, Plugin> item in plugins)
            {
                item.Value.GetImplementors<T>(result);
            }
            return result;
        }

        public void RegisterPlugins(string path)
        {
            string[] files = Directory.GetFiles(path, "*.dll");
            foreach (string file in files)
            {
                Assembly assembly = null;
                try
                {
                    assembly = Assembly.LoadFrom(file);
                }
                catch(Exception)
                {}
                plugins.Add(assembly.FullName, new Plugin(assembly));
            }
        }

        protected PluginManager()
        {

        }
        private Dictionary<string,Plugin> plugins = new Dictionary<string,Plugin>();
    }
}
