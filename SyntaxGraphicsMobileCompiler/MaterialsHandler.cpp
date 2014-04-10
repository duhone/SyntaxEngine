#include "StdAfx.h"
#include "MaterialsHandler.h"
#include "MaterialsCompiler.h"

using namespace Syntax::Compiler;
using namespace Syntax::GraphicsCompiler;

MaterialsHandler::MaterialsHandler(void)
{
}

MaterialsHandler::~MaterialsHandler(void)
{
}

INodeCompiler* MaterialsHandler::StartElement()
{
	return new MaterialsCompiler();
}