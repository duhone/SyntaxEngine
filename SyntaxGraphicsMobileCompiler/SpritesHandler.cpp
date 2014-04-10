#include "StdAfx.h"
#include "SpritesHandler.h"
#include "SpritesCompiler.h"

using namespace Syntax::Compiler;
using namespace Syntax::GraphicsCompiler;

SpritesHandler::SpritesHandler(void)
{
}

SpritesHandler::~SpritesHandler(void)
{
}

INodeCompiler* SpritesHandler::StartElement()
{
	return new SpritesCompiler();
}
