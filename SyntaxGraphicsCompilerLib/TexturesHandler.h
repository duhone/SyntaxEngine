#pragma once
#include "inodehandler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class TexturesHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			TexturesHandler(void);
			virtual ~TexturesHandler(void);
			virtual std::wstring Handles() {return L"textures";}
			virtual std::wstring Parent() {return L"data";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value) {}
			virtual Syntax::Compiler::INodeCompiler* StartElement();
		};
	}
}
