#pragma once
#include "inodecompiler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class SpriteCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:
			SpriteCompiler(void);
			virtual ~SpriteCompiler(void);
			virtual void CompileData(Syntax::Utility::BinaryWriter &writer) {};
		};
	}
}
