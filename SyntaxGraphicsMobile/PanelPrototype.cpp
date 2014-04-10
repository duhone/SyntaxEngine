#include "StdAfx.h"
#include "PanelPrototype.h"

using namespace Syntax;
using namespace Syntax::Graphics;
using namespace Syntax::Database;
using namespace std;

PanelPrototype::PanelPrototype(const Syntax::Database::IRecord *record) :
Resource(record)
{
}

PanelPrototype::~PanelPrototype(void)
{
	if(RefCount() > 0) FreeResource();
}
			
void PanelPrototype::BuildResource()
{
	auto_ptr<IRecordData> data = record->GetData();
	(*data) >> dimensions >> backgroundTexture >> backgroundColor;
	(*data) >> useBackgroundImage >> anchorLeft >> anchorRight;
	(*data) >> anchorTop >> anchorBottom >> z;
}

void PanelPrototype::FreeResource()
{

}