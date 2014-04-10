using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Syntax.XMLParserLibrary;
using System.Xml.Linq;
using Syntax.NETUtility;

namespace Syntax.Graphics.Handlers
{
    public class MaterialHandler : Handler<Material>
    {
        public override XElement Document
        {
            set { materials = value.Element("materials"); }
        }

        public override string XMLItemTag
        {
            get { return "material"; }
        }

        public override XElement CollectionElement
        {
            get { return materials; }
        }

        public override XMLData BuildData(XElement element)
        {
            Material result = new Material();
            List<XAttribute> textures = new List<XAttribute>();
            List<XAttribute> materials = new List<XAttribute>();

            foreach (var item in element.Attributes())
            {
                if (item.Name.ToString().ToLower().Equals("name"))
                {
                    result.Name = item.Value;
                }
                else if (item.Name.ToString().ToLower().Equals("effect"))
                {
                    result.Effect = item.Value;
                }
                else if (item.Name.ToString().ToLower().StartsWith("texture"))
                {
                    textures.Add(item);
                }
                else
                {
                    materials.Add(item);
                }
            }
            textures.ForEach(item => result.SetTexture(item.Name.ToString(), item.Value));
            materials.ForEach(item => result.SetMaterial(item.Name.ToString(), new Vector(item.Value)));

            return result;
        }

        public override void UpdateElement(XElement element, XMLData data)
        {
            Material material = data as Material;
            element.Attributes().Remove();
            element.SetAttributeValue("name", material.Name);
            element.SetAttributeValue("effect", material.Effect);
            foreach (var item in material.Textures)
            {
                element.Add(new XAttribute(item.Key, item.Value));
            }
            foreach (var item in material.Materials)
            {
                element.Add(new XAttribute(item.Key, item.Value));
            }
        }

        private XElement materials;
    }
}
