// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SYNTAXCOMMAND_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SYNTAXCOMMAND_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#pragma once
#ifdef SYNTAXCOMMAND_EXPORTS
#define SYNTAXCOMMAND_API __declspec(dllexport)
#else
#define SYNTAXCOMMAND_API __declspec(dllimport)
#endif

#include<string>
#include"Observer.h"
#include"boost/shared_ptr.hpp"

namespace Syntax
{
	namespace Database
	{
		class ISyntaxDatabase;
	}
}

namespace Syntax
{
	namespace Command
	{
		class ICommand;

		class SYNTAXCOMMAND_API ISyntaxCommand 
		{
		public:
			virtual void SetDatabase(boost::shared_ptr<Syntax::Database::ISyntaxDatabase> database) = 0;
			virtual void Observe(std::wstring &name,IObserver *observer) = 0;
			virtual ICommand* GetCommand(std::wstring &name) = 0;
			template<class T,class Fn>
			IObserver* CreateObserver(T *_obj,Fn _functor);
		};

		template<class T,class Fn>
		IObserver* ISyntaxCommand::CreateObserver(T *_obj,Fn _functor)
		{
			return new ObserverImpl(_obj,_functor);
		}
	}
}

SYNTAXCOMMAND_API Syntax::Command::ISyntaxCommand* const GetSyntaxCommand(void);
