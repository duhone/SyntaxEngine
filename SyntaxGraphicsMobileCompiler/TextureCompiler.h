#pragma once
#include "c:\source\syntax engine\syntaxcompilerlib\inodecompiler.h"

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
			void FileName(std::wstring fileName) {this->fileName = fileName;}
		private:
			void SetUpFileNames();
			void CheckFile();
			void BuildFinal();
			bool needsToUpdate;
			std::wstring fileName;
			std::wstring finalFileName;
		};
	}
}