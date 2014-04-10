using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Syntax.XMLParserLibrary;
using System.Xml.Linq;

namespace Syntax.Graphics.Handlers
{
    internal class LabelHandler : Handler<Label>
    {
        public override XElement Document
        {
            set { labels = value.Element("labels"); }
        }

        public override string XMLItemTag
        {
            get { return "label"; }
        }

        public override XElement CollectionElement
        {
            get { return labels; }
        }

        public override XMLData BuildData(XElement element)
        {
            Label result = new Label();
            result.Name = element.Attribute("name").Value;
            result.Font = element.Attribute("font").Value;
            result.Text = element.Attribute("text").Value;
            result.AnchorLeft = Boolean.Parse(element.Attribute("anchorleft").Value);
            result.AnchorRight = Boolean.Parse(element.Attribute("anchorright").Value);
            result.AnchorTop = Boolean.Parse(element.Attribute("anchortop").Value);
            result.AnchorBottom = Boolean.Parse(element.Attribute("anchorbottom").Value);
            return result;
        }

        public override void UpdateElement(XElement element, XMLData data)
        {
            Label label = data as Label;
            element.SetAttributeValue("name", label.Name);
            element.SetAttributeValue("font", label.Font);
            element.SetAttributeValue("text", label.Text);
            element.SetAttributeValue("anchorleft", label.AnchorLeft);
            element.SetAttributeValue("anchorright", label.AnchorRight);
            element.SetAttributeValue("anchortop", label.AnchorTop);
            element.SetAttributeValue("anchorbottom", label.AnchorBottom);
        }

        private XElement labels;
    }
}
