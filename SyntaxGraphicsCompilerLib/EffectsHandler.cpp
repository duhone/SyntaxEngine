#include "StdAfx.h"
#include "EffectsHandler.h"
#include "EffectsCompiler.h"

using namespace Syntax::Compiler;
using namespace Syntax::GraphicsCompiler;

EffectsHandler::EffectsHandler(void)
{
}

EffectsHandler::~EffectsHandler(void)
{
}

INodeCompiler* EffectsHandler::StartElement()
{
	return new EffectsCompiler();
}