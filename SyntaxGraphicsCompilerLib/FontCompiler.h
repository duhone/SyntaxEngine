#pragma once
#include "inodecompiler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class FontCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:
			FontCompiler(void);
			virtual ~FontCompiler(void);
			virtual std::wstring IndexName() {return name;}
			void Name(const std::wstring &name) {this->name = name;}
			void Height(long height) {this->height = height;}
			void Width(long width) {this->width = width;}
			void Weight(const long weight) {this->weight = weight;}
			void Italic(bool italic) {this->italic = italic;}
			void CharSet(long charSet) {this->charSet = charSet;}
			void FaceName(const std::wstring &facename) {this->facename = facename;}
			virtual void CompileData(Syntax::Utility::BinaryWriter &writer);

		private:
			std::wstring name;
			long height;
			long width;
			long weight;
			long charSet;
			bool italic;
			std::wstring facename;
		};
	}
}
