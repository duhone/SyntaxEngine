#pragma once
#include "inodehandler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class SpriteCompiler;

		class SpriteHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			SpriteHandler(void);
			virtual ~SpriteHandler(void);
			virtual std::wstring Handles() {return L"sprite";}
			virtual std::wstring Parent() {return L"sprites";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value);
			virtual Syntax::Compiler::INodeCompiler* StartElement();
		private:
			SpriteCompiler* compiler;
		};
	}
}
