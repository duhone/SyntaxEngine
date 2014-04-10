using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Syntax.XMLParserLibrary;

namespace Syntax.Graphics
{
    public class Label : XMLData
    {
        public string Font { get; set; }
        public string Text { get; set; }
        public bool AnchorLeft { get; set; }
        public bool AnchorRight { get; set; }
        public bool AnchorTop { get; set; }
        public bool AnchorBottom { get; set; }
    }
}
