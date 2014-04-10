#pragma once
#include<string>

namespace Syntax
{
	namespace Command
	{
		class ICommand
		{
		public:
			virtual const std::wstring& Name() = 0;
			virtual void Signal(int arg) = 0;
		};
	}
}
