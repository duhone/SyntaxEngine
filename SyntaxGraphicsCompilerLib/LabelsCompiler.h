#pragma once
#include "inodecompiler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class LabelsCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:
			LabelsCompiler(void);
			virtual ~LabelsCompiler(void);
			virtual std::wstring IndexName() {return L"labels";}
		};
	}
}
