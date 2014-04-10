#pragma once
#include "inodehandler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class EffectCompiler;

		class EffectHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			EffectHandler(void);
			virtual ~EffectHandler(void);
			virtual std::wstring Handles() {return L"effect";}
			virtual std::wstring Parent() {return L"effects";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value);
			virtual Syntax::Compiler::INodeCompiler* StartElement();
		private:
			EffectCompiler* compiler;
		};
	}
}
