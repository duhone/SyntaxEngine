#pragma once
#include "..\syntaxcompilerlib\inodecompiler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class TexturesCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:
			TexturesCompiler(void);
			virtual ~TexturesCompiler(void);
			virtual std::wstring IndexName() {return L"textures";}
		};
	}
}
