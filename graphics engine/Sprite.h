#pragma once
#include"Renderable.h"
#include"ISprite.h"
#include "IRenderer.h"


namespace graphicsengine
{
	namespace resources
	{
		class Texture;
		class SpritePrototype;
	}
	namespace renderables
	{
		class FrameSet;
		class Material;

		class Sprite :
			public ISprite , public graphicsengine::renderables::Renderable
		{
		private:
			D3DXMATRIX world;
		public:
			void Init(void);
			Sprite(graphicsengine::resources::SpritePrototype *prototype);
			
			virtual void CopyNewValues();
			virtual void AssignToRenderManager(void);
			virtual float X(void) {return x;};
			virtual float Y(void) {return y;};
			virtual float Z(void) {return z;};
			virtual void SetPosition(float x, float y, float z);
			virtual void SetFrameSet(std::wstring);
			virtual std::wstring GetCurrentFrameSet();
			FrameSet* GetFrameSet() { return currentframeSet;}
			FrameSet** GetFrameSetPtr() { return &currentframeSet;}
			//graphicsengine::resources::Texture* GetCurrentTexture();
			Material* GetMaterial() const;
			bool IsAlpha(void)
			{
				return alpha;
			}
			D3DXMATRIX* World(void)
			{
				return &world;
			}
			virtual void Move(float x, float y, float z);
			virtual void RotateX(float angle);
			virtual void RotateY(float angle);
			virtual void RotateZ(float angle);

			virtual void SetScale(float x, float y);
			virtual void ResetRotation(void);
			virtual void SetColor(float red, float green, float blue, float alpha);
			virtual void SetCustomParameter(const std::wstring& parameter,float x,float y,float z,float w);
			virtual graphicsengine::renderers::IRenderer::RendererType GetRenderer();
			D3DXVECTOR4* Color() {return &color;}
			virtual void AnimateOnce() { newAnimateOnce = true;};
		public:
			virtual ~Sprite(void);
			virtual graphicsengine::resources::Effect* GetEffect(void);
			//virtual const graphicsengine::resources::Resource* const GetResource(void) const;
			virtual void Render();
			virtual void BuildExecutionPlan(graphicsengine::renderables::ObjectExecutionPlan* plan,
				graphicsengine::resources::Effect* effect);
			virtual void ReadyToMove();
			virtual void Visible(bool visible) {this->newVisible = visible;};
			virtual bool Visible() const {return newVisible;};
			virtual int CurrentFrame() const;
			virtual void CurrentFrame(int newFrame) { newFrameNumber = newFrame;}
		private:
			int newFrameNumber;
			bool animateOnce;
			bool newAnimateOnce;
			bool visible;
			bool newVisible;
			float x,y,z;
			stdext::hash_map<std::wstring,FrameSet*> framesets;
			FrameSet* currentframeSet;
			bool alpha;
			bool animate;
			float newx,newy, newz;
			float scalex,scaley;
			std::wstring frame;
			std::wstring newFrame;
			std::wstring moveFrame;
			graphicsengine::resources::SpritePrototype *prototype;
			D3DXMATRIX translation;
			D3DXMATRIX scaling;
			D3DXMATRIX rotation;
			D3DXMATRIX newRotation;
			D3DXVECTOR3 up;
			D3DXVECTOR3 forward;
			D3DXVECTOR3 side;
			D3DXVECTOR3 newUp;
			D3DXVECTOR3 newForward;
			D3DXVECTOR3 newSide;
			D3DXVECTOR4 color;
			D3DXVECTOR4 newColor;
			graphicsengine::renderables::ObjectExecutionPlan* plan;
			std::vector<std::pair<std::wstring,D3DXVECTOR4> > newCustomSemantics;
			stdext::hash_map<std::wstring,D3DXVECTOR4> customSemantics;
			virtual void Animate(bool animate);
		};
	}
}