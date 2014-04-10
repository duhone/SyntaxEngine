#include "StdAfx.h"
#include "TexturesHandler.h"
#include "TexturesCompiler.h"

using namespace Syntax::Compiler;
using namespace Syntax::GraphicsCompiler;

TexturesHandler::TexturesHandler(void)
{
}

TexturesHandler::~TexturesHandler(void)
{
}

INodeCompiler* TexturesHandler::StartElement()
{
	return new TexturesCompiler();
}
