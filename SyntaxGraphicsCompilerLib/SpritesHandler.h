#pragma once
#include "inodehandler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class SpritesHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			SpritesHandler(void);
			virtual ~SpritesHandler(void);
			virtual std::wstring Handles() {return L"sprites";}
			virtual std::wstring Parent() {return L"data";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value) {}
			virtual Syntax::Compiler::INodeCompiler* StartElement();
		};
	}
}
