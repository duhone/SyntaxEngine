#include "StdAfx.h"
#include "SyntaxDatabase.h"
#include "Exceptions.h"
#include "Record.h"
#include "BinaryReader.h"

using namespace Syntax;
using namespace Syntax::Utility;
using namespace Syntax::Database;
using namespace boost;

SyntaxDatabase::SyntaxDatabase(std::wstring fileName)
{
	reader = new BinaryReader(fileName);
	Guid id;
	long long length;
	(*reader) >> id;
	(*reader) >> length;

	root = new Record(id,length,*reader,this);
	records[id] = root;
}

SyntaxDatabase::~SyntaxDatabase(void)
{
	delete root;
	delete reader;
	records.clear();
}

void SyntaxDatabase::Release()
{
	delete this;
}

const IRecord* const SyntaxDatabase::GetRoot() const
{
	return root;
}

const IRecord* const SyntaxDatabase::GetRecord(const Guid& key) const
{
	unordered_map<Syntax::Utility::Guid,IRecord*>::const_iterator iterator = records.find(key);
	if(iterator == records.end())
		return NULL;
	return iterator->second;
}

void SyntaxDatabase::MergeFile(std::wstring fileName)
{
	throw NotImplementedException();
}
