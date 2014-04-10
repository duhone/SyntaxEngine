using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Syntax.XMLParserLibrary;
using System.Xml.Linq;

namespace Syntax.Graphics.Handlers
{
    class SpriteHandler : Handler<Sprite>
    {
        public override XElement Document
        {
            set { sprites = value.Element("sprites"); }
        }

        public override string XMLItemTag
        {
            get { return "sprite"; }
        }

        public override XElement CollectionElement
        {
            get { return sprites; }
        }

        public override XMLData BuildData(XElement element)
        {
            Sprite result = new Sprite();
            result.Name = element.Attribute("name").Value;
            foreach (var item in from c in element.Elements() where c.Name == "frameset" select c)
            {
                FrameSet set = new FrameSet();
                set.Name = item.Attribute("name").Value;
                set.Material = item.Attribute("material").Value;
                set.FrameWidth = Int32.Parse(item.Attribute("framewidth").Value);
                set.FPS = Int32.Parse(item.Attribute("fps").Value);
                result.AddFrameSet(set);
            }
            return result;
        }

        public override void UpdateElement(XElement element, XMLData data)
        {
            Sprite sprite = data as Sprite;
            element.SetAttributeValue("name", sprite.Name);
            element.Elements().Remove();
            foreach (var item in sprite.FrameSets)
            {
                XElement frameSet = new XElement("frameset",
                new XAttribute("name", item.Name),
                new XAttribute("material", item.Material),
                new XAttribute("framewidth", item.FrameWidth),
                new XAttribute("fps", item.FPS));
                element.Add(frameSet);
            }
        }

        private XElement sprites;
    }
}
