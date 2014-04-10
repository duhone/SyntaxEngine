#pragma once

#include "IObserver.h"

namespace Syntax
{
	namespace Command
	{
		template<class T,class Fn>
		class ObserverImpl : public IObserver
		{
		public:

			ObserverImpl(T *_obj,Fn _functor)
			{
			}

			~ObserverImpl(void)
			{
			}
		private:
			//T::functor
		};

		template<class T,class Fn>
		IObserver* CreateObserver(T *_obj,Fn _functor)
		{
			return new ObserverImpl(_obj,_functor);
		}
	}
}
