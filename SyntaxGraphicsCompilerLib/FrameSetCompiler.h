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
			virtual std::wstring IndexName() {return name;}
			void Name(const std::wstring &name) {this->name = name;}
			void Material(const std::wstring &material) {this->material = material;}
			void FrameWidth(unsigned long frameWidth) {this->frameWidth = frameWidth;}
			void Fps(float fps) {this->fps = fps;}
			virtual void CompileData(Syntax::Utility::BinaryWriter &writer);

		private:
			std::wstring name;
			std::wstring material;
			unsigned long frameWidth;
			float fps;
		};
	}
}
