#pragma once
#include "inodecompiler.h"

namespace Syntax
{
	namespace Compiler
	{
		class DataCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:
			DataCompiler(void);
			virtual ~DataCompiler(void);
		};
	}
}
