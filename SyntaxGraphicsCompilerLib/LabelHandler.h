#pragma once
#include "inodehandler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class LabelCompiler;

		class LabelHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			LabelHandler(void);
			virtual ~LabelHandler(void);
			virtual std::wstring Handles() {return L"label";}
			virtual std::wstring Parent() {return L"labels";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value);
			virtual Syntax::Compiler::INodeCompiler* StartElement();
		private:
			LabelCompiler* compiler;
		};
	}
}
