#pragma once
#include "inodecompiler.h"
#include "Vector.h"
#include "Guid.h"

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
			void Effect(const std::wstring &effect) {this->effect = effect;}
			void AddProperty(std::wstring name,Syntax::Math::Vector4F value) { properties.push_back(std::make_pair(name,value));}
			void AddTexture(std::wstring name,Syntax::Utility::Guid value) { textures.push_back(std::make_pair(name,value));}
			virtual void CompileData(Syntax::Utility::BinaryWriter &writer);

		private:
			std::wstring effect;
			std::vector<std::pair<std::wstring,Syntax::Utility::Guid> > textures;
			std::vector<std::pair<std::wstring,Syntax::Math::Vector4F> > properties;
		};
	}
}
