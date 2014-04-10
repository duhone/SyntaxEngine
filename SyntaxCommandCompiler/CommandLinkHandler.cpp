#include "StdAfx.h"
#include "CommandLinkHandler.h"
#include "CommandLinkCompiler.h"

using namespace Syntax::Compiler;
using namespace Syntax::CommandCompiler;

CommandLinkHandler::CommandLinkHandler(void)
{
}

CommandLinkHandler::~CommandLinkHandler(void)
{
}

void CommandLinkHandler::HandleAttribute(const std::wstring &name,const std::wstring& value)
{
	if(name == L"name")
		compiler->Name(value);
}

Syntax::Compiler::INodeCompiler* CommandLinkHandler::StartElement()
{
	compiler =  new CommandLinkCompiler();
	return compiler;
}