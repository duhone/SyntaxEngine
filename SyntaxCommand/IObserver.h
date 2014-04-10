#pragma once

namespace Syntax
{
	namespace Command
	{
		class IObserver
		{
		public:
			virtual void operator()(int arg) = 0;
		protected:
			IObserver(void) {}
			~IObserver(void) {}
		};
	}
}
