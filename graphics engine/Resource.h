#pragma once
#include<string>
#include "Syntax Database.h"

namespace graphicsengine
{
	namespace resources
	{
		class Resource 
		{
		private:
			int refCount;
			unsigned long id;
			static unsigned long nextId;
		public:
			Resource(IDirect3DDevice9* d3d_device,const Syntax::Database::IRecord *record);
			virtual void BuildResource() = 0;
			virtual void FreeResource() = 0;
		public:
			virtual ~Resource(void);
		
		public:
			void AddRef(void);
			void SubRef(void);
			long GetId() const { return id;}
			const std::wstring& Name() const { return record->Name();}
		protected:
			IDirect3DDevice9* d3d_device;
			const Syntax::Database::IRecord *record;
			int RefCount() { return refCount; }
		
		};
	}
}
