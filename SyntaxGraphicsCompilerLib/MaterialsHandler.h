#pragma once
#include "inodehandler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class MaterialsHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			MaterialsHandler(void);
			virtual ~MaterialsHandler(void);
			virtual std::wstring Handles() {return L"materials";}
			virtual std::wstring Parent() {return L"data";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value) {}
			virtual Syntax::Compiler::INodeCompiler* StartElement();
		};
	}
}
