#pragma once
#include "inodehandler.h"

namespace Syntax
{
	namespace Compiler
	{
		class CompilerSettingsHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			CompilerSettingsHandler(void);
			virtual ~CompilerSettingsHandler(void);
			virtual std::wstring Handles() {return L"compiler-settings";}
			virtual std::wstring Parent() {return L"data";}
			virtual Syntax::Compiler::INodeCompiler* StartElement() {return NULL;}
		};
	}
}
