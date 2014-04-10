using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Syntax.NETUtility;
using Syntax.XMLParserLibrary;
using Syntax.Graphics.Handlers;
using Microsoft.DirectX.Direct3D;
using System.Windows.Forms;

namespace Syntax.Graphics
{
    public class GraphicsHandlers : Singleton<GraphicsHandlers>, IHandlers
    {
        protected GraphicsHandlers() { }

        public void InitDevice(Control renderWindow)
        {        
            PresentParameters presentParams = new PresentParameters();
            presentParams.Windowed=true;
            presentParams.SwapEffect = SwapEffect.Discard;

            device = new Device(0, DeviceType.Hardware, renderWindow,
                CreateFlags.SoftwareVertexProcessing, presentParams);
        }

        public Device D3DDevice
        {
            get
            {
                return device;
            }
        }

        #region IHandlers Members

        public List<IHandler> GetHandlers()
        {
            List<IHandler> result = new List<IHandler>();
            result.Add(new FontHandler());
            result.Add(new LabelHandler());
            result.Add(effectHandler);
            result.Add(new TextureHandler());
            result.Add(new MaterialHandler());
            return result;
        }

        #endregion

        internal EffectHandler EffectHandler
        {
            get { return effectHandler; }
        }
        private EffectHandler effectHandler = new EffectHandler();
        private Device device;
    }
}
