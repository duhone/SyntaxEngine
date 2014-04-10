#pragma once
#include "..\syntaxcompilerlib\inodecompiler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class PanelsCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:
			PanelsCompiler(void);
			virtual ~PanelsCompiler(void);
			virtual std::wstring IndexName() {return L"panels";}
		};
	}
}
