#include "StdAfx.h"
#include "FrameSetPrototype.h"

using namespace Syntax;
using namespace Syntax::Graphics;
using namespace std;

FrameSetPrototype::FrameSetPrototype(const Syntax::Utility::Guid& id,const Syntax::Utility::Guid& material,float fps)
{
	this->id = id;
	this->material = material;
	this->fps = fps;
}
FrameSetPrototype::FrameSetPrototype(const FrameSetPrototype &_other)
{
	this->id = _other.id;
	this->material = _other.material;
	this->fps = _other.fps;
}

void FrameSetPrototype::operator=(const FrameSetPrototype &_other)
{
	this->id = _other.id;
	this->material = _other.material;
	this->fps = _other.fps;
}
			
FrameSetPrototype::~FrameSetPrototype(void)
{
}
