#pragma once
#include "..\syntaxcompilerlib\inodehandler.h"

namespace Syntax
{
	namespace Compiler
	{
		class OutputPathHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			OutputPathHandler(void);
			virtual ~OutputPathHandler(void);
			virtual std::wstring Handles() {return L"output-path";}
			virtual std::wstring Parent() {return L"compiler-settings";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value);
			virtual Syntax::Compiler::INodeCompiler* StartElement() {return NULL;}
		};
	}
}
