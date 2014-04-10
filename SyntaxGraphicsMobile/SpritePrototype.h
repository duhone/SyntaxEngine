#pragma once
#include "resource.h"
#include "FrameSetPrototype.h"

namespace Syntax
{
	namespace Graphics
	{
		class SpritePrototype :
			public Syntax::Graphics::Resource
		{
		public:
			SpritePrototype(const Syntax::Database::IRecord *record);
			virtual ~SpritePrototype(void);
			virtual void BuildResource();
			virtual void FreeResource();
			const std::vector<FrameSetPrototype>& GetFrameSets() const { return framesets;}
		private:
			std::vector<FrameSetPrototype> framesets;
		};
	}
}
