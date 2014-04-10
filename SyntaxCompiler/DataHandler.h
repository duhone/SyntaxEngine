#pragma once
#include "inodehandler.h"

namespace Syntax
{
	namespace Compiler
	{
		class DataHandler :
			public Syntax::Compiler::INodeHandler
		{
		public:
			DataHandler(void);
			virtual ~DataHandler(void);
			virtual std::wstring Handles() {return L"data";}
			virtual std::wstring Parent() {return L"";}
			virtual INodeCompiler* StartElement();
		};
	}
}
