#pragma once
#include "..\utility\iserializable.h"

namespace Syntax
{
	namespace Graphics
	{
		class ISurface :
			public Syntax::Utility::ISerializable
		{
		public:
			virtual const unsigned short *Surface16() const = 0;
			virtual const unsigned char *Surface8() const = 0;
			virtual const unsigned char *SurfaceAlpha() const = 0;
			virtual const unsigned short *SurfacePallette() const = 0;
		protected:
			ISurface(void) {}
			virtual ~ISurface(void)	{}
		};
	}
}
