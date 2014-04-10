#include "StdAfx.h"
#include "CommandsHandler.h"
#include "CommandsCompiler.h"

using namespace Syntax::Compiler;
using namespace Syntax::CommandCompiler;

CommandsHandler::CommandsHandler(void)
{
}

CommandsHandler::~CommandsHandler(void)
{
}

INodeCompiler* CommandsHandler::StartElement()
{
	return new CommandsCompiler();
}