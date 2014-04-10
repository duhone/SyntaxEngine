#pragma once
#include "inodecompiler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class LabelCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:
			LabelCompiler(void);
			virtual ~LabelCompiler(void);
			virtual std::wstring IndexName() {return name;}
			virtual void CompileData(Syntax::Utility::BinaryWriter &writer);
			void Name(std::wstring name) {this->name = name;}
			void Font(std::wstring font) {this->font = font;}
			void Text(std::wstring text) {this->text = text;}
			void Anchor(long anchor) {this->anchor = this->anchor|anchor;}
		private:
			std::wstring name;
			std::wstring font;
			std::wstring text;
			long anchor;
		};
	}
}
