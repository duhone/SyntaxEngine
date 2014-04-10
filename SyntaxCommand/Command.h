#pragma once
#include "ICommand.h"
#include <hash_map>

namespace Syntax
{
	namespace Command
	{
		class IObserver;

		class Command : public ICommand
		{
		public:
			Command();
			virtual ~Command(void)
			{
			}
			void Observe(std::wstring &name,IObserver *observer);
			virtual const std::wstring& Name() {return name;}
			virtual void Signal(int arg);
		private:			
			std::wstring name;
			stdext::hash_map<std::wstring,std::vector<IObserver*> > observers;
		};
	}
}
