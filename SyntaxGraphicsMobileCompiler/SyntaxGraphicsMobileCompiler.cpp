// SyntaxGraphicsMobileCompiler.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "SyntaxGraphicsMobileCompiler.h"
#include "TexturesHandler.h"
#include "TextureHandler.h"
#include "MaterialsHandler.h"
#include "MaterialHandler.h"
#include "SpritesHandler.h"
#include "SpriteHandler.h"
#include "FrameSetHandler.h"
#include "PanelsHandler.h"
#include "PanelHandler.h"

using namespace std;
using namespace Syntax;
using namespace Syntax::Compiler;
using namespace Syntax::GraphicsCompiler;

vector<INodeHandler*> GetHandlers(void)
{
	vector<INodeHandler*> handlers;	
	handlers.push_back(new TexturesHandler());
	handlers.push_back(new TextureHandler());
	handlers.push_back(new MaterialsHandler());
	handlers.push_back(new MaterialHandler());
	handlers.push_back(new SpritesHandler());
	handlers.push_back(new SpriteHandler());
	handlers.push_back(new FrameSetHandler());
	handlers.push_back(new PanelsHandler());
	handlers.push_back(new PanelHandler());
	return handlers;
}

void SetCompiler(Syntax::Compiler::ICompiler *compiler)
{
	Globals::Instance().Compiler(compiler);
}