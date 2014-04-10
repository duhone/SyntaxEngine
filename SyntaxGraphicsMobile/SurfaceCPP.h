#pragma once
#include "isurface.h"
#include "CacheAlignedArray.h"
#include "ForwardDeclarations.h"
#include <assert.h>

namespace Syntax
{
	namespace Graphics
	{
		class SurfaceCPP :
			public Syntax::Graphics::ISurface
		{
		public:
			SurfaceCPP(unsigned long _width,unsigned long _height);
			virtual ~SurfaceCPP(void);
			virtual void Serialize(Syntax::Utility::BinaryWriter &_writer) const { assert(true); }
			virtual void DeSerialize(Syntax::Utility::BinaryReader &_reader);
			unsigned long Width() const {return width;}
			unsigned long Height() const {return height;}
			virtual const unsigned short *Surface16() const {return surface.Get();}
			virtual const unsigned char *Surface8() const {return NULL;}
			virtual const unsigned char *SurfaceAlpha() const {return NULL;}
			virtual const unsigned short *SurfacePallette() const {return NULL;}
		private:
			Syntax::Utility::CacheAlignedArray2D<unsigned short> surface;
			unsigned long width;
			unsigned long height;
		};
	}
}
