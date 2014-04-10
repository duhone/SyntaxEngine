// Syntax Database.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "Syntax Database.h"
#include "SyntaxDatabase.h"

using namespace std;
using namespace Syntax;
using namespace Syntax::Database;

#ifdef _MANAGED
#pragma managed(push, off)
#endif

#ifdef _WINDOWS
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
#endif

#ifdef WINCE
BOOL APIENTRY DllMain( HANDLE hModule, 
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
#endif

#ifdef _MANAGED
#pragma managed(pop)
#endif


ISyntaxDatabase* SyntaxDatabaseFactory::CreateDatabase(const std::wstring& fileName)
{
	return new SyntaxDatabase(fileName);
}