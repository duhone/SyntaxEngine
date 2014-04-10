#include "StdAfx.h"
#include "Texture.h"
#include "ISurface.h"
#include "DeviceFactory.h"

using namespace std;
using namespace boost;
using namespace Syntax;
using namespace Syntax::Graphics;
using namespace Syntax::Database;

Texture::Texture(const Syntax::Database::IRecord *record):
Resource(record)
{
}

Texture::~Texture(void)
{
	if(RefCount() > 0) FreeResource();
}

void Texture::BuildResource(void)
{
	auto_ptr<IRecordData> recordData = record->GetData();
	long compressedSize;
	(*recordData) >> compressedSize >> width >> height;

	recordData->CompressingMode(true,compressedSize);
	surface = DeviceFactory::Instance().CreateSurface(width,height);
	(*recordData) >> surface.get();	
}

void Texture::FreeResource(void)
{
	surface.reset();
}
