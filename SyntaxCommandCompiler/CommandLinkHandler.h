#pragma once
#include "c:\source\syntax engine\syntaxcompilerlib\inodehandler.h"

namespace Syntax
{
	namespace CommandCompiler
	{
		class CommandLinkCompiler;

		class CommandLinkHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			CommandLinkHandler(void);
			virtual ~CommandLinkHandler(void);
			virtual std::wstring Handles() {return L"commandlink";}
			virtual std::wstring Parent() {return L"commandset";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value);
			virtual Syntax::Compiler::INodeCompiler* StartElement();
		private:
			CommandLinkCompiler* compiler;
		};
	}
}
