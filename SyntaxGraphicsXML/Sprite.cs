using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Syntax.XMLParserLibrary;
using System.Collections;

namespace Syntax.Graphics
{
    public class Sprite : XMLData
    {
        public IEnumerable<FrameSet> FrameSets
        {
            get
            {
                return frameSets.Values;
            }
        }

        public FrameSet this[string name]
        {
            get
            {
                return frameSets[name];
            }
            set
            {
                frameSets[name] = value;
            }
        }

        public void AddFrameSet(FrameSet set)
        {
            frameSets.Add(set.Name, set);
        }

        private Dictionary<string, FrameSet> frameSets = new Dictionary<string, FrameSet>();
    }
}
