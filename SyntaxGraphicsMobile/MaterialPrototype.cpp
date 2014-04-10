#include "StdAfx.h"
#include "MaterialPrototype.h"

using namespace Syntax;
using namespace Syntax::Database;
using namespace Syntax::Graphics;
using namespace Syntax::Math;
using namespace Syntax::Utility;
using namespace std;

MaterialPrototype::MaterialPrototype(const IRecord *record) :
Resource(record)
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
		Guid texture;
		(*data) >> texture;
		textures.push_back(texture);
	}
	(*data) >> numProperties;
	for(int i = 0;i < numProperties;i++)
	{
		std::wstring propName;
		Vector4F vector;
		(*data) >> propName >> vector;
		properties.push_back(pair<wstring,Vector4F>(propName,vector));
	}
	//material = new graphicsengine::renderables::Material(this);
}

void MaterialPrototype::FreeResource()
{
	effect.clear();
	textures.clear();
	properties.clear();
	record = NULL;
	//delete material;
}
