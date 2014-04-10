#pragma once
#include"IGraphicsEngine.h"
#include"ILabel.h"
#include"ISprite.h"
#include"../../Syntax Database/SyntaxDatabase.h"
#include "Timer.h"
using namespace graphicsengine;


class Test
{
public:
	Test(HWND hwnd);
public:
	virtual ~Test(void);
	void Iterate(void);
	void Forward(bool forward) {this->forward = forward;}
	void Backward(bool backward) {this->backward = backward;}
	void Left(bool left) {this->left = left;}
	void Right(bool right) {this->right = right;}
	void ScaleUp(bool scaleUp) {this->scaleUp = scaleUp;}
	void ScaleDn(bool scaleDn) {this->scaleDn = scaleDn;}
private:
	Syntax::Database::ISyntaxDatabase* database;
	IGraphicsEngine* graphicsEngine;
	ILabel* fpsBlock;
	ILabel* memBlock;
	ILabel* helpBlock;
	ISprite* tile0;
	ISprite* tile1;
	ISprite* tile2;
	ISprite* tile3;
	ISprite* lavaBeast;

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
	Syntax::Utility::Timer timer;
	bool forward;
	bool backward;
	bool left;
	bool right;
	float x,y;
	float scale;
	bool scaleUp;
	bool scaleDn;
};
