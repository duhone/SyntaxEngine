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
			virtual std::wstring IndexName() {return name;}
			void Name(const std::wstring &name) {this->name = name;}
			virtual void CompileData(Syntax::Utility::BinaryWriter &writer) {};

		private:
			std::wstring name;
		};
	}
}
