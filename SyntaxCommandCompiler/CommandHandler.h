#pragma once
#include "inodehandler.h"

namespace Syntax
{
	namespace CommandCompiler
	{
		class CommandCompiler;

		class CommandHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			CommandHandler(void);
			virtual ~CommandHandler(void);
			virtual std::wstring Handles() {return L"command";}
			virtual std::wstring Parent() {return L"commands";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value);
			virtual Syntax::Compiler::INodeCompiler* StartElement();
			virtual void StartProcessing();
			virtual void PreCompile();
		private:
			CommandCompiler* compiler;
			std::vector<CommandCompiler*> compilers;
		};
	}
}
