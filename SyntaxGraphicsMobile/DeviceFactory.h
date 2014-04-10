#pragma once
#include "Singleton.h"
#include "boost/smart_ptr.hpp"

namespace Syntax
{
	namespace Graphics
	{
		class IDevice;
		class ISurface;

		class DeviceFactory : public Syntax::Utility::Singleton<DeviceFactory>
		{
			friend Syntax::Utility::Singleton<DeviceFactory>;
		public:
			boost::shared_ptr<IDevice> CreateDevice();
			boost::shared_ptr<ISurface> CreateSurface(unsigned long _width,unsigned long _height);
		protected:
			DeviceFactory(void);
			~DeviceFactory(void);
		};
	}
}
