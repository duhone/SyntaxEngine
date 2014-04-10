#include "StdAfx.h"
#include "Stress.h"
#include"../../graphics engine/IGraphicsEngine.h"
#include"../../graphics engine/ISprite.h"

using namespace graphicsengine;

Stress::Stress(ISprite *sprite)
{
	this->sprite = sprite;
	sprite->SetPosition((rand()%50)/10.0 + 1.2,(rand()%50)/10.0 + -2.8,(rand()%20)/10.0 + 8);
	right = rand()%2;
	up = rand()%2;
}

Stress::~Stress(void)
{
	sprite->Release();
}

void Stress::move(void)
{
	if(right)
	{
		sprite->Move(0.02,0,0);
		if(sprite->X() > 6.2)
			right = false;
	}
	else
	{
		sprite->Move(-0.02,0,0);
		if(sprite->X() < 1.2)
			right = true;
	}
	if(up)
	{
		sprite->Move(0,0.02,0);
		if(sprite->Y() > 2.2)
			up = false;
	}
	else
	{
		sprite->Move(0,-0.02,0);
		if(sprite->Y() < -2.8)
			up = true;
	}
}
