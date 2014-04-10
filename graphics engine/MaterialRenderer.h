#pragma once

#include "RenderList.h"
#include "Renderable.h"

namespace graphicsengine
{
	namespace resources
	{
		class MaterialPrototype;
		class Texture;
		class Effect;
	}
	namespace renderables
	{
		class Renderable;
		class Material;
	}
	namespace renderers
	{
		class MaterialRenderer
		{
		public:
			MaterialRenderer(graphicsengine::renderables::Material* material);
			virtual ~MaterialRenderer(void);
			virtual void AddRenderable(graphicsengine::renderables::Renderable* renderable,
				graphicsengine::renderables::ObjectExecutionPlan* plan,graphicsengine::resources::Effect* effect);
			virtual void RemoveRenderable(graphicsengine::renderables::Renderable* renderable);
			virtual void Render();
			virtual bool Empty();
			virtual void CopyNewValues();
		private:
			graphicsengine::renderables::Material* material;
			RenderList<graphicsengine::renderables::Renderable> renderList;
		};
	}
}
