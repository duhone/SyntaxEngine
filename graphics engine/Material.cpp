#include "StdAfx.h"
#include "Material.h"
#include "ResourceManager.h"
#include "GraphicsEngine.h"
#include "MaterialPrototype.h"

using namespace graphicsengine;
using namespace graphicsengine::resources;
using namespace graphicsengine::renderables;
using namespace graphicsengine::manager;
using namespace graphicsengine::implementation;
using namespace graphicsengine::renderers;
using namespace std;
using namespace stdext;
using namespace Syntax;
using namespace Syntax::Utility;

Material::Material(MaterialPrototype *material) :prototype(material)
{
	ResourceManager* manager = ((GraphicsEngine*)IGraphicsEngine::getInstance())->GetResourceManager();
	const vector<wstring>& textures = material->Textures();
	for(unsigned int i = 0;i < textures.size();i++)
	{
		Texture *texture = manager->GetTexture(textures[i]);
		texture->AddRef();
		this->textures.push_back(texture);
	}
	this->effect = manager->GetEffect(material->Effect());
}

Material::~Material(void)
{
	ForEach(textures,mem_fun(&Texture::SubRef));
	//prototype->SubRef();
}

const std::vector<std::pair<std::wstring,D3DXVECTOR4> >& Material::Properties() const
{
	return prototype->Properties();
}	

long Material::GetId() const
{
	return prototype->GetId();
}
		