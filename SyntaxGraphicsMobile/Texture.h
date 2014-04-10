#pragma once
#include "Resource.h"

namespace Syntax
{
	namespace Graphics
	{
		class ISurface;

		class Texture : public Resource
		{
		public:
			Texture(const Syntax::Database::IRecord *record);
			virtual ~Texture(void);
			virtual void BuildResource(void);
			virtual void FreeResource(void);
			long Width() {return width;}
			long Height() {return height;}
			const boost::shared_ptr<ISurface>& Surface() {return surface;}
		private:
			long width;
			long height;
			boost::shared_ptr<ISurface> surface;
		};
	}
}
