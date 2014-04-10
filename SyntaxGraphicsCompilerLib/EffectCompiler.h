#pragma once
#include "inodecompiler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class EffectCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:
			EffectCompiler(void);
			virtual ~EffectCompiler(void);
			virtual std::wstring IndexName() {return name;}
			virtual void CompileData(Syntax::Utility::BinaryWriter &writer);
			void Name(std::wstring name) {this->name = name;}
			void FileName(std::wstring fileName) {this->fileName = fileName;}
		private:
			void SetUpFileNames();
			void CheckFile();
			void BuildFXO();
			void BuildFXF();
			bool needsToUpdate;
			std::wstring name;
			std::wstring fileName;
			std::wstring tempFileName;
			std::wstring finalFileName;
		};
	}
}
