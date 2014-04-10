#include "StdAfx.h"
#include "FrameSetPrototype.h"

using namespace graphicsengine;
using namespace graphicsengine::resources;

FrameSetPrototype::FrameSetPrototype(const std::wstring& name,const std::wstring& material,int framewidth,float fps)
{
	this->name = name;
	this->material = material;
	this->framewidth = framewidth;
	this->fps = fps;
}

FrameSetPrototype::~FrameSetPrototype(void)
{
}
