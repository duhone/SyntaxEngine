#include "StdAfx.h"
#include "SpriteHandler.h"
#include "SpriteCompiler.h"

using namespace Syntax::Compiler;
using namespace Syntax::GraphicsCompiler;

SpriteHandler::SpriteHandler(void)
{
}

SpriteHandler::~SpriteHandler(void)
{
}

void SpriteHandler::HandleAttribute(const std::wstring &name,const std::wstring& value)
{
	if(name == L"name")
		compiler->Name(value);
}

Syntax::Compiler::INodeCompiler* SpriteHandler::StartElement()
{
	compiler = new SpriteCompiler();
	return compiler;
}