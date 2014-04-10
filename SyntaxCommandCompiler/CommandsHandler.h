#pragma once
#include "inodehandler.h"

namespace Syntax
{
	namespace CommandCompiler
	{
		class CommandsHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			CommandsHandler(void);
			virtual ~CommandsHandler(void);
			virtual std::wstring Handles() {return L"commands";}
			virtual std::wstring Parent() {return L"data";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value) {}
			virtual Syntax::Compiler::INodeCompiler* StartElement();
		};
	}
}
