#include "StdAfx.h"
#include "LabelHandler.h"
#include "LabelCompiler.h"

using namespace Syntax::Compiler;
using namespace Syntax::GraphicsCompiler;

LabelHandler::LabelHandler(void)
{
}

LabelHandler::~LabelHandler(void)
{
}

void LabelHandler::HandleAttribute(const std::wstring &name,const std::wstring& value)
{
	if(name == L"name")
		compiler->Name(value);
	else if(name == L"font")
		compiler->Font(value);
	else if(name == L"text")
		compiler->Text(value);
	else if(name == L"anchorleft" && value == L"true")
		compiler->Anchor(0x01);
	else if(name == L"anchorright" && value == L"true")
		compiler->Anchor(0x02);
	else if(name == L"anchortop" && value == L"true")
		compiler->Anchor(0x04);
	else if(name == L"anchorbottom" && value == L"true")
		compiler->Anchor(0x08);
}

Syntax::Compiler::INodeCompiler* LabelHandler::StartElement()
{
	compiler = new LabelCompiler();
	compiler->Anchor(0);
	return compiler;
}
