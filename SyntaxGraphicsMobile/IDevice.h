#pragma once
#include<string>
#include "Color.h"
#include "Rectangle.h"
#include "boost/shared_ptr.hpp"

namespace Syntax
{
	namespace Graphics
	{
		class ISurface;

		class IDevice
		{
		public:
			virtual bool Initialize(std::wstring* const _errors) = 0;
			virtual void Flip() = 0;
			virtual void Clear(unsigned char _red,
				unsigned char _green, unsigned char _blue) = 0;
			virtual unsigned int Width() const = 0;
			virtual unsigned int Height() const = 0;
			virtual void BeginUpdate() = 0;
			virtual void EndUpdate() = 0;
			virtual void Blt(const Syntax::Math::Color32 &_clearColor,
				const Syntax::Math::RectangleI &_destination) = 0;
			virtual void Blt(const boost::shared_ptr<ISurface> &_surface,
				const Syntax::Math::RectangleI &_destination,
				const Syntax::Math::RectangleI &_source) = 0;
		protected:
			IDevice(void) { }
			virtual ~IDevice(void) {}
		};
	}
}
