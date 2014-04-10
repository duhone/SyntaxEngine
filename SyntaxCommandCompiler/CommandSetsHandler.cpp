#include "StdAfx.h"
#include "CommandSetsHandler.h"
#include "CommandSetsCompiler.h"

using namespace Syntax::Compiler;
using namespace Syntax::CommandCompiler;

CommandSetsHandler::CommandSetsHandler(void)
{
}

CommandSetsHandler::~CommandSetsHandler(void)
{
}

INodeCompiler* CommandSetsHandler::StartElement()
{
	return new CommandSetsCompiler();
}