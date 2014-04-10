#pragma once
#include "syntax database.h"
#include "Record.h"
#include "ForwardDeclarations.h"
#include "boost/unordered_map.hpp"

namespace Syntax
{
	namespace Database
	{
		class SyntaxDatabase :
			public Syntax::Database::ISyntaxDatabase
		{
		public:
			SyntaxDatabase(std::wstring fileName);
			virtual ~SyntaxDatabase(void);
			virtual const IRecord* const GetRoot() const;
			virtual const IRecord* const GetRecord(const Syntax::Utility::Guid& key) const;
			virtual void MergeFile(std::wstring fileName);
			virtual void Release();
			void AddRecord(IRecord *_record) {records[_record->ID()] = _record;}
		private:
			Record *root;
			Syntax::Utility::BinaryReader *reader;
			boost::unordered_map<Syntax::Utility::Guid,IRecord*> records;
		};
	}
}
