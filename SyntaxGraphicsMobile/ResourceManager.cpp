#include "StdAfx.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "FunctionObjects.h"
#include "AssetList.h"
#include "PanelPrototype.h"

using namespace std;
using namespace Syntax;
using namespace Syntax::Graphics;
using namespace Syntax::Utility;
using namespace Syntax::Database;

ResourceManager::ResourceManager(void)
{
}

ResourceManager::~ResourceManager(void)
{
	Clear();
}

void ResourceManager::Clear(void)
{
	Clear<Texture>(textures);
	Clear<PanelPrototype>(panels);
}

void ResourceManager::SetDatabase(Syntax::Database::ISyntaxDatabase *database)
{
	this->database = database;
	Load<Texture>(textures,AssetList::textures::ID);
	Load<PanelPrototype>(panels,AssetList::panels::ID);
}

 Texture* ResourceManager::GetTexture(const Guid& id)
 {
	 return Get<Texture>(id,textures);
 }

MaterialPrototype* ResourceManager::GetMaterial(const Guid& id)
{
	 return Get<MaterialPrototype>(id,materials);
}

SpritePrototype* ResourceManager::GetSprite(const Guid& id)
{
	 return Get<SpritePrototype>(id,sprites);
}

PanelPrototype* ResourceManager::GetPanel(const Guid& id)
{
	 return Get<PanelPrototype>(id,panels);
}