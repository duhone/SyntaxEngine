#pragma once
#include "c:\source\syntax engine\syntaxcompilerlib\inodecompiler.h"

namespace Syntax
{
	namespace CommandCompiler
	{
		class CommandSetsCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:
			CommandSetsCompiler(void) {};
			virtual ~CommandSetsCompiler(void) {};
			virtual std::wstring IndexName() {return L"commandsets";}
		};
	}
}