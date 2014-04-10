#include "StdAfx.h"
#include "LabelsHandler.h"
#include "Labelscompiler.h"

using namespace Syntax::Compiler;
using namespace Syntax::GraphicsCompiler;

LabelsHandler::LabelsHandler(void)
{
}

LabelsHandler::~LabelsHandler(void)
{
}

INodeCompiler* LabelsHandler::StartElement()
{
	return new LabelsCompiler();
}
