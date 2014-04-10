#pragma once
#include "inodecompiler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class TextureCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:
			TextureCompiler(void);
			virtual ~TextureCompiler(void);
			virtual std::wstring IndexName() {return name;}
			virtual void CompileData(Syntax::Utility::BinaryWriter &writer);
			void Name(std::wstring name) {this->name = name;}
			void FileName(std::wstring fileName) {this->fileName = fileName;}
			void Type(std::wstring type) {this->type = type;}
			void Compression(std::wstring compression) {this->compression = compression;}
		private:
			void SetUpFileNames();
			void CheckFile();
			void BuildTemp();
			void BuildFinal();
			bool needsToUpdate;
			bool dds;
			std::wstring name;
			std::wstring type;
			std::wstring compression;
			std::wstring fileName;
			std::wstring tempFileName;
			std::wstring finalFileName;
			stdext::hash_map<std::wstring,std::wstring> optionsLookup;

		};
	}
}
