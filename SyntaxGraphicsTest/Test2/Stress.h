#pragma once

namespace graphicsengine
{
	class ISprite;
};


class Stress
{
private:
	graphicsengine::ISprite* sprite;
	bool right,up;

public:
	Stress(graphicsengine::ISprite* sprite);
public:
	virtual ~Stress(void);
public:
	void move(void);
};
