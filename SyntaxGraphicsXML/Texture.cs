using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Syntax.XMLParserLibrary;

namespace Syntax.Graphics
{
    public enum TextureCompressionType
    {
        Uncompressed,
        DXT1,
        DXT5,
        DXT5N,
        ATI1,
        ATI2
    };

    public class Texture : XMLData
    {
        public string FileName { get; set; }
        public TextureCompressionType CompressionType { get; set; }
    }
}
