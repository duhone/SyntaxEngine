#include "StdAfx.h"
#include "PanelHandler.h"
#include "PanelCompiler.h"

using namespace Syntax::Compiler;
using namespace Syntax::GraphicsCompiler;
using boost::lexical_cast;
using boost::bad_lexical_cast;
using namespace Syntax::Utility;
using namespace std;
using namespace Syntax::Math;
using namespace boost;

PanelHandler::PanelHandler(void)
{
}

PanelHandler::~PanelHandler(void)
{
}

void PanelHandler::HandleAttribute(const std::wstring &name,const std::wstring& value)
{
	if(name == L"name")
		compiler->Name(value);
	if(name == L"id")
		compiler->Index(value);
	else if(name == L"anchor_left")
		compiler->AnchorLeft(to_lower_copy(value) == L"true");
	else if(name == L"anchor_right")
		compiler->AnchorRight(to_lower_copy(value) == L"true");
	else if(name == L"anchor_top")
		compiler->AnchorTop(to_lower_copy(value) == L"true");
	else if(name == L"anchor_bottom")
		compiler->AnchorBottom(to_lower_copy(value) == L"true");
	else if(name == L"use_bg_texture")
		compiler->UseBackgroundImage(to_lower_copy(value) == L"true");
	else if(name == L"dimensions")
	{
		int x,y,z,w;
		wstringstream stream(value);
		stream >> x >> y >> z >> w;
		compiler->Dimensions(RectangleI(x,y,z,w));
	}
	else if(name == L"bg_color")
	{
		int x,y,z,w;
		wstringstream stream(value);
		stream >> x >> y >> z >> w;
		compiler->BackgroundColor(Color32(x,y,z,w));
	}
	else if(name == L"bg_texture_id")
		compiler->BackgroundTexture(value);
	else if(name == L"z")
		compiler->Z(lexical_cast<unsigned short>(value));
}

Syntax::Compiler::INodeCompiler* PanelHandler::StartElement()
{
	compiler = new PanelCompiler();
	return compiler;
}