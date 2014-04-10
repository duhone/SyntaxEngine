#pragma once
#include "..\syntaxcompilerlib\inodehandler.h"

namespace Syntax
{
	namespace Compiler
	{
		class SettingHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			SettingHandler(void);
			virtual ~SettingHandler(void);
			virtual std::wstring Handles() {return L"setting";}
			virtual std::wstring Parent() {return L"compiler-settings";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value);
			virtual Syntax::Compiler::INodeCompiler* StartElement() {return NULL;}
			virtual void EndElement();
		private:
			std::wstring name;
			std::wstring value;
		};
	}
}
