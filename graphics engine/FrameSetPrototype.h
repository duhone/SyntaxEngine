#pragma once

namespace graphicsengine
{
	namespace resources
	{
		class FrameSetPrototype
		{
		private:
			std::wstring name;
			std::wstring material;
			int framewidth;
			float fps;
		public:
			FrameSetPrototype(const std::wstring& name,const std::wstring& material,int framewidth,float fps);
		public:
			virtual ~FrameSetPrototype(void);
			std::wstring* GetName() { return &name; }
			const std::wstring& GetMaterial() { return material; }
			int GetFrameWidth() {return framewidth; }
			float GetFPS() { return fps; }
		};
	}
}
