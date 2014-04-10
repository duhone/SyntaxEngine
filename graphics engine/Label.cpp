#include "StdAfx.h"
#include "Label.h"
#include ".\graphicsengine.h"
#include "IGraphicsEngine.h"
#include "LabelPrototype.h"
#include "Effect.h"

using namespace graphicsengine;
using namespace graphicsengine::resources;
using namespace graphicsengine::renderables;
using namespace graphicsengine::implementation;
using namespace graphicsengine::manager;
using namespace graphicsengine::renderers;
using namespace std;



Label::Label(LabelPrototype *labelPrototype):
Renderable()
{
	prototype = labelPrototype;
	labelPrototype->AddRef();
	this->color = 0;
	this->text = labelPrototype->GetText();
	this->anchor = labelPrototype->GetAnchor();
	font = (Font*)((GraphicsEngine*)IGraphicsEngine::getInstance())->GetResourceManager()->GetFont(labelPrototype->GetFontName());
	((Font*)font)->AddRef();
	effect = ((GraphicsEngine*)IGraphicsEngine::getInstance())->GetResourceManager()->GetEffect(L"null");
	newcolor = this->color;
	newtext = text;
	xlocation = 0;
	ylocation = 0;
	newfont = font;
	newanchor = anchor;
}

Label::~Label(void)
{
	renderManager->RemoveRenderable(this);
	((Font*)font)->SubRef();
	prototype->SubRef();
}

void Label::SetFont(Font* font)
{
	newfont = font;
}

Font* Label::GetFont()
{
	return font;
}

void Label::SetText(const std::wstring& text)
{
	this->newtext = text;
}

void Label::SetLocation(const float& x,const float& y)
{
	
	xlocation = x;
	ylocation = y;
}

void Label::SetColor(const float& r,const float& g,const float& b,const float& a)
{
	
	newcolor = (int)(a*255) << 24;
	newcolor += (int)(r*255) << 16;
	newcolor += (int)(g*255) << 8;
	newcolor += (int)(b*255);
	
}

void Label::CopyNewValues()
{
	
	text = newtext;
	anchor = newanchor;
	BuildBoundsRect();
	
	color = newcolor;
	SwitchFont();
}

void Label::BuildBoundsRect()
{
	int height = ((GraphicsEngine*)IGraphicsEngine::getInstance())->GetScreenHeight();
	float aspectRatio = ((GraphicsEngine*)IGraphicsEngine::getInstance())->GetAspectRatio();
	float xl,yl;
	if(anchor & ANCHOR_LEFT)
		xl = aspectRatio*-0.5f + xlocation;
	else if(anchor & ANCHOR_RIGHT)
		xl = aspectRatio*0.5f + xlocation;
	else
		xl = xlocation;
	if(anchor & ANCHOR_TOP)
		yl = -0.5f + ylocation;
	else if(anchor & ANCHOR_BOTTOM)
		yl = 0.5f + ylocation;
	else
		yl = ylocation;

	xl = (xl + aspectRatio*0.5f)*height;
	yl = (yl + 0.5f)*height;

	bounds.left = (long)xl;
	bounds.right = bounds.left + 1;
	bounds.top = (long)yl;
	bounds.bottom = bounds.top + 1;
}

void Label::SwitchFont()
{
	if(newfont == font) return;
	if(this->font != NULL)
	{
		((Font*)(font))->SubRef();
	}
	renderManager->RemoveRenderable(this);

	font = newfont;
	((Font*)(font))->AddRef();
	renderManager->AddRenderable(this);
}
void graphicsengine::renderables::Label::AssignToRenderManager(void)
{
	renderManager->AddRenderable(this);
}

RECT* graphicsengine::renderables::Label::GetBounds(void)
{
	return &bounds;
}

void Label::SetAnchor(int anchor)
{
	this->newanchor = anchor;
}

IRenderer::RendererType Label::GetRenderer()
{
	return IRenderer::LABEL;
}

Effect* Label::GetEffect(void)
{
	return effect;
}


const Resource* const Label::GetResource(void) const
{
	return font;
}


void Label::Render()
{
	font->GetD3dFont()->DrawText(NULL,text.c_str(),-1,&bounds,DT_LEFT | DT_NOCLIP,color);
}