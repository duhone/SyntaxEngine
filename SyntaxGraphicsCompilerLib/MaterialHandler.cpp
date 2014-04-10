#include "StdAfx.h"
#include "MaterialHandler.h"
#include "MaterialCompiler.h"

using namespace Syntax::Compiler;
using namespace Syntax::GraphicsCompiler;
using namespace boost;
using namespace std;

MaterialHandler::MaterialHandler(void)
{
}

MaterialHandler::~MaterialHandler(void)
{
}

void MaterialHandler::HandleAttribute(const std::wstring &name,const std::wstring& value)
{
	if(name == L"name")
		compiler->Name(value);
	else if(name == L"effect")
		compiler->Effect(value);
	else if(find_first(name,L"texture"))
		compiler->AddTexture(name,value);
	else
	{
		float x,y,z,w;
		wstringstream stream(value);
		stream >> x >> y >> z >> w;
		compiler->AddProperty(name,D3DXVECTOR4(x,y,z,w));
	}
}

Syntax::Compiler::INodeCompiler* MaterialHandler::StartElement()
{
	compiler = new MaterialCompiler();
	return compiler;
}
