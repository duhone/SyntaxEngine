// SyntaxCommand.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "SyntaxCommand.h"
#include "SyntaxCommandImpl.h"

using namespace Syntax;
using namespace Syntax::Command;

// This is an example of an exported variable
SYNTAXCOMMAND_API int nSyntaxCommand=0;

// This is an example of an exported function.
SYNTAXCOMMAND_API ISyntaxCommand* const GetSyntaxCommand(void)
{
	return SyntaxCommandImpl::Instance();
}

