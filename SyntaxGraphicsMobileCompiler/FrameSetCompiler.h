#pragma once
#include "inodecompiler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class FrameSetCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:
			FrameSetCompiler(void);
			virtual ~FrameSetCompiler(void);
			void Material(const Syntax::Utility::Guid &material) {this->material = material;}
			void Fps(float fps) {this->fps = fps;}
			virtual void CompileData(Syntax::Utility::BinaryWriter &writer);

		private:
			Syntax::Utility::Guid material;
			float fps;
		};
	}
}
