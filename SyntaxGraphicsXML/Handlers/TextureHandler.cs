using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Syntax.XMLParserLibrary;
using System.Xml.Linq;

namespace Syntax.Graphics.Handlers
{
    internal class TextureHandler : Handler<Texture>
    {
        public override XElement Document
        {
            set { textures = value.Element("textures"); }
        }

        public override string XMLItemTag
        {
            get { return "texture"; }
        }

        public override XElement CollectionElement
        {
            get { return textures; }
        }

        public override XMLData BuildData(XElement element)
        {
            Texture temp = new Texture();
            temp.Name = element.Attribute("name").Value;
            temp.FileName = element.Attribute("filename").Value;
            string compression = element.Attribute("compression").Value;
            if (compression == "RGBA")
            {
                temp.CompressionType = TextureCompressionType.Uncompressed;
            }
            else if (compression == "DXT1")
            {
                temp.CompressionType = TextureCompressionType.DXT1;
            }
            else if (compression == "DXT5")
            {
                temp.CompressionType = TextureCompressionType.DXT5;
            }
            else if (compression == "DXT5N")
            {
                temp.CompressionType = TextureCompressionType.DXT5N;
            }
            else if (compression == "ATI1")
            {
                temp.CompressionType = TextureCompressionType.ATI1;
            }
            else if (compression == "ATI2")
            {
                temp.CompressionType = TextureCompressionType.ATI2;
            }
            return temp;
        }

        public override void UpdateElement(XElement element, XMLData data)
        {
            Texture texture = data as Texture;
            string type = CompresionToString(texture.CompressionType);
            element.SetAttributeValue("name", texture.Name);
            element.SetAttributeValue("filename", texture.FileName);
            element.SetAttributeValue("compression", type);
        }

        private string CompresionToString(TextureCompressionType compressionType)
        {
            string type;
            switch (compressionType)
            {
                case TextureCompressionType.Uncompressed:
                    type = "RGBA";
                    break;
                case TextureCompressionType.DXT1:
                    type = "DXT1";
                    break;
                case TextureCompressionType.DXT5:
                    type = "DXT5";
                    break;
                case TextureCompressionType.DXT5N:
                    type = "DXT5N";
                    break;
                case TextureCompressionType.ATI1:
                    type = "ATI1";
                    break;
                case TextureCompressionType.ATI2:
                    type = "ATI2";
                    break;
                default:
                    type = "RGBA";
                    break;
            }
            return type;
        }
        private XElement textures;
    }
}
