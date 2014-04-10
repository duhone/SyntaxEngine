using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Syntax.XMLParserLibrary;

namespace Syntax.Graphics
{
    public class FrameSet
    {
        public string Name { get; set; }
        public string Material { get; set; }
        public int FrameWidth { get; set; }
        public float FPS { get; set; }
    }
}
