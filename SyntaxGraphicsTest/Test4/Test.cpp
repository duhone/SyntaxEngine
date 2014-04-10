#include "StdAfx.h"
#include "Test.h"
#include<sstream>

using namespace std;
using namespace Syntax::Database;
using namespace Syntax::Utility;

Test::Test(HWND hwnd)
{
	quality = 0;
	srand(GetTickCount());

	database = Syntax::Database::SyntaxDatabaseFactory::Instance()->CreateDatabase(L"data.edf");
	graphicsEngine = IGraphicsEngine::getInstance();
	WindowSettings* setting = new WindowSettings();
	setting->hwnd = hwnd;
	setting->renderingQuality = 1;
	graphicsEngine->Initialize(setting);
	graphicsEngine->setBackgroundColor(0,0,0);
	graphicsEngine->SetDatabase(database);
	graphicsEngine->SetQuality(quality);

	fpsBlock = graphicsEngine->CreateLabel(L"stdblock");
	fpsBlock->SetLocation(-0.45f,-0.45f);
	fpsBlock->SetColor(1.0f,1.0f,1.0f,1.0f);
	fpsBlock->SetText(L"Frame Rate = 0.0fps");
	memBlock = graphicsEngine->CreateLabel(L"stdblock");
	memBlock->SetLocation(-0.1f,-0.45f);
	memBlock->SetColor(1.0f,1.0f,1.0f,1.0f);
	memBlock->SetText(L"Used Memory = 0meg");
	helpBlock = graphicsEngine->CreateLabel(L"largeblock");
	helpBlock->SetLocation(-0.5f,-0.48f);
	helpBlock->SetColor(1.0f,1.0f,1.0f,1.0f);
	helpBlock->SetText(L"Use W,A,S,D to move. Up/Dn arrows to zoom. ESC to quit.");
	
	tile0 = graphicsEngine->CreateSprite(L"tile0");
	tile0->SetColor(1.0f,1.0f,1.0f,1.0f);
	tile0->SetScale(5.0f,5.0f);

	tile1 = graphicsEngine->CreateSprite(L"tile1");
	tile1->SetColor(1.0f,1.0f,1.0f,1.0f);
	tile1->SetScale(15.0f,15.0f);

	tile2 = graphicsEngine->CreateSprite(L"tile2");
	tile2->SetColor(1.0f,1.0f,1.0f,1.0f);
	tile2->SetScale(25.0f,25.0f);

	tile3 = graphicsEngine->CreateSprite(L"tile3");
	tile3->SetColor(1.0f,1.0f,1.0f,1.0f);
	tile3->SetScale(15.0f,15.0f);

	lavaBeast = graphicsEngine->CreateSprite(L"lavabeast");
	lavaBeast->SetPosition(0,0,1.9f);
	lavaBeast->SetScale(0.1f,0.1f);
	lavaBeast->Animate(false);
	lavaBeast->CurrentFrame(0);

	LARGE_INTEGER temp;
	QueryPerformanceFrequency(&temp);
	timerfreq = 1.0/temp.QuadPart;
	QueryPerformanceCounter(&starttime);
	QueryPerformanceCounter(&endtime);
	fpscount = 0;
	zleft = true;
	angle = 0;
	angleup = true;
	lightAngle = 0;

	x=0;
	y=0;
	forward = false;
	backward = false;
	left = false;
	right = false;
	scale = 1;
	scaleUp = false;
	scaleDn = false;
}

Test::~Test(void)
{
	fpsBlock->Release();
	memBlock->Release();
	helpBlock->Release();
	tile0->Release();
	tile1->Release();
	tile2->Release();
	tile3->Release();
	lavaBeast->Release();
	graphicsEngine->Shutdown();
	database->Release();
}

void Test::Iterate(void)
{
	timer.Update();
	if(left)
		x += 0.1f*timer.GetLastFrameTime();
	if(right)
		x -= 0.1f*timer.GetLastFrameTime();
	if(backward)
		y += 0.1f*timer.GetLastFrameTime();
	if(forward)
		y -= 0.1f*timer.GetLastFrameTime();
	if(left || right || forward || backward)
		lavaBeast->Animate(true);
	else
	{
		lavaBeast->Animate(false);
	}

	if(scaleUp)
		scale += 0.25f*timer.GetLastFrameTime();
	if(scaleDn)
		scale -= 0.25f*timer.GetLastFrameTime();

	if(forward)
	{
		if(left)
			lavaBeast->SetFrameSet(L"northwest");
		else if(right)
			lavaBeast->SetFrameSet(L"northeast");
		else
			lavaBeast->SetFrameSet(L"north");
	}
	else if(backward)
	{
		if(left)
			lavaBeast->SetFrameSet(L"southwest");
		else if(right)
			lavaBeast->SetFrameSet(L"southeast");
		else
			lavaBeast->SetFrameSet(L"south");
	}
	else
	{
		if(left)
			lavaBeast->SetFrameSet(L"west");
		if(right)
			lavaBeast->SetFrameSet(L"east");
	}

	tile0->SetPosition(x*scale,y*scale,5);
	tile1->SetPosition(x*scale,y*scale,4);
	tile2->SetPosition(x*scale,y*scale,3);
	tile3->SetPosition(x*scale,y*scale-0.15f*scale,2);

	tile0->SetScale(5.0f*scale,5.0f*scale);
	tile1->SetScale(15.0f*scale,15.0f*scale);
	tile2->SetScale(25.0f*scale,25.0f*scale);
	tile3->SetScale(15.0f*scale,15.0f*scale);
	lavaBeast->SetScale(0.1f*scale,0.1f*scale);

	tile0->SetCustomParameter(L"View",0,0,0,0);
	tile1->SetCustomParameter(L"View",0,0,0,0);
	tile2->SetCustomParameter(L"View",0,0,0,0);
	tile3->SetCustomParameter(L"View",0,0,0,0);

	fpscount++;
	if(fpscount >= 100)
	{
		QueryPerformanceCounter(&endtime);
		double fps = fpscount / ((endtime.QuadPart-starttime.QuadPart)*timerfreq);
		wstringstream tempstring;
		tempstring << L"Frame Rate = " << fps << L" fps";
		fpsBlock->SetText(tempstring.str());
		starttime = endtime;
		fpscount = 0;

		MEMORYSTATUSEX memstatus;
		memstatus.dwLength = sizeof(MEMORYSTATUSEX);
		GlobalMemoryStatusEx(&memstatus);
		wstringstream memstring;
		memstring << L"Used Memory = " << (memstatus.ullTotalVirtual - memstatus.ullAvailVirtual)/(1024.0*1024.0) << L" Meg";
		memBlock->SetText(memstring.str());
	}
	graphicsEngine->Commit();
}