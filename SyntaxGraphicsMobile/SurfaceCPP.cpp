#include "StdAfx.h"
#include "SurfaceCPP.h"
#include "BinaryReader.h"

using namespace Syntax;
using namespace Syntax::Graphics;
using namespace Syntax::Utility;

SurfaceCPP::SurfaceCPP(unsigned long _width,unsigned long _height) :width(_width), height(_height)
{
	surface.Init(width,height);
}

SurfaceCPP::~SurfaceCPP(void)
{
	
}

void SurfaceCPP::DeSerialize(BinaryReader &_reader)
{
	unsigned short* data = surface.Get();
	_reader.Read(reinterpret_cast<char*>(data),width*height*2);
}