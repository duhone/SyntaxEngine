using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Syntax.XMLParserLibrary
{
    public interface IHandlers
    {
        List<IHandler> GetHandlers();
    }
}
