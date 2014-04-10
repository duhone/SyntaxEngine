#include "StdAfx.h"
#include "GraphicsImpl.h"
#include "DeviceFactory.h"
#include "IDevice.h"
#include "ResourceManager.h"
#include "RenderManager.h"

using namespace std;
using namespace Syntax;
using namespace Syntax::Graphics;
using namespace Syntax::Utility;
using namespace boost;

GraphicsImpl::GraphicsImpl(void)
{
	//resourceManager.reset(new ResourceManager());
}

GraphicsImpl::~GraphicsImpl(void)
{
}

#ifdef _WINDOWS
void GraphicsImpl::Initialize(const SettingsWindows& _settings)
{
	wstring errors;
	hwnd = _settings.hwnd;
	device = DeviceFactory::Instance().CreateDevice();
	device->Initialize(&errors);
}
#endif

void GraphicsImpl::Commit()
{
	if(device)
	{
		device->BeginUpdate();
		if(useBackgroundColor)
		{
			device->Clear(backgroundColor.Red(),backgroundColor.Green(),
			backgroundColor.Blue());
		}
		RenderManager::Instance().Render();
		device->EndUpdate();
		device->Flip();
	}
}

void GraphicsImpl::SetDatabase(Syntax::Database::ISyntaxDatabase *_database)
{
	ResourceManager::Instance().SetDatabase(_database);
}
	
shared_ptr<IPanel> GraphicsImpl::CreatePanel(const Guid &_id)
{
	return RenderManager::Instance().CreatePanel(_id);
}