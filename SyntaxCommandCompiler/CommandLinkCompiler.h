#pragma once
#include "c:\source\syntax engine\syntaxcompilerlib\inodecompiler.h"

namespace Syntax
{
	namespace CommandCompiler
	{
		class CommandLinkCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:

			CommandLinkCompiler(void) {}
			virtual ~CommandLinkCompiler(void) {}
			virtual std::wstring IndexName() {return name;}
			void Name(const std::wstring &name) {this->name = name;}
		private:
			std::wstring name;
		};
	}
}
