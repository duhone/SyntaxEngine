#pragma once
#include "inodehandler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class FontsHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			FontsHandler(void);
			~FontsHandler(void);
			virtual std::wstring Handles() {return L"fonts";}
			virtual std::wstring Parent() {return L"data";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value) {}
			virtual Syntax::Compiler::INodeCompiler* StartElement();
		};
	}
}
