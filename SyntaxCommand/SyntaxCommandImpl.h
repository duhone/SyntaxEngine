#pragma once
#include "syntaxcommand.h"
#include "Singleton.h"
#include<hash_map>

namespace Syntax
{
	namespace Command
	{
		class SyntaxCommandImpl :
			public Syntax::Command::ISyntaxCommand , public Syntax::Utility::Singleton<SyntaxCommandImpl>
		{
			friend Syntax::Utility::Singleton<SyntaxCommandImpl>;
		public:
			virtual void SetDatabase(boost::shared_ptr<Syntax::Database::ISyntaxDatabase> database);
			virtual void Observe(std::wstring &name,IObserver *observer);
			virtual ICommand* GetCommand(std::wstring &name);
		protected:
			SyntaxCommandImpl(void);
			virtual ~SyntaxCommandImpl(void);
		private:
			stdext::hash_map<std::wstring,ICommand*> commands;
		};
	}
}
