#pragma once
#include "Syntax Database.h"

namespace graphicsengine
{
	namespace resources
	{
		class Font;
		class LabelPrototype;
		class Effect;
		class Texture;
		class SpritePrototype;
		class MaterialPrototype;
	}
	namespace manager
	{
		class ResourceManager
		{
		private:
			stdext::hash_map<std::wstring,graphicsengine::resources::Font*> fonts;
			stdext::hash_map<std::wstring,graphicsengine::resources::LabelPrototype*> textBlocks;
			stdext::hash_map<std::wstring,graphicsengine::resources::Effect*> effects;
			stdext::hash_map<std::wstring,graphicsengine::resources::Texture*> textures;
			stdext::hash_map<std::wstring,graphicsengine::resources::SpritePrototype*> sprites;
			stdext::hash_map<std::wstring,graphicsengine::resources::MaterialPrototype*> materials;

			Syntax::Database::ISyntaxDatabase *database;
			IDirect3DDevice9* d3d_device;
		public:
			ResourceManager(IDirect3DDevice9* d3d_device);
			virtual ~ResourceManager(void);
			virtual void Clear(void);
			virtual void SetDatabase(Syntax::Database::ISyntaxDatabase *database);
			virtual graphicsengine::resources::Font* GetFont(const std::wstring& name);
			virtual graphicsengine::resources::Effect* GetEffect(const std::wstring& name);
			virtual graphicsengine::resources::LabelPrototype* GetLabel(const std::wstring& name);
			virtual graphicsengine::resources::Texture* GetTexture(const std::wstring& name);
			virtual graphicsengine::resources::SpritePrototype* GetSprite(const std::wstring& name);
			virtual graphicsengine::resources::MaterialPrototype* GetMaterial(const std::wstring& name);
		private:
			template<class T> 
			void Load(stdext::hash_map<std::wstring,T*> &items,std::wstring record,bool preload = false);
			template<class T> 
			void Clear(stdext::hash_map<std::wstring,T*> &items);
			template<class T> 
			T* Get(const std::wstring &name,stdext::hash_map<std::wstring,T*> &items) const;
		};

		
		template<class T> 
		void ResourceManager::Load(stdext::hash_map<std::wstring,T*> &items,std::wstring record,bool preload)
		{
			const IRecord *records = database->GetRecord(record);
			const vector<const IRecord*>& children = records->GetChildren();
			for(unsigned int count = 0;count < children.size();count++)
			{
				const IRecord *record = children[count];
				T* item = new T(d3d_device,record);
				items[item->Name()] = item;
				if(preload) item->AddRef();
			}
		}

		template<class T> 
		void ResourceManager::Clear(stdext::hash_map<std::wstring,T*> &items)
		{
			for_each(items.begin(),items.end(),DeleteFOPair());
			items.clear();
		}

		template<class T> 
		T* ResourceManager::Get(const std::wstring &name,stdext::hash_map<std::wstring,T*> &items) const
		{
			 hash_map<wstring,T*>::iterator iterator = items.find(name);
			 if(iterator == items.end()) return NULL;
			 T* result = iterator->second;
			 return result;
		}

	}
}

	