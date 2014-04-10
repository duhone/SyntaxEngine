#pragma once
#include "inodehandler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class FontCompiler;

		class FontHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			FontHandler(void);
			virtual ~FontHandler(void);
			virtual std::wstring Handles() {return L"font";}
			virtual std::wstring Parent() {return L"fonts";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value);
			virtual Syntax::Compiler::INodeCompiler* StartElement();
		private:
			FontCompiler* compiler;
			stdext::hash_map<std::wstring,long> charSetLookup;
		};
	}
}
