#include "StdAfx.h"
#include "FontsHandler.h"
#include "FontsCompiler.h"

using namespace Syntax::Compiler;
using namespace Syntax::GraphicsCompiler;

FontsHandler::FontsHandler(void)
{
}

FontsHandler::~FontsHandler(void)
{
}

INodeCompiler* FontsHandler::StartElement()
{
	return new FontsCompiler();
}