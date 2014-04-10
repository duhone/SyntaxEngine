#include "StdAfx.h"
#include "CommandHandler.h"
#include "CommandCompiler.h"
#include "FunctionObjects.h"

using namespace Syntax::Compiler;
using namespace Syntax::CommandCompiler;
using namespace Syntax::Utility;

CommandHandler::CommandHandler(void)
{
}

CommandHandler::~CommandHandler(void)
{
}

void CommandHandler::HandleAttribute(const std::wstring &name,const std::wstring& value)
{
	if(name == L"name")
		compiler->Name(value);
}

Syntax::Compiler::INodeCompiler* CommandHandler::StartElement()
{
	compiler =  new CommandCompiler();
	compilers.push_back(compiler);
	return compiler;
}

void CommandHandler::StartProcessing()
{
	ForEach(compilers,DeleteFO());
	compilers.clear();
}

void CommandHandler::PreCompile()
{

}