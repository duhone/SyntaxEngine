#include "StdAfx.h"
#include "LabelPrototype.h"
#include ".\graphicsengine.h"
#include "IGraphicsEngine.h"

using namespace graphicsengine;
using namespace graphicsengine::resources;
using namespace graphicsengine::implementation;
using namespace Syntax;
using namespace Syntax::Database;
using namespace std;

LabelPrototype::LabelPrototype(IDirect3DDevice9* d3d_device,
									   const Syntax::Database::IRecord *record) :
Resource(d3d_device,record)
{
}

LabelPrototype::~LabelPrototype(void)
{
	if(RefCount() > 0) FreeResource();
}

void LabelPrototype::BuildResource()
{
	auto_ptr<IRecordData> data = record->GetData();
	fontName = new wstring();
	text = new wstring();
	(*data) >> (*fontName)  >> anchor >> (*text);
}

void LabelPrototype::FreeResource()
{
	delete fontName;
	delete text;
}

void LabelPrototype::Release()
{
	this->SubRef();
}