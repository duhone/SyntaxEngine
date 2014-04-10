#pragma once
#include "c:\source\syntax engine\syntaxcompilerlib\inodehandler.h"

namespace Syntax
{
	namespace Compiler
	{
		class AssetPathHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			AssetPathHandler(void);
			virtual ~AssetPathHandler(void);
			virtual std::wstring Handles() {return L"asset-path";}
			virtual std::wstring Parent() {return L"compiler-settings";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value);
			virtual Syntax::Compiler::INodeCompiler* StartElement() {return NULL;}
		};
	}
}

