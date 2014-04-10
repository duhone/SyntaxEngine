#include "StdAfx.h"
#include "DeviceFactory.h"
#include "SurfaceCPP.h"

#ifdef _WINDOWS
#include "WindowsMobile\DeviceWindowsMobile.h"
#endif

using namespace boost;
using namespace Syntax;
using namespace Syntax::Graphics;
using namespace Syntax::Utility;

DeviceFactory::DeviceFactory(void)
{
}

DeviceFactory::~DeviceFactory(void)
{
}

shared_ptr<IDevice> DeviceFactory::CreateDevice()
{
#ifdef _WINDOWS
	return shared_ptr<IDevice>(new DeviceWindowsMobile());
#endif
}

shared_ptr<ISurface> DeviceFactory::CreateSurface(unsigned long _width,unsigned long _height)
{
	return shared_ptr<ISurface>(new SurfaceCPP(_width,_height));
}