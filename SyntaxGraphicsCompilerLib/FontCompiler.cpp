#include "StdAfx.h"
#include "FontCompiler.h"

using namespace Syntax::GraphicsCompiler;

FontCompiler::FontCompiler(void)
{
}

FontCompiler::~FontCompiler(void)
{
}

void FontCompiler::CompileData(Syntax::Utility::BinaryWriter &writer)
{
	writer << height << width << weight << italic << charSet << facename;
}