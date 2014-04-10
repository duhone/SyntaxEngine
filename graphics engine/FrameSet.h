#pragma once

namespace graphicsengine
{
	namespace renderables
	{
		class Material;
	}
	namespace resources
	{
		class Texture;
		class Effect;
		class MaterialPrototype;
	}
	namespace renderables
	{
		class FrameSet
		{
		public:
			FrameSet(std::wstring* name,graphicsengine::resources::MaterialPrototype* material,
				int framewidth, float fps);
		public:
			virtual ~FrameSet(void);
		public:
			std::wstring name;
		public:
			graphicsengine::renderables::Material* Material() const;
			graphicsengine::resources::Effect* GetEffect(void);
		public:
			int frameWidth;
			void Animate(float time);
			void InitAnimation(void);
			int CurrentFrame() const { return currentFrame;}
			void CurrentFrame(int newFrame)
			{
				if(newFrame >= nframes)
					newFrame = nframes-1;
				currentFrame = newFrame;
			}
			int NFrames() const { return nframes; }
		private:
			graphicsengine::resources::MaterialPrototype* material;
			float fps;
			int nframes;
			int currentFrame;
			float timeBetweenFrames;
			float timeTillNextFrame;
		};
	}
}
