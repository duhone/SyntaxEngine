#pragma once
#include "c:\source\syntax engine\syntaxcompilerlib\inodehandler.h"

namespace Syntax
{
	namespace Compiler
	{
		class AssetSectionHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			AssetSectionHandler(void);
			virtual ~AssetSectionHandler(void);
			virtual std::wstring Handles() {return L"asset-section";}
			virtual std::wstring Parent() {return L"compiler-settings";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value);
			virtual Syntax::Compiler::INodeCompiler* StartElement() {return NULL;}
		};
	}
}
