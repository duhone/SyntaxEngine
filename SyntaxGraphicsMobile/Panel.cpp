#include "StdAfx.h"
#include "Panel.h"
#include "RenderManager.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "IDevice.h"
#include "GraphicsImpl.h"
#include "Rectangle.h"

using namespace Syntax;
using namespace Syntax::Graphics;
using namespace Syntax::Math;
using namespace boost;

Panel::Panel(RenderManager &_renderManager,PanelPrototype *_prototype) : renderManager(_renderManager),
	prototype(_prototype), show(true)
{
	prototype->AddRef();
	BackgroundTexture(_prototype->BackgroundTexture());
	dimensions = _prototype->Dimensions();
	backgroundColor = _prototype->BackgroundColor();
	useBackgroundImage = _prototype->UseBackgroundImage();
	anchorLeft = _prototype->AnchorLeft();
	anchorRight = _prototype->AnchorRight();
	anchorTop = _prototype->AnchorTop();
	anchorBottom = _prototype->AnchorBottom();
	z = _prototype->Z();
	if(!backgroundTexture.IsNull())
	{
		texture = ResourceManager::Instance().GetTexture(backgroundTexture);
		texture->AddRef();
	}
}

Panel::~Panel(void)
{
	renderManager.RemovePanel(this);
	if(texture)
		texture->SubRef();
	texture = NULL;
	prototype->SubRef();
}

void Panel::Release()
{
	delete this;
}

void Panel::Z(float _z)
{
	if(z == _z)
		return;
	z = _z;
	renderManager.PanelChangeZ(this);
}

void Panel::BackgroundTexture(const Syntax::Utility::Guid& _backgroundTexture)
{
	if(backgroundTexture == _backgroundTexture)
		return;
	if(texture)
	{
		texture->SubRef();
		texture = NULL;
	}
	backgroundTexture = _backgroundTexture;
	if(!_backgroundTexture.IsNull())
	{
		texture = ResourceManager::Instance().GetTexture(_backgroundTexture);
		assert(texture); //tried to set to a texture that doesn't exist
	}
	if(!texture)
		useBackgroundImage = false;
}

void Panel::Render()
{
	RectangleI destination;
	RectangleI source;
	shared_ptr<IDevice> device = GraphicsImpl::Instance().Device();
	if(anchorLeft && anchorRight)
	{
		destination.Left(0);
		destination.Width(device->Width());
	}
	else if(anchorLeft && !anchorRight)
	{
		destination.Left(0);
		destination.Width(dimensions.Width());
	}
	else if(!anchorLeft && anchorRight)
	{
		destination.Left(device->Width()-dimensions.Width());
		destination.Width(dimensions.Width());
	}
	else
	{
		destination.Left(dimensions.Left());
		destination.Width(dimensions.Width());
	}

	if(anchorTop && anchorBottom)
	{
		destination.Top(0);
		destination.Height(device->Height());
	}
	else if(anchorTop && !anchorBottom)
	{
		destination.Top(0);
		destination.Height(dimensions.Height());
	}
	else if(!anchorTop && anchorBottom)
	{
		destination.Top(device->Height()-dimensions.Height());
		destination.Height(dimensions.Height());
	}
	else
	{
		destination.Top(dimensions.Top());
		destination.Height(dimensions.Height());
	}

	if(!useBackgroundImage)
	{
		destination.Clamp(0,0,device->Width(),device->Height());
		device->Blt(backgroundColor,destination);
	}
	else
	{
		assert(texture);

		const shared_ptr<ISurface> &surface = texture->Surface();
		source.Top(0);
		source.Left(0);
		source.Width(texture->Width());
		source.Height(texture->Height());
		device->Blt(surface,destination,source);
	}
}