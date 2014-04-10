#pragma once
#include "Syntax Database.h"
#include <boost/unordered_map.hpp>
#include "Singleton.h"

namespace Syntax
{
	namespace Graphics
	{
		class Texture;
		class MaterialPrototype;
		class SpritePrototype;
		class PanelPrototype;

		class ResourceManager : public Syntax::Utility::Singleton<ResourceManager>
		{
			friend Syntax::Utility::Singleton<ResourceManager>;
		public:
			virtual void Clear(void);
			virtual void SetDatabase(Syntax::Database::ISyntaxDatabase *database);
			virtual Texture* GetTexture(const Syntax::Utility::Guid& _id);
			virtual MaterialPrototype* GetMaterial(const Syntax::Utility::Guid& _id);
			virtual SpritePrototype* GetSprite(const Syntax::Utility::Guid& _id);
			virtual PanelPrototype* GetPanel(const Syntax::Utility::Guid& _id);
		protected:
			ResourceManager(void);
			~ResourceManager(void);
		private:
			template<class T> 
			void Load(boost::unordered_map<Syntax::Utility::Guid,T*> &items,const Syntax::Utility::Guid& record,bool preload = false);
			template<class T> 
			void Clear(boost::unordered_map<Syntax::Utility::Guid,T*> &items);
			template<class T> 
			T* Get(const Syntax::Utility::Guid &name,boost::unordered_map<Syntax::Utility::Guid,T*> &items) const;

			Syntax::Database::ISyntaxDatabase *database;
			boost::unordered_map<Syntax::Utility::Guid,Texture*> textures;
			boost::unordered_map<Syntax::Utility::Guid,MaterialPrototype*> materials;
			boost::unordered_map<Syntax::Utility::Guid,SpritePrototype*> sprites;
			boost::unordered_map<Syntax::Utility::Guid,PanelPrototype*> panels;
		};

		
		template<class T> 
		void ResourceManager::Load(boost::unordered_map<Syntax::Utility::Guid,T*> &items,const Syntax::Utility::Guid& record,bool preload)
		{
			const IRecord *records = database->GetRecord(record);
			if(records)
			{
				const vector<const IRecord*>& children = records->GetChildren();
				for(unsigned int count = 0;count < children.size();count++)
				{
					const IRecord *record = children[count];
					T* item = new T(record);
					items[item->ID()] = item;
					if(preload) item->AddRef();
				}
			}
		}

		template<class T> 
		void ResourceManager::Clear(boost::unordered_map<Syntax::Utility::Guid,T*> &items)
		{
			for_each(items.begin(),items.end(),DeleteFOPair());
			items.clear();
		}

		template<class T> 
		T* ResourceManager::Get(const Syntax::Utility::Guid &id,boost::unordered_map<Syntax::Utility::Guid,T*> &items) const
		{
			 boost::unordered_map<Syntax::Utility::Guid,T*>::iterator iterator = items.find(id);
			 if(iterator == items.end()) return NULL;
			 T* result = iterator->second;
			 return result;
		}
	}
}
