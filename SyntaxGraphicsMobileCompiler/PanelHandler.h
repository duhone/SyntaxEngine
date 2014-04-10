#pragma once
#include "c:\source\syntax engine\syntaxcompilerlib\inodehandler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class PanelCompiler;

		class PanelHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			PanelHandler(void);
			virtual ~PanelHandler(void);
			virtual std::wstring Handles() {return L"panel";}
			virtual std::wstring Parent() {return L"panels";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value);
			virtual Syntax::Compiler::INodeCompiler* StartElement();
		private:
			PanelCompiler* compiler;
		};
	}
}
