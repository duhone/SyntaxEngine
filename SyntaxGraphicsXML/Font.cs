using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Syntax.XMLParserLibrary;

namespace Syntax.Graphics
{
    public class Font : XMLData
    {
        public int Height { get; set; }
        public int Width { get; set; }
        public int Weight { get; set; }
        public bool Italic { get; set; }
        public string Charset { get; set; }
        public string FaceName { get; set; }
    }
}
