#pragma once
#include "inodehandler.h"

namespace Syntax
{
	namespace GraphicsCompiler
	{
		class FrameSetCompiler;

		class FrameSetHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			FrameSetHandler(void);
			virtual ~FrameSetHandler(void);
			virtual std::wstring Handles() {return L"frameset";}
			virtual std::wstring Parent() {return L"sprite";}
			virtual void HandleAttribute(const std::wstring &name,const std::wstring& value);
			virtual Syntax::Compiler::INodeCompiler* StartElement();
		private:
			FrameSetCompiler* compiler;
		};
	}
}
