#pragma once
#include "c:\source\syntax engine\syntaxcompilerlib\inodehandler.h"

namespace Syntax
{
	namespace CommandCompiler
	{
		class CommandSetCompiler;

		class CommandSetHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			CommandSetHandler(void);
			virtual ~CommandSetHandler(void);
			virtual std::wstring Handles() {return L"commandset";}
			virtual std::wstring Parent() {return L"commandsets";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value);
			virtual Syntax::Compiler::INodeCompiler* StartElement();
		private:
			CommandSetCompiler* compiler;
		};
	}
}
