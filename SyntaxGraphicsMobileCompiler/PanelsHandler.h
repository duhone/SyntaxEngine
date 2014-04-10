#pragma once
#include "c:\source\syntax engine\syntaxcompilerlib\inodehandler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class PanelsHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			PanelsHandler(void);
			virtual ~PanelsHandler(void);
			virtual std::wstring Handles() {return L"panels";}
			virtual std::wstring Parent() {return L"data";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value) {}
			virtual Syntax::Compiler::INodeCompiler* StartElement();
		};
	}
}
