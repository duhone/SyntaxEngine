#pragma once
#include "c:\source\syntax engine\syntaxcompilerlib\inodecompiler.h"

namespace Syntax
{
	namespace CommandCompiler
	{
		class CommandSetCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:

			CommandSetCompiler(void) {}
			virtual ~CommandSetCompiler(void) {}
			virtual std::wstring IndexName() {return name;}
			void Name(const std::wstring &name) {this->name = name;}
		private:
			std::wstring name;
		};
	}
}
