#include "StdAfx.h"
#include "FrameSetHandler.h"
#include "FrameSetCompiler.h"

using namespace Syntax::Compiler;
using namespace Syntax::GraphicsCompiler;
using boost::lexical_cast;
using boost::bad_lexical_cast;
using namespace Syntax::Utility;

FrameSetHandler::FrameSetHandler(void)
{
}

FrameSetHandler::~FrameSetHandler(void)
{
}

void FrameSetHandler::HandleAttribute(const std::wstring &name,const std::wstring& value)
{
	if(name == L"name")
		compiler->Name(value);
	if(name == L"id")
		compiler->Index(value);
	else if(name == L"material_id")
		compiler->Material(Guid(value));
	else if(name == L"fps")
		compiler->Fps(lexical_cast<float>(value));
}

Syntax::Compiler::INodeCompiler* FrameSetHandler::StartElement()
{
	compiler = new FrameSetCompiler();
	return compiler;
}