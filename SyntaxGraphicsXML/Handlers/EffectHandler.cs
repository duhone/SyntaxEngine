using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Syntax.XMLParserLibrary;
using System.Xml.Linq;

namespace Syntax.Graphics.Handlers
{
    internal class EffectHandler : Handler<Effect>
    {
        public override XElement Document
        {
            set { effects = value.Element("effects"); }
        }

        public override string XMLItemTag
        {
            get { return "effect"; }
        }

        public override XElement CollectionElement
        {
            get { return effects; }
        }

        public override XMLData BuildData(XElement element)
        {
            Effect result = new Effect();
            result.Name = element.Attribute("name").Value;
            result.FileName = element.Attribute("filename").Value;
            return result;
        }

        public override void UpdateElement(XElement element, XMLData data)
        {
            Effect effect = data as Effect;
            element.SetAttributeValue("name", effect.Name);
            element.SetAttributeValue("filename", effect.FileName);
        }

        private XElement effects;
    }
}
