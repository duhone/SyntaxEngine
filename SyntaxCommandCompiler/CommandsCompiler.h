#pragma once
#include "inodecompiler.h"

namespace Syntax
{
	namespace CommandCompiler
	{
		class CommandsCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:
			CommandsCompiler(void) {};
			virtual ~CommandsCompiler(void) {};
			virtual std::wstring IndexName() {return L"commands";}
		};
	}
}
