#pragma once
#include"IGraphicsEngine.h"
#include"ILabel.h"
#include"ISprite.h"
#include"../../Syntax Database/SyntaxDatabase.h"

using namespace graphicsengine;


class Test
{
private:
	Syntax::Database::ISyntaxDatabase* database;
	IGraphicsEngine* graphicsEngine;
	ILabel* fpsBlock;
	ILabel* memBlock;
	ILabel* twirlBlock;
	ILabel* perpixelZBlock;
	ISprite* square;
	ISprite* bar;
	ISprite* twirl;
	
	ILabel* qualityBlock;
	ISprite* qualitysquare;
	ISprite* qualitybar;

	ILabel* lightBlock;
	ISprite* light;
	ISprite* litlakus;

	LARGE_INTEGER starttime;
	LARGE_INTEGER endtime;
	double timerfreq;
	int fpscount;
	bool zleft;
	int quality;
	float angle;
	bool angleup;
	float lightAngle;
	float lx,ly;
public:
	Test(HWND hwnd);
public:
	virtual ~Test(void);
	void Iterate(void);
};
