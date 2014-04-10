#pragma once
#include "..\idevice.h"
#include <ddraw.h>

namespace Syntax
{
	namespace Graphics
	{
		class DeviceWindowsMobile :
			public Syntax::Graphics::IDevice
		{
		public:
			DeviceWindowsMobile(void);
			virtual ~DeviceWindowsMobile(void);
			virtual bool Initialize(std::wstring* const _errors);
			virtual void Flip();
			virtual void Clear(unsigned char _red,
				unsigned char _green, unsigned char _blue);
			virtual unsigned int Width() const {return 100;}
			virtual unsigned int Height() const {return 100;}
			virtual void BeginUpdate();
			virtual void EndUpdate();
			virtual void Blt(const Syntax::Math::Color32 &_clearColor,
				const Syntax::Math::RectangleI &_destination);
			virtual void Blt(const boost::shared_ptr<ISurface> &_surface,
				const Syntax::Math::RectangleI &_destination,
				const Syntax::Math::RectangleI &_source);
		private:
			LPDIRECTDRAW device;
			LPDIRECTDRAWSURFACE frontBuffer;
			LPDIRECTDRAWSURFACE backBuffer;
			bool hardwareDevice;
			unsigned short *surface;
		};
	}
}
