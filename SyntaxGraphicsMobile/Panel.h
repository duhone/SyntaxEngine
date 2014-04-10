#pragma once
#include "SyntaxGraphicsMobile.h"
#include "PanelPrototype.h"

namespace Syntax
{
	namespace Graphics
	{
		class RenderManager;
		class Texture;

		class Panel :
			public Syntax::Graphics::IPanel
		{
		public:
			Panel(RenderManager &_renderManager,PanelPrototype *_prototype);
			virtual ~Panel(void);
			virtual float Z() const {return z;}
			virtual void Z(float _z);
			virtual bool Show() const {return show;}
			virtual void Show(bool _show) {show = _show;}
			virtual float X() const {return dimensions.Left();}
			virtual void X(float _x) {dimensions.Left(_x);}
			virtual float Y() const {return dimensions.Top();}
			virtual void Y(float _y) {dimensions.Top(_y);}
			virtual float Width() const {return dimensions.Width();}
			virtual void Width(float _width) {dimensions.Width(_width);}
			virtual float Height() const {return dimensions.Height();}
			virtual void Height(float _height) {dimensions.Height(_height);}
			virtual const Syntax::Utility::Guid& BackgroundTexture() const {return backgroundTexture;}
			virtual void BackgroundTexture(const Syntax::Utility::Guid& _backgroundTexture);
			virtual const Syntax::Math::Color32& BackgroundColor() const {return backgroundColor;}
			virtual void BackgroundColor(const Syntax::Math::Color32& _backgroundColor) {backgroundColor = backgroundColor;}
			virtual bool UseBackgroundImage() const {return useBackgroundImage;}
			virtual void UseBackgroundImage(bool _useBackgroundImage) {useBackgroundImage = _useBackgroundImage;}
			virtual bool AnchorLeft() const {return anchorLeft;}
			virtual void AnchorLeft(bool _anchorLeft) {anchorLeft = _anchorLeft;}
			virtual bool AnchorRight() const {return anchorRight;}
			virtual void AnchorRight(bool _anchorRight) {anchorRight = _anchorRight;}
			virtual bool AnchorTop() const {return anchorTop;}
			virtual void AnchorTop(bool _anchorTop) {anchorTop = _anchorTop;}
			virtual bool AnchorBottom() const {return anchorBottom;}
			virtual void AnchorBottom(bool _anchorBottom) {anchorBottom = _anchorBottom;}
			void Render();
			void Release();
		private:
			RenderManager &renderManager;
			PanelPrototype *prototype;
			bool show;
			Syntax::Math::RectangleI dimensions;
			Syntax::Utility::Guid backgroundTexture;
			Syntax::Math::Color32 backgroundColor;
			bool useBackgroundImage;
			bool anchorLeft;
			bool anchorRight;
			bool anchorTop;
			bool anchorBottom;
			unsigned short z;
			Texture *texture;
		};
	}
}
