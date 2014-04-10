#include "StdAfx.h"
#include "MaterialRenderer.h"
#include "Material.h"
#include "Texture.h"
#include "ObjectExecutionPlan.h"
#include "Effect.h"
#include "Semantics.h"
#include "Sprite.h"

using namespace graphicsengine;
using namespace graphicsengine::renderables;
using namespace graphicsengine::renderers;
using namespace graphicsengine::resources;
using namespace graphicsengine::implementation;
using namespace std;
using namespace stdext;

namespace graphicsengine
{
	namespace resources
	{
		class TextureExecutePlan : public IExecuteSemantic
		{
		private:
			Effect* effect;
			D3DXHANDLE handle;
			Texture* texture;
		public:
			TextureExecutePlan(Effect* effect,D3DXHANDLE handle,Texture* texture)
			{
				this->effect = effect;
				this->handle = handle;
				this->texture = texture;
			}
			void Execute()
			{
				effect->SetTexture(handle,texture);
			}
		};
		
		class PropertyExecutePlan : public IExecuteSemantic
		{
		private:
			Effect* effect;
			D3DXHANDLE handle;
			D3DXVECTOR4 value;
		public:
			PropertyExecutePlan(Effect* effect,D3DXHANDLE handle,D3DXVECTOR4 value)
			{
				this->effect = effect;
				this->handle = handle;
				this->value = value;
			}
			void Execute()
			{
				effect->SetVector(handle,&value);
			}
		};
	}
}
MaterialRenderer::MaterialRenderer(Material* material)
{
	this->material = material;
}

MaterialRenderer::~MaterialRenderer(void)
{
}


void MaterialRenderer::AddRenderable(Renderable* renderable,ObjectExecutionPlan* plan,Effect* effect)
{
	Sprite *sprite = dynamic_cast<Sprite*>(renderable);
	Material *material = sprite->GetMaterial();
	const vector<Texture*> textures = material->Textures();
	for(unsigned int i = 0;i < textures.size();i++)
	{
		D3DXHANDLE handle = effect->GetHandleForSemantic(
			static_cast<Semantics::SEMANTICS>(Semantics::Texture0+i));
		if(handle != NULL)
			plan->AddExecute(new TextureExecutePlan(effect,handle,textures[i]));
	}
	const vector<pair<wstring,D3DXVECTOR4> > &properties = material->Properties();
	const hash_map<wstring,D3DXHANDLE>& availCustomSemantics = effect->GetMaterialSemantics();
	for(unsigned int i = 0;i < properties.size();i++)
	{
		hash_map<wstring,D3DXHANDLE>::const_iterator iterator = availCustomSemantics.find(properties[i].first);
		if(iterator != availCustomSemantics.end())
		{
			D3DXHANDLE handle = iterator->second;
			plan->AddExecute(new PropertyExecutePlan(
				effect,handle,properties[i].second));
		}
	}
	renderList.AddRenderable(renderable,plan,effect);
}

void MaterialRenderer::RemoveRenderable(Renderable* renderable)
{
	renderList.RemoveRenderable(renderable);
}

void MaterialRenderer::Render()
{
	renderList.Render();
}

bool MaterialRenderer::Empty()
{
	return renderList.Empty();
}

void MaterialRenderer::CopyNewValues()
{	
	renderList.CopyNewValues();
}	