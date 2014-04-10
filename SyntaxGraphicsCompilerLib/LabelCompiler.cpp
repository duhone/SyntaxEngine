#include "StdAfx.h"
#include "LabelCompiler.h"

using namespace Syntax::GraphicsCompiler;

LabelCompiler::LabelCompiler(void)
{
	anchor = 0;
}

LabelCompiler::~LabelCompiler(void)
{
}

void LabelCompiler::CompileData(Syntax::Utility::BinaryWriter &writer)
{
	writer << font << anchor << text;
}