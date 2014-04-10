using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Syntax.XMLParserLibrary;
using System.Xml.Linq;

namespace Syntax.Graphics.Handlers
{
    internal class FontHandler : Handler<Font>
    {
        public override XElement Document
        {
            set { fonts = value.Element("fonts"); }
        }

        public override string XMLItemTag
        {
            get { return "font"; }
        }

        public override XElement CollectionElement
        {
            get { return fonts; }
        }

        public override XMLData BuildData(XElement element)
        {
            Font font = new Font();
            font.Name = element.Attribute("name").Value;
            font.Height = Int32.Parse(element.Attribute("height").Value);
            font.Width = Int32.Parse(element.Attribute("width").Value);
            font.Weight = Int32.Parse(element.Attribute("weight").Value);
            font.Italic = Boolean.Parse(element.Attribute("italic").Value);
            font.Charset = element.Attribute("charset").Value;
            font.FaceName = element.Attribute("facename").Value;
            return font;
        }

        public override void UpdateElement(XElement element, XMLData data)
        {
            Font font = data as Font;
            element.SetAttributeValue("name", font.Name);
            element.SetAttributeValue("height", font.Height);
            element.SetAttributeValue("width", font.Width);
            element.SetAttributeValue("weight", font.Weight);
            element.SetAttributeValue("italic", font.Italic);
            element.SetAttributeValue("charset", font.Charset);
            element.SetAttributeValue("facename", font.FaceName);
        }

        private XElement fonts;
    }
}
