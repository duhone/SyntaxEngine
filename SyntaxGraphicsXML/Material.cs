using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Syntax.NETUtility;
using Syntax.XMLParserLibrary;
using Syntax.Graphics.Handlers;

namespace Syntax.Graphics
{
    public class Material : XMLData
    {
        public string Effect
        {
            get
            {
                return effect;
            }
            set
            {
                effect = value;
                Dictionary<string, string> oldTextureParams = textureParams;
                textureParams = new Dictionary<string, string>();
                Syntax.Graphics.Effect newEffect = GraphicsHandlers.Instance.EffectHandler.Get<Effect>(effect);
                foreach (var param in newEffect.TextureParams)
                {
                    if (oldTextureParams.ContainsKey(param))
                    {
                        textureParams.Add(param, oldTextureParams[param]);
                    }
                    else
                    {
                        textureParams.Add(param, "");
                    }
                }
                Dictionary<string, Vector> oldMaterialParams = materialParams;
                materialParams = new Dictionary<string, Vector>(); 
                foreach (var param in newEffect.MaterialParams)
                {
                    if (oldMaterialParams.ContainsKey(param))
                    {
                        materialParams.Add(param, oldMaterialParams[param]);
                    }
                    else
                    {
                        materialParams.Add(param, new Vector());
                    }
                }
                
            }
        }
        public IEnumerable<KeyValuePair<string,string>> Textures
        {
            get
            {
                return textureParams;
            }
        }

        public void SetTexture(string texture, string value)
        {
            if (!textureParams.ContainsKey(texture))
                return;
            textureParams[texture] = value;
        }

        public IEnumerable<KeyValuePair<string, Vector>> Materials
        {
            get
            {
                return materialParams;
            }
        }

        public void SetMaterial(string material, Vector value)
        {
            if (!materialParams.ContainsKey(material))
                return;
            materialParams[material] = value;
        }

        private string effect;
        private Dictionary<string, string> textureParams = new Dictionary<string, string>();
        private Dictionary<string, Vector> materialParams = new Dictionary<string, Vector>();
    }
}
