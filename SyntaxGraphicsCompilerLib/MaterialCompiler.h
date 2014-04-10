#pragma once
#include "inodecompiler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class MaterialCompiler :
			public Syntax::Compiler::INodeCompiler
		{
		public:
			MaterialCompiler(void);
			virtual ~MaterialCompiler(void);
			virtual std::wstring IndexName() {return name;}
			void Name(const std::wstring &name) {this->name = name;}
			void Effect(const std::wstring &effect) {this->effect = effect;}
			void AddProperty(std::wstring name,D3DXVECTOR4 value) { properties.push_back(std::make_pair(name,value));}
			void AddTexture(std::wstring name,std::wstring value) { textures.push_back(std::make_pair(name,value));}
			virtual void CompileData(Syntax::Utility::BinaryWriter &writer);

		private:
			std::wstring name;
			std::wstring effect;
			std::vector<std::pair<std::wstring,std::wstring> > textures;
			std::vector<std::pair<std::wstring,D3DXVECTOR4> > properties;
		};
	}
}
