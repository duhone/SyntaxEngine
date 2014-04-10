#include "StdAfx.h"
#include "AssetPathHandler.h"
#include "CompilerImpl.h"

using namespace Syntax;
using namespace Syntax::Compiler;
using namespace boost;

AssetPathHandler::AssetPathHandler(void)
{
}

AssetPathHandler::~AssetPathHandler(void)
{
}

void AssetPathHandler::HandleAttribute(const std::wstring &name,const std::wstring& value)
{
	if(to_lower_copy(name) == L"path")
		CompilerImpl::Instance().AddAssetPath(value);
}