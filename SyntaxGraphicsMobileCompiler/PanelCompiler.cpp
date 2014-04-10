#include "StdAfx.h"
#include "PanelCompiler.h"

using namespace Syntax::GraphicsCompiler;

PanelCompiler::PanelCompiler(void)
{
}

PanelCompiler::~PanelCompiler(void)
{
}

void PanelCompiler::CompileData(Syntax::Utility::BinaryWriter &writer)
{
	writer << dimensions << backgroundTexture << backgroundColor;
	writer << useBackgroundImage << anchorLeft << anchorRight;
	writer << anchorTop << anchorBottom << z;
}
