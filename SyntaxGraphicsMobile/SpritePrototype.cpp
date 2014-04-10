#include "StdAfx.h"
#include "SpritePrototype.h"

using namespace Syntax;
using namespace Syntax::Database;
using namespace Syntax::Graphics;
using namespace Syntax::Math;
using namespace Syntax::Utility;
using namespace std;

SpritePrototype::SpritePrototype(const Syntax::Database::IRecord *record):
Resource(record)
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

		const Guid &id = record->ID();
		Guid material;
		float fps;
		(*data) >> material >> fps;

		framesets.push_back(FrameSetPrototype(id,material,fps));
	}
}

void SpritePrototype::FreeResource()
{

}
