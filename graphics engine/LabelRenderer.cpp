#include "StdAfx.h"
#include "LabelRenderer.h"
#include "Font.h"
#include "Label.h"
#include "IGraphicsEngine.h"
#include "GraphicsEngine.h"

using namespace graphicsengine;
using namespace graphicsengine::implementation;
using namespace graphicsengine::renderables;
using namespace graphicsengine::resources;
using namespace graphicsengine::renderers;
using namespace stdext;

LabelRenderer::LabelRenderer(void) : IRenderer(IRenderer::LABEL)
{
}

LabelRenderer::~LabelRenderer(void)
{
}
	
void LabelRenderer::AddRenderable(graphicsengine::renderables::Renderable* renderable,
				graphicsengine::renderables::ObjectExecutionPlan* plan,graphicsengine::resources::Effect* effect)
{
	Label* text = dynamic_cast<Label*>(renderable);
	renderList.AddRenderable((Font*)text->GetFont(),text,plan,effect);
}

void LabelRenderer::RemoveRenderable(graphicsengine::renderables::Renderable* renderable)
{
	Label* text = dynamic_cast<Label*>(renderable);
	renderList.RemoveRenderable((Font*)text->GetFont(),text);
}

void LabelRenderer::Render()
{
	renderList.Render();
}

bool LabelRenderer::Empty()
{
	return renderList.Empty();
}


void LabelRenderer::CopyNewValues()
{	
	renderList.CopyNewValues();
}	