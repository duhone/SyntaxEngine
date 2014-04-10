#pragma once

namespace graphicsengine
{
	namespace resources
	{
		class Texture;
		class MaterialPrototype;
		class Effect;
	}
	namespace renderables
	{
		class Material
		{
		public:
			Material(graphicsengine::resources::MaterialPrototype *material);
			virtual ~Material(void);
			const std::vector<graphicsengine::resources::Texture*>& Textures() const {return textures;}
			graphicsengine::resources::Effect* const Effect() const {return effect;}
			const std::vector<std::pair<std::wstring,D3DXVECTOR4> >& Properties() const;
			long GetId() const;
		private:
			std::vector<graphicsengine::resources::Texture*> textures;
			graphicsengine::resources::Effect *effect;
			graphicsengine::resources::MaterialPrototype *prototype;

		};
	}
}
