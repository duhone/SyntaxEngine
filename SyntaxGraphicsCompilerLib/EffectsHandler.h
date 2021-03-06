#pragma once
#include "inodehandler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class EffectsHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			EffectsHandler(void);
			virtual ~EffectsHandler(void);
			virtual std::wstring Handles() {return L"effects";}
			virtual std::wstring Parent() {return L"data";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value) {}
			virtual Syntax::Compiler::INodeCompiler* StartElement();
		};
	}
}
