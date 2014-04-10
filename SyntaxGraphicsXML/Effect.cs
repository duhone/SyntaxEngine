using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Syntax.XMLParserLibrary;
using Microsoft.DirectX.Direct3D;

namespace Syntax.Graphics
{
    public class Effect : XMLData
    {
        public string FileName { get; set; }
        
        public string Compile()
        {
            string buildErrors;
            Microsoft.DirectX.Direct3D.Effect effect =
                Microsoft.DirectX.Direct3D.Effect.FromFile(
                GraphicsHandlers.Instance.D3DDevice, FileName, null, null,
                Microsoft.DirectX.Direct3D.ShaderFlags.None,
                null, out buildErrors);

            return buildErrors;
        }

        internal List<string> TextureParams
        {
            get
            {
                List<string> result = new List<string>();

                Microsoft.DirectX.Direct3D.Effect effect =
                    Microsoft.DirectX.Direct3D.Effect.FromFile(
                    GraphicsHandlers.Instance.D3DDevice, FileName, null, null,
                    Microsoft.DirectX.Direct3D.ShaderFlags.None,
                    null);
                if (effect == null) return result;
                int numParams = effect.Description.Parameters;
                for (int i = 0; i < numParams; i++)
                {
                    EffectHandle handle = effect.GetParameter(null, i);
                    ParameterDescription description = effect.GetParameterDescription(handle);
                    if (description.Semantic.ToLower().StartsWith("texture"))
                    {
                        result.Add(description.Semantic);
                    }
                }

                return result;
            }
        }

        internal List<string> MaterialParams
        {
            get
            {
                List<string> result = new List<string>();

                Microsoft.DirectX.Direct3D.Effect effect =
                    Microsoft.DirectX.Direct3D.Effect.FromFile(
                    GraphicsHandlers.Instance.D3DDevice, FileName, null, null,
                    Microsoft.DirectX.Direct3D.ShaderFlags.None,
                    null);
                if (effect == null) return result;
                int numParams = effect.Description.Parameters;
                for (int i = 0; i < numParams; i++)
                {
                    EffectHandle handle = effect.GetParameter(null, i);
                    ParameterDescription description = effect.GetParameterDescription(handle);
                    EffectHandle annotation = effect.GetAnnotation(handle, "Type");
                    if (annotation != null)
                    {
                        string annot = effect.GetValueString(annotation);
                        if (annot.ToLower().Equals("material"))
                            result.Add(annot);
                    }
                }

                return result;
            }
        }
    }
}
