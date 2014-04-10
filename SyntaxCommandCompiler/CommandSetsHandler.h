#pragma once
#include "c:\source\syntax engine\syntaxcompilerlib\inodehandler.h"

namespace Syntax
{
	namespace CommandCompiler
	{
		class CommandSetsHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			CommandSetsHandler(void);
			virtual ~CommandSetsHandler(void);
			virtual std::wstring Handles() {return L"commandsets";}
			virtual std::wstring Parent() {return L"data";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value) {}
			virtual Syntax::Compiler::INodeCompiler* StartElement();
		};
	}
}
