#pragma once
#include "inodehandler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class EffectsCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:
			EffectsCompiler(void);
			virtual ~EffectsCompiler(void);
			virtual std::wstring IndexName() {return L"effects";}
		};
	}
}
