#pragma once
#include "inodehandler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class MaterialCompiler;

		class MaterialHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			MaterialHandler(void);
			virtual ~MaterialHandler(void);
			virtual std::wstring Handles() {return L"material";}
			virtual std::wstring Parent() {return L"materials";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value);
			virtual Syntax::Compiler::INodeCompiler* StartElement();
		private:
			MaterialCompiler* compiler;
		};
	}
}
