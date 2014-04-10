#include "StdAfx.h"
#include "SpritePrototype.h"
#include "FrameSetPrototype.h"

using namespace Syntax;
using namespace Syntax::Database;
using namespace graphicsengine;
using namespace graphicsengine::resources;
using namespace std;

SpritePrototype::SpritePrototype(IDirect3DDevice9* d3d_device,const Syntax::Database::IRecord *record) :
Resource(d3d_device,record)
{
}

SpritePrototype::~SpritePrototype(void)
{
	if(RefCount() > 0) FreeResource();
}

void SpritePrototype::BuildResource()
{
	const vector<const IRecord*> &records = record->GetChildren();

	for(unsigned int i = 0;i< records.size();i++)
	{
		const IRecord* record = records[i];
		auto_ptr<IRecordData> data = record->GetData();

		const wstring &name = record->Name();
		wstring material;
		long framewidth;
		float fps;
		(*data) >> material >> framewidth >> fps;

		FrameSetPrototype *frameset = new FrameSetPrototype(name,material,framewidth,fps);
		framesets.push_back(frameset);
	}
}

void SpritePrototype::FreeResource()
{
	for(unsigned int i = 0;i < framesets.size();i++)
	{
		delete framesets[i];
	}
	framesets.clear();
}

void SpritePrototype::Release()
{
	this->SubRef();
}