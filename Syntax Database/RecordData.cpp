#include "StdAfx.h"
#include "RecordData.h"
#include "BinaryReader.h"
#include "ISerializable.h"

using namespace Syntax;
using namespace Syntax::Utility;
using namespace Syntax::Database;

RecordData::RecordData(Syntax::Utility::BinaryReader *reader)
{
	this->reader = reader;
	reader->Lock();
}

RecordData::~RecordData(void)
{
	reader->UnLock();
}

bool RecordData::CompressingMode() const
{
	return reader->CompressingMode();
}

void RecordData::CompressingMode(bool compressing,unsigned int compresedSize)
{
	reader->CompressingMode(compressing,compresedSize);
}

void RecordData::Read(char* data,int size)
{
	reader->Read(data,size);
}
