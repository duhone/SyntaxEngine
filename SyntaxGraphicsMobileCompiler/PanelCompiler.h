#pragma once
#include "c:\source\syntax engine\syntaxcompilerlib\inodecompiler.h"
#include "Rectangle.h"
#include "Color.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class PanelCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:
			PanelCompiler(void);
			virtual ~PanelCompiler(void);
			void AnchorLeft(bool _anchor) {anchorLeft = _anchor;}
			void AnchorRight(bool _anchor) {anchorRight = _anchor;}
			void AnchorTop(bool _anchor) {anchorTop = _anchor;}
			void AnchorBottom(bool _anchor) {anchorBottom = _anchor;}
			void Dimensions(const Syntax::Math::RectangleI _dimensions) {dimensions = _dimensions;}
			void BackgroundTexture(Syntax::Utility::Guid _backTexture) {backgroundTexture = _backTexture;}
			void BackgroundColor(Syntax::Math::Color32 _backColor) {backgroundColor = _backColor;}
			void UseBackgroundImage(bool _useBackImage) {useBackgroundImage = _useBackImage;}
			virtual void CompileData(Syntax::Utility::BinaryWriter &writer);
			void Z(unsigned short _z) {z = _z;}
		private:
			bool anchorLeft;
			bool anchorRight;
			bool anchorTop;
			bool anchorBottom;
			Syntax::Math::RectangleI dimensions;
			Syntax::Utility::Guid backgroundTexture;
			Syntax::Math::Color32 backgroundColor;
			bool useBackgroundImage;
			unsigned short z;
		};
	}
}
