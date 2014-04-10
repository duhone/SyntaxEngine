#pragma once
#include "inodecompiler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class FontsCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:
			FontsCompiler(void);
			virtual ~FontsCompiler(void);
			virtual std::wstring IndexName() {return L"fonts";}
		};
	}
}
