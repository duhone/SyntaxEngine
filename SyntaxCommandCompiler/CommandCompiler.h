#pragma once
#include "inodecompiler.h"

namespace Syntax
{
	namespace CommandCompiler
	{
		class CommandCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:
			CommandCompiler(void) {};
			virtual ~CommandCompiler(void) {};
			virtual std::wstring IndexName() {return name;}
			void Name(const std::wstring &name) {this->name = name;}
		private:
			std::wstring name;
		};
	}
}