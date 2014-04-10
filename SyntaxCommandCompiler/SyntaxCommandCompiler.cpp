// SyntaxCommandCompiler.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "SyntaxCommandCompiler.h"
#include "CommandsHandler.h"
#include "CommandHandler.h"
#include "CommandSetsHandler.h"
#include "CommandSetHandler.h"
#include "CommandLinkHandler.h"

using namespace std;
using namespace Syntax;
using namespace Syntax::Compiler;
using namespace Syntax::CommandCompiler;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

vector<INodeHandler*> GetHandlers(void)
{
	vector<INodeHandler*> handlers;
	handlers.push_back(new CommandsHandler());
	handlers.push_back(new CommandHandler());
	handlers.push_back(new CommandSetsHandler());
	handlers.push_back(new CommandSetHandler());
	handlers.push_back(new CommandLinkHandler());
	return handlers;
}