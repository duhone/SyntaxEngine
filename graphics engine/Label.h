#pragma once
#include"Renderable.h"
#include "ILabel.h"

namespace graphicsengine
{
	namespace resources
	{
		class LabelPrototype;
		class Effect;
		class Font;
	}

	namespace renderables
	{
		class Label :
			public ILabel , public graphicsengine::renderables::Renderable
		{
		private:
			graphicsengine::resources::Font* newfont;
			graphicsengine::resources::Font* font;
			D3DCOLOR newcolor;
			D3DCOLOR color;
			std::wstring newtext;
			std::wstring text;
			RECT bounds;
			float xlocation;
			float ylocation;
			int anchor;
			int newanchor;
			graphicsengine::resources::LabelPrototype* prototype;
			void SwitchFont();
			void BuildBoundsRect();
			graphicsengine::resources::Effect* effect;
		public:
			Label(graphicsengine::resources::LabelPrototype *labelPrototype);
		public:
			virtual ~Label(void);
			virtual void SetFont(graphicsengine::resources::Font* font);
			virtual graphicsengine::resources::Font* GetFont();
			virtual void SetText(const std::wstring& text);
			virtual void SetLocation(const float& x,const float& y);
			virtual void SetColor(const float& r,const float& g,const float& b,const float& a);
			virtual void CopyNewValues();
			D3DCOLOR GetColor() {return color;}
			std::wstring GetText() {return text;}
			virtual void SetAnchor(int anchor);
			virtual graphicsengine::renderers::IRenderer::RendererType GetRenderer();
			
			virtual const graphicsengine::resources::Resource* const GetResource(void) const;
			virtual void BuildExecutionPlan(graphicsengine::resources::Effect* effect) {};
		public:
			virtual void AssignToRenderManager(void);
		public:
			RECT* GetBounds(void);
		public:

			virtual graphicsengine::resources::Effect* GetEffect(void);
			virtual void Render();
		};
	}
}
