#pragma once
#include "resource.h"
#include "Vector.h"

namespace Syntax
{
	namespace Graphics
	{
		class MaterialPrototype :
			public Syntax::Graphics::Resource
		{
		public:
			MaterialPrototype(const Syntax::Database::IRecord *record);
			virtual ~MaterialPrototype(void);			
			virtual void BuildResource();
			virtual void FreeResource();
			const std::vector<Syntax::Utility::Guid>& Textures() const {return textures;}
			const std::vector<std::pair<std::wstring,Syntax::Math::Vector4F> >& Properties() const {return properties;}
			const std::wstring& Effect() const {return effect;}
			//graphicsengine::renderables::Material *Material() {return material;}
		private:
			std::vector<Syntax::Utility::Guid> textures;
			std::vector<std::pair<std::wstring,Syntax::Math::Vector4F> > properties;
			std::wstring effect;
			//graphicsengine::renderables::Material *material;
		};
	}
}
