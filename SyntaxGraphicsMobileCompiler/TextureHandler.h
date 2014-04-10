#pragma once
#include "c:\source\syntax engine\syntaxcompilerlib\inodehandler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class TextureCompiler;

		class TextureHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			TextureHandler(void);
			virtual ~TextureHandler(void);
			virtual std::wstring Handles() {return L"texture";}
			virtual std::wstring Parent() {return L"textures";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value);
			virtual Syntax::Compiler::INodeCompiler* StartElement();
		private:
			TextureCompiler* compiler;
		};
	}
}
