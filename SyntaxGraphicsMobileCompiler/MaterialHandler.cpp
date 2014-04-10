#include "StdAfx.h"
#include "MaterialHandler.h"
#include "MaterialCompiler.h"

using namespace Syntax::Compiler;
using namespace Syntax::GraphicsCompiler;
using namespace Syntax::Math;
using namespace boost;
using namespace std;
using namespace Syntax::Utility;

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
	if(name == L"id")
		compiler->Index(value);
	else if(name == L"effect")
		compiler->Effect(value);
	else if(ends_with(name,L"_id"))
		compiler->AddTexture(name.substr(0,name.length()-3),Guid(value));
	else
	{
		float x,y,z,w;
		wstringstream stream(value);
		stream >> x >> y >> z >> w;
		compiler->AddProperty(name,Vector4F(x,y,z,w));
	}
}

Syntax::Compiler::INodeCompiler* MaterialHandler::StartElement()
{
	compiler = new MaterialCompiler();
	return compiler;
}
