#pragma once

#include "IRenderer.h"
#include "FontRenderer.h"

namespace graphicsengine
{
	namespace resources
	{
		class Font;
	}
	namespace renderables
	{
		class Label;
	}
	namespace renderers
	{
		class LabelRenderer : public IRenderer
		{
		private:	
			RendererList<FontRenderer,graphicsengine::resources::Font,graphicsengine::renderables::Label> renderList;
		public:
			LabelRenderer(void);
		public:
			virtual ~LabelRenderer(void);
			virtual void AddRenderable(graphicsengine::renderables::Renderable* renderable,
				graphicsengine::renderables::ObjectExecutionPlan* plan,graphicsengine::resources::Effect* effect);
			virtual void RemoveRenderable(graphicsengine::renderables::Renderable* renderable);
			virtual void Render();
			virtual bool Empty();
			virtual void CopyNewValues();
		};
	}
}
