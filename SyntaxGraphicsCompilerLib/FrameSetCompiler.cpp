#include "StdAfx.h"
#include "FrameSetCompiler.h"

using namespace Syntax::GraphicsCompiler;

FrameSetCompiler::FrameSetCompiler(void)
{
}

FrameSetCompiler::~FrameSetCompiler(void)
{
}

void FrameSetCompiler::CompileData(Syntax::Utility::BinaryWriter &writer)
{
	writer << material;
	writer << frameWidth;
	writer << fps;
}