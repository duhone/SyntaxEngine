#pragma once
#include "inodecompiler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class SpritesCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:
			SpritesCompiler(void);
			virtual ~SpritesCompiler(void);
			virtual std::wstring IndexName() {return L"sprites";}
		};
	}
}
