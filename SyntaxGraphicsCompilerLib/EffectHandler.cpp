#include "StdAfx.h"
#include "EffectHandler.h"
#include "EffectCompiler.h"

using namespace Syntax::Compiler;
using namespace Syntax::GraphicsCompiler;

EffectHandler::EffectHandler(void)
{
}

EffectHandler::~EffectHandler(void)
{
}

void EffectHandler::HandleAttribute(const std::wstring &name,const std::wstring& value)
{
	if(name == L"name")
		compiler->Name(value);
	else if(name == L"filename")
		compiler->FileName(value);
}

Syntax::Compiler::INodeCompiler* EffectHandler::StartElement()
{
	compiler = new EffectCompiler();
	return compiler;
}
