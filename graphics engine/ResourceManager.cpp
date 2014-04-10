#include "StdAfx.h"
#include "ResourceManager.h"
#include "LabelPrototype.h"
#include "NullEffect.h"
#include "FunctionObjects.h"
#include"Font.h"
#include "Effect.h"
#include "Texture.h"
#include "SpritePrototype.h"
#include "MaterialPrototype.h"

using namespace stdext;
using namespace graphicsengine;
using namespace std;
using namespace stdext;
using namespace graphicsengine::manager;
using namespace graphicsengine::resources;
using namespace Syntax::Database;
using namespace Syntax::Utility;

graphicsengine::manager::ResourceManager::ResourceManager(IDirect3DDevice9* d3d_device)
{
	this->d3d_device = d3d_device;
}

graphicsengine::manager::ResourceManager::~ResourceManager(void)
{
	Clear();
}

void graphicsengine::manager::ResourceManager::Clear(void)
{
	Clear<Font>(fonts);
	Clear<LabelPrototype>(textBlocks);
	Clear<Effect>(effects);
	Clear<Texture>(textures);
	Clear<SpritePrototype>(sprites);
	Clear<MaterialPrototype>(materials);
}

void ResourceManager::SetDatabase(Syntax::Database::ISyntaxDatabase *database)
{
	this->database = database;
	Load<Font>(fonts,L"fonts");
	Load<LabelPrototype>(textBlocks,L"labels");
	Load<Effect>(effects,L"effects",true);
	Load<Texture>(textures,L"textures");
	Load<SpritePrototype>(sprites,L"sprites");
	Load<MaterialPrototype>(materials,L"materials");
}

 Font* ResourceManager::GetFont(const std::wstring& name)
 {
	 return Get<Font>(name,fonts);
 }

 Effect* ResourceManager::GetEffect(const std::wstring& name)
 {
	 return Get<Effect>(name,effects);
 }

 LabelPrototype* ResourceManager::GetLabel(const std::wstring& name)
 {
	 return Get<LabelPrototype>(name,textBlocks);
 }

 Texture* ResourceManager::GetTexture(const std::wstring& name)
 {
	 return Get<Texture>(name,textures);
 }

 SpritePrototype* ResourceManager::GetSprite(const std::wstring& name)
 {
	 return Get<SpritePrototype>(name,sprites);
 }

 MaterialPrototype* ResourceManager::GetMaterial(const std::wstring& name)
 {
	 return Get<MaterialPrototype>(name,materials);
 }