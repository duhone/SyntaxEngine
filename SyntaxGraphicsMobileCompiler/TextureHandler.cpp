#include "StdAfx.h"
#include "TextureHandler.h"
#include "TextureCompiler.h"

using namespace boost;
using namespace Syntax::Compiler;
using namespace Syntax::GraphicsCompiler;

TextureHandler::TextureHandler(void)
{
}

TextureHandler::~TextureHandler(void)
{
}

void TextureHandler::HandleAttribute(const std::wstring &name,const std::wstring& value)
{
	if(name == L"name")
		compiler->Name(value);
	if(name == L"id")
		compiler->Index(value);
	else if(name == L"filename")
		compiler->FileName(value);
}

INodeCompiler* TextureHandler::StartElement()
{
	compiler = new TextureCompiler();
	return compiler;
}

