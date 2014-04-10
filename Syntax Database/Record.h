#pragma once
#include "syntax database.h"
#include "boost/shared_ptr.hpp"
#include <memory>
#include <hash_map>

namespace Syntax
{
	namespace Database
	{	
		class SyntaxDatabase;

		class Record :
			public Syntax::Database::IRecord
		{
		public:
			Record(Syntax::Utility::Guid &id, long long length, Syntax::Utility::BinaryReader &reader,SyntaxDatabase *_database);
			virtual ~Record(void);
			virtual const Syntax::Utility::Guid& ID() const {return id;};
			virtual unsigned long ChildCount() const {return static_cast<unsigned long>(vchildren.size());};
			virtual const std::vector<const IRecord*>& GetChildren() const { return vchildren;}
			virtual const IRecord* const GetRecord(const Syntax::Utility::Guid& key) const;
			virtual std::auto_ptr<IRecordData> GetData() const;
		private:
			Syntax::Utility::Guid id;
			long long length;
			long long dataPosition;
			Syntax::Utility::BinaryReader &reader;
			std::vector<const IRecord*> vchildren;
			SyntaxDatabase *database;
		};
	}
}
