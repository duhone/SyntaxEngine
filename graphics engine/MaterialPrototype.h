#pragma once
#include "resource.h"
#include "IResource.h"

namespace graphicsengine
{
	namespace renderables
	{
		class Material;
	}
	namespace resources
	{
		class MaterialPrototype :
			public IResource, public graphicsengine::resources::Resource
		{
		public:
			MaterialPrototype(IDirect3DDevice9* d3d_device,const Syntax::Database::IRecord *record);
			virtual ~MaterialPrototype(void);
			virtual void BuildResource();
			virtual void FreeResource();
			virtual void Release(void);
			const std::vector<std::wstring>& Textures() const {return textures;}
			const std::vector<std::pair<std::wstring,D3DXVECTOR4> >& Properties() const {return properties;}
			const std::wstring& Effect() const {return effect;}
			graphicsengine::renderables::Material *Material() {return material;}
		private:
			std::vector<std::wstring> textures;
			std::vector<std::pair<std::wstring,D3DXVECTOR4> > properties;
			std::wstring effect;
			graphicsengine::renderables::Material *material;
		};
	}
}