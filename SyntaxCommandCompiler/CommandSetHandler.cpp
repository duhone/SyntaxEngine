#include "StdAfx.h"
#include "CommandSetHandler.h"
#include "CommandSetCompiler.h"

using namespace Syntax::Compiler;
using namespace Syntax::CommandCompiler;

CommandSetHandler::CommandSetHandler(void)
{
}

CommandSetHandler::~CommandSetHandler(void)
{
}

void CommandSetHandler::HandleAttribute(const std::wstring &name,const std::wstring& value)
{
	if(name == L"name")
		compiler->Name(value);
}

Syntax::Compiler::INodeCompiler* CommandSetHandler::StartElement()
{
	compiler =  new CommandSetCompiler();
	return compiler;
}