#include "StdAfx.h"
#include ".\font.h"
#include ".\graphicsengine.h"
#include "IGraphicsEngine.h"

using namespace Syntax;
using namespace Syntax::Database;
using namespace graphicsengine;
using namespace graphicsengine::resources;
using namespace graphicsengine::implementation;
using namespace std;

graphicsengine::resources::Font::Font(IDirect3DDevice9* d3d_device,const Syntax::Database::IRecord *record) :
Resource(d3d_device,record)
{
	font = NULL;
}

graphicsengine::resources::Font::~Font(void)
{
	if(RefCount() > 0) FreeResource();
}


void graphicsengine::resources::Font::BuildResource()
{
	auto_ptr<IRecordData> data = record->GetData();
	
	float sizeFactor = ((GraphicsEngine*)IGraphicsEngine::getInstance())->GetScreenHeight()/768.0f;
	long height,width,weight,charset;
	bool italic;
	wstring facename;
	(*data) >> height >> width >> weight >> italic >> charset >> facename;
	D3DXCreateFont(d3d_device,height,width,weight,4,italic,charset,OUT_DEFAULT_PRECIS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_DONTCARE,facename.c_str(),&font);

}

void graphicsengine::resources::Font::FreeResource()
{
	font->Release();
	font = NULL;
	record = NULL;
}

void graphicsengine::resources::Font::Release()
{
	this->SubRef();
}

