// SyntaxGraphicsCompilerLib.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "SyntaxGraphicsCompilerLib.h"
#include "FontsHandler.h"
#include "FontHandler.h"
#include "LabelsHandler.h"
#include "LabelHandler.h"
#include "EffectsHandler.h"
#include "EffectHandler.h"
#include "TexturesHandler.h"
#include "TextureHandler.h"
#include "MaterialsHandler.h"
#include "MaterialHandler.h"
#include "SpritesHandler.h"
#include "SpriteHandler.h"
#include "FrameSetHandler.h"

using namespace std;
using namespace Syntax;
using namespace Syntax::Compiler;
using namespace Syntax::GraphicsCompiler;

#ifdef _MANAGED
#pragma managed(push, off)
#endif

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

#ifdef _MANAGED
#pragma managed(pop)
#endif

vector<INodeHandler*> GetHandlers(void)
{
	vector<INodeHandler*> handlers;
	handlers.push_back(new FontsHandler());
	handlers.push_back(new FontHandler());
	handlers.push_back(new LabelsHandler());
	handlers.push_back(new LabelHandler());
	handlers.push_back(new EffectsHandler());
	handlers.push_back(new EffectHandler());
	handlers.push_back(new TexturesHandler());
	handlers.push_back(new TextureHandler());
	handlers.push_back(new MaterialsHandler());
	handlers.push_back(new MaterialHandler());
	handlers.push_back(new SpritesHandler());
	handlers.push_back(new SpriteHandler());
	handlers.push_back(new FrameSetHandler());
	return handlers;
}

void SetCompiler(Syntax::Compiler::ICompiler *compiler)
{
	Globals::Instance().Compiler(compiler);
}