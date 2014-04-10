#pragma once
#include <string>
#include "Guid.h"

namespace Syntax
{
	namespace Graphics
	{
		class FrameSetPrototype
		{
		public:
			FrameSetPrototype(const Syntax::Utility::Guid& id,const Syntax::Utility::Guid& material,float fps);
			FrameSetPrototype(const FrameSetPrototype &_other);
			void operator=(const FrameSetPrototype &_other);
			virtual ~FrameSetPrototype(void);
			const Syntax::Utility::Guid& ID() const { return id; }
			const Syntax::Utility::Guid& Material() const { return material; }
			float FPS() const { return fps; }
		private:
			Syntax::Utility::Guid id;
			Syntax::Utility::Guid material;
			float fps;
		};
	}
}
