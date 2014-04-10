#pragma once

#include"../../graphics engine/IGraphicsEngine.h"
#include"../../graphics engine/ILabel.h"
#include"../../Syntax Database/SyntaxDatabase.h"


class TestText
{
private:
	graphicsengine::IGraphicsEngine* graphicsEngine;
	Syntax::Database::ISyntaxDatabase* database;
	graphicsengine::ILabel* fpsBlock;
	graphicsengine::ILabel* memBlock;
	graphicsengine::ILabel* bigText;
	graphicsengine::ILabel* anchorTLText;
	graphicsengine::ILabel* anchorBRText;
	graphicsengine::ILabel* transText;
	graphicsengine::ILabel* paraText;
	graphicsengine::ILabel* moveText;
	graphicsengine::ILabel* moveText2;
	graphicsengine::ILabel* japText;
	graphicsengine::ILabel* uniText;
	graphicsengine::ILabel* chiText;
	graphicsengine::ILabel* rusText;

	LARGE_INTEGER starttime;
	LARGE_INTEGER endtime;
	double timerfreq;
	int fpscount;
	float textx;
	float texty;
	float xv;
	float yv;
	float swidth;
	float textx2;
	float texty2;
	float xv2;
	float yv2;

public:
	TestText(HWND hwnd);
public:
	~TestText(void);
public:
	void Iterate(void);
};
