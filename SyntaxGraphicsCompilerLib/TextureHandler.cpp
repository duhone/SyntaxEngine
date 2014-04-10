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
	else if(name == L"filename")
		compiler->FileName(value);
	else if(name == L"type")
		compiler->Type(to_lower_copy(value));
	else if(name == L"compression")
		compiler->Compression(to_lower_copy(value));
}

INodeCompiler* TextureHandler::StartElement()
{
	compiler = new TextureCompiler();
	return compiler;
}

