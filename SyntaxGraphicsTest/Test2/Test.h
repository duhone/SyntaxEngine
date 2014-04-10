#pragma once
#include"../../graphics engine/IGraphicsEngine.h"
#include"../../graphics engine/ILabel.h"
#include"../../graphics engine/ISprite.h"
#include"../../Syntax Database/SyntaxDatabase.h"
#include "Stress.h"

using namespace graphicsengine;


class Test
{
private:
	IGraphicsEngine* graphicsEngine;
	ILabel* fpsBlock;
	ILabel* memBlock;
	ILabel* rotxBlock;
	ISprite* rotxSprite;
	ISprite* rotySprite;
	ISprite* rotzSprite;

	ILabel* colorBlock;
	ISprite* colorSprite1;
	ISprite* colorSprite2;
	
	ILabel* zBlock;
	ISprite* zSprite1;
	ISprite* zSprite2;
	bool zup;

	ILabel* knightBlock;
	ISprite* knightSprite;

	ILabel* stressBlock;
	
	LARGE_INTEGER starttime;
	LARGE_INTEGER endtime;
	double timerfreq;
	int fpscount;
	bool walk;
	Syntax::Database::ISyntaxDatabase* database;
	
	std::vector<Stress*> stress;
public:
	Test(HWND hwnd);
public:
	virtual ~Test(void);
	void Iterate(void);
};
