#pragma once
#include "inodecompiler.h"

namespace Syntax
{
	namespace Compiler
	{
		class TopCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:
			TopCompiler(void);
			virtual ~TopCompiler(void);
			void Compile(Syntax::Utility::BinaryWriter &writer) { realTop->Compile(writer);}
			INodeCompiler *realTop;
		};
	}
}
