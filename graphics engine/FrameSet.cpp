#include "StdAfx.h"
#include "FrameSet.h"
#include "Texture.h"
#include "Effect.h"
#include "MaterialPrototype.h"
#include "Material.h"

using namespace graphicsengine;
using namespace graphicsengine::renderables;
using namespace graphicsengine::resources;
using namespace std;

FrameSet::FrameSet(wstring* name,MaterialPrototype* material,
				int framewidth, float fps)
: material(material)
, frameWidth(framewidth)
, fps(fps)
{
	this->name = *name;
	material->AddRef();
	this->frameWidth = framewidth;
	this->fps = fps;
	this->timeBetweenFrames = 1.0f/fps;
	this->timeTillNextFrame = timeBetweenFrames;
	nframes = material->Material()->Textures()[0]->Width()/frameWidth;
	currentFrame = 0;
}

FrameSet::~FrameSet(void)
{
	material->SubRef();
}

void graphicsengine::renderables::FrameSet::Animate(float time)
{
	timeTillNextFrame -= time;
	if(timeTillNextFrame <= 0)
	{
		timeTillNextFrame += timeBetweenFrames;
		currentFrame++;
		if(currentFrame >= nframes)
			currentFrame = 0;
	}
}

void graphicsengine::renderables::FrameSet::InitAnimation(void)
{
	currentFrame = 0;
	timeTillNextFrame += timeBetweenFrames;
}

Effect* graphicsengine::renderables::FrameSet::GetEffect(void)
{
	return material->Material()->Effect();
}

Material* FrameSet::Material() const
{
	return material->Material();
}