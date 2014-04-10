using System;
using System.Collections.Generic;
using System.Text;

namespace Syntax.NETUtility
{
    public interface IPlugin
    {
        List<T> GetImplementors<T>();
    }
}
