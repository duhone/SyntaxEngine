#include "StdAfx.h"
#include "PanelsHandler.h"
#include "PanelsCompiler.h"

using namespace Syntax::Compiler;
using namespace Syntax::GraphicsCompiler;

PanelsHandler::PanelsHandler(void)
{
}

PanelsHandler::~PanelsHandler(void)
{
}

INodeCompiler* PanelsHandler::StartElement()
{
	return new PanelsCompiler();
}