#include "StdAfx.h"
#include "MaterialPrototype.h"
#include "Material.h"

using namespace Syntax;
using namespace Syntax::Database;
using namespace graphicsengine;
using namespace graphicsengine::resources;
using namespace graphicsengine::renderables;
using namespace std;

MaterialPrototype::MaterialPrototype(IDirect3DDevice9* d3d_device,const IRecord *record) :
Resource(d3d_device,record)
{
}

MaterialPrototype::~MaterialPrototype(void)
{
	if(RefCount() > 0) FreeResource();
}

void MaterialPrototype::BuildResource()
{
	auto_ptr<IRecordData> data = record->GetData();
	long numTextures,numProperties;
	(*data) >> effect >> numTextures;
	for(int i = 0;i < numTextures;i++)
	{
		std::wstring texture;
		(*data) >> texture;
		textures.push_back(texture);
	}
	(*data) >> numProperties;
	for(int i = 0;i < numProperties;i++)
	{
		std::wstring propName;
		float x,y,z,w;
		(*data) >> propName >> x >> y >> z >> w;
		properties.push_back(pair<wstring,D3DXVECTOR4>(propName,D3DXVECTOR4(x,y,z,w)));
	}
	material = new graphicsengine::renderables::Material(this);
}

void MaterialPrototype::FreeResource()
{
	effect.clear();
	textures.clear();
	properties.clear();
	record = NULL;
	delete material;
}

void MaterialPrototype::Release()
{
	this->SubRef();
}
