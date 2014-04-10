#include "StdAfx.h"
#include "Record.h"
#include "RecordData.h"
#include "FunctionObjects.h"
#include "SyntaxDatabase.h"

using namespace std;
using namespace boost;
using namespace Syntax;
using namespace Syntax::Utility;
using namespace Syntax::Database;

Record::Record(Syntax::Utility::Guid &id, long long length, Syntax::Utility::BinaryReader &reader,
			   SyntaxDatabase *_database) : reader(reader), database(_database)
{
	this->id = id;
	this->length = length;

	long childrenSize;
	reader >> childrenSize;
	long long childrenStartPosition;
	reader >> childrenStartPosition;

	dataPosition = reader.Position();

	reader.Position(childrenStartPosition);
	vchildren.reserve(childrenSize);
	for(int i =0;i < childrenSize;i++)
	{
		long long startPosition = reader.Position();
		Guid childId;
		reader >> childId;
		long long childLength;
		reader >> childLength;
		
		IRecord *childRecord = new Record(childId,childLength,reader,_database);
		vchildren.push_back(childRecord);
		reader.Position(startPosition+childLength);
		database->AddRecord(childRecord);
	}
}

Record::~Record(void)
{

}

const IRecord* const Record::GetRecord(const Guid& key) const
{
	return database->GetRecord(key);	
}

auto_ptr<IRecordData> Record::GetData() const
{
	reader.Position(dataPosition);
	reader.CompressingMode(false,0);
	return auto_ptr<IRecordData>(new RecordData(&reader));
}