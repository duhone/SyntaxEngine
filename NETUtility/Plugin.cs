using System;
using System.Collections.Generic;
using System.Text;
using System.Reflection;

namespace Syntax.NETUtility
{
    internal class Plugin : IPlugin
    {
        public Plugin(Assembly assembly)
        {
            this.assembly = assembly;
        }

        public void GetImplementors<T>(List<T> implementors)
        {
            Type[] types = assembly.GetTypes();
            foreach (Type type in types)
            {
                if (typeof(T).IsAssignableFrom(type))
                {
                    ConstructorInfo cinfo = type.GetConstructor(Type.EmptyTypes);
                    if (cinfo != null)
                    {
                        object implementor = cinfo.Invoke(null);
                        implementors.Add((T)implementor);
                    }
                    
                }
            }
        }

        #region IPlugin Members

        public List<T> GetImplementors<T>()
        {
            List<T> result = new List<T>();
            GetImplementors<T>(result);
            return result;
        }

        #endregion

        private Assembly assembly;
    }
}
