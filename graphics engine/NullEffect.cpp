#include "StdAfx.h"
#include "NullEffect.h"

using namespace graphicsengine;
using namespace graphicsengine::resources;
using namespace std;

NullEffect::NullEffect(IDirect3DDevice9* d3d_device) :
Effect(d3d_device,NULL)
{
	//name = new string("null");
}

NullEffect::~NullEffect(void)
{
}

void NullEffect::BuildResource(void)
{

}