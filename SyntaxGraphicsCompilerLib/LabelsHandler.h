#pragma once
#include "inodehandler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class LabelsHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			LabelsHandler(void);
			virtual ~LabelsHandler(void);
			virtual std::wstring Handles() {return L"labels";}
			virtual std::wstring Parent() {return L"data";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value) {}
			virtual Syntax::Compiler::INodeCompiler* StartElement();
		};
	}
}
