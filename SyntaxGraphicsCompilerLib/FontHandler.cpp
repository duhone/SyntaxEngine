#include "StdAfx.h"
#include "FontHandler.h"
#include "FontCompiler.h"

using namespace boost;
using namespace Syntax::Compiler;
using namespace Syntax::GraphicsCompiler;
using boost::lexical_cast;
using boost::bad_lexical_cast;

FontHandler::FontHandler(void)
{
	charSetLookup[L"ANSI"] = ANSI_CHARSET;
	charSetLookup[L"SYMBOL"] = SYMBOL_CHARSET;
	charSetLookup[L"SHIFTJIS"] = SHIFTJIS_CHARSET;
	charSetLookup[L"HANGEUL"] = HANGEUL_CHARSET;
	charSetLookup[L"HANGUL"] = HANGUL_CHARSET;
	charSetLookup[L"GB2312"] = GB2312_CHARSET;
	charSetLookup[L"CHINESEBIG5"] = CHINESEBIG5_CHARSET;
	charSetLookup[L"JOHAB"] = JOHAB_CHARSET;
	charSetLookup[L"HEBREW"] = HEBREW_CHARSET;
	charSetLookup[L"ARABIC"] = ARABIC_CHARSET;
	charSetLookup[L"GREEK"] = GREEK_CHARSET;
	charSetLookup[L"TURKISH"] = TURKISH_CHARSET;
	charSetLookup[L"VIETNAMESE"] = VIETNAMESE_CHARSET;
	charSetLookup[L"THAI"] = THAI_CHARSET;
	charSetLookup[L"EASTEUROPE"] = EASTEUROPE_CHARSET;
	charSetLookup[L"RUSSIAN"] = RUSSIAN_CHARSET;
	charSetLookup[L"MAC"] = MAC_CHARSET;
	charSetLookup[L"BALTIC"] = BALTIC_CHARSET;
}

FontHandler::~FontHandler(void)
{
}

void FontHandler::HandleAttribute(const std::wstring &name,const std::wstring& value)
{
	if(name == L"name")
		compiler->Name(value);
	else if(name == L"height")
		compiler->Height(lexical_cast<long>(value));
	else if(name == L"width")
		compiler->Width(lexical_cast<long>(value));
	else if(name == L"weight")
		compiler->Weight(lexical_cast<long>(value));
	else if(name == L"italic")
		compiler->Italic(value == L"true");
	else if(name == L"charset")
		compiler->CharSet(charSetLookup[to_upper_copy(value)]);
	else if(name == L"facename")
		compiler->FaceName(value);
}

Syntax::Compiler::INodeCompiler* FontHandler::StartElement()
{
	compiler = new FontCompiler();
	return compiler;
}