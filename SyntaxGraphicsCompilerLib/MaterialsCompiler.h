#pragma once
#include "inodecompiler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class MaterialsCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:
			MaterialsCompiler(void);
			virtual ~MaterialsCompiler(void);
			virtual std::wstring IndexName() {return L"materials";}
		};
	}
}
