#pragma once
#include<string>
#include "Syntax Database.h"

namespace Syntax
{
	namespace Graphics
	{
		class Resource
		{
		public:
			Resource(const Syntax::Database::IRecord *record);
			virtual ~Resource(void);
			virtual void BuildResource() = 0;
			virtual void FreeResource() = 0;
			virtual void Release(void);
			void AddRef(void);
			void SubRef(void);
			const Syntax::Utility::Guid& ID() const { return record->ID();}
		protected:
			const Syntax::Database::IRecord *record;
			int RefCount() { return refCount; }
		private:
			int refCount;
		};
	}
}