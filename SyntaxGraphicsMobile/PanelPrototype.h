#pragma once
#include "resource.h"
#include "Rectangle.h"
#include "Color.h"

namespace Syntax
{
	namespace Graphics
	{
		class PanelPrototype :
			public Syntax::Graphics::Resource
		{
		public:
			PanelPrototype(const Syntax::Database::IRecord *record);
			virtual ~PanelPrototype(void);			
			virtual void BuildResource();
			virtual void FreeResource();
			const Syntax::Math::RectangleI& Dimensions() {return dimensions;}
			const Syntax::Utility::Guid& BackgroundTexture() {return backgroundTexture;}
			const Syntax::Math::Color32& BackgroundColor() {return backgroundColor;}
			bool UseBackgroundImage() {return useBackgroundImage;}
			bool AnchorLeft() {return anchorLeft;}
			bool AnchorRight() {return anchorRight;}
			bool AnchorTop() {return anchorTop;}
			bool AnchorBottom() {return anchorBottom;}
			unsigned short Z() {return z;}
		private:
			Syntax::Math::RectangleI dimensions;
			Syntax::Utility::Guid backgroundTexture;
			Syntax::Math::Color32 backgroundColor;
			bool useBackgroundImage;
			bool anchorLeft;
			bool anchorRight;
			bool anchorTop;
			bool anchorBottom;
			unsigned short z;
		};
	}
}
