#include "StdAfx.h"
#include "Test.h"
#include<sstream>

using namespace std;
using namespace Syntax::Database;
using namespace Syntax::Utility;

#define NUMSPRITES 4000

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
	perpixelZBlock = graphicsEngine->CreateLabel(L"stdblock");
	perpixelZBlock->SetLocation(-0.6f,-0.4f);
	perpixelZBlock->SetColor(1.0f,1.0f,1.0f,1.0f);
	perpixelZBlock->SetText(L"Color key transparency with per pixel z sprite.\nHeight info stored in alpha.");

	square = graphicsEngine->CreateSprite(L"square");
	square->SetPosition(-3.5f,2.5,10);
	square->SetScale(0.6f,1.2f);
	bar = graphicsEngine->CreateSprite(L"bar");
	bar->SetPosition(-2,2.5f,10);
	bar->SetScale(1.5f,0.5f);

	qualityBlock = graphicsEngine->CreateLabel(L"stdblock");
	qualityBlock->SetLocation(0.1f,-0.4f);
	qualityBlock->SetColor(1.0f,1.0f,1.0f,1.0f);
	wstringstream qualityText;
	qualityText << L"Engine quality settings.\nEngine currently set to quality " << quality;
	qualityBlock->SetText(qualityText.str());

	qualitysquare = graphicsEngine->CreateSprite(L"squarequality");
	qualitysquare->SetPosition(3.5f,2.5,10);
	qualitysquare->SetScale(0.6f,1.2f);
	qualitybar = graphicsEngine->CreateSprite(L"barquality");
	qualitybar->SetPosition(3.5,2.5f,10);
	qualitybar->SetScale(1.5f,0.5f);

	
	twirlBlock = graphicsEngine->CreateLabel(L"stdblock");
	twirlBlock->SetLocation(-0.6f,0.0f);
	twirlBlock->SetColor(1.0f,1.0f,1.0f,1.0f);
	twirlBlock->SetText(L"Custom user code driven shader\nTwirl");
	
	twirl = graphicsEngine->CreateSprite(L"twirl");
	twirl->SetPosition(-4,-1.5,10);
	twirl->SetScale(1.8f,2);
	twirl->SetCustomParameter(L"Angle",0,0,0,0);

	
	lightBlock = graphicsEngine->CreateLabel(L"stdblock");
	lightBlock->SetLocation(0.1f,0.0f);
	lightBlock->SetColor(1.0f,1.0f,1.0f,1.0f);
	lightBlock->SetText(L"Custom user code driven shader\nbasic light controled by custom\nfx parameter from user code");
	
	litlakus = graphicsEngine->CreateSprite(L"lakus");
	litlakus->SetPosition(3,-2.0,10);
	litlakus->SetScale(1.0f,1.2f);
	light = graphicsEngine->CreateSprite(L"light");
	light->SetPosition(1.5f,-2.0,10);
	light->SetScale(0.2f,0.2f);


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
}

Test::~Test(void)
{
	fpsBlock->Release();
	memBlock->Release();
	perpixelZBlock->Release();
	square->Release();
	bar->Release();
	qualityBlock->Release();
	qualitysquare->Release();
	qualitybar->Release();
	twirlBlock->Release();
	twirl->Release();
	lightBlock->Release();
	light->Release();
	litlakus->Release();
	graphicsEngine->Shutdown();
}

void Test::Iterate(void)
{
	if(zleft)
	{
		bar->Move(-0.02f,0,0);
		if(bar->X() <= -5)
			zleft = false;
	}
	else
	{
		bar->Move(0.02f,0,0);
		if(bar->X() >= -2)
			zleft = true;
	}
	
	if(angleup)
	{
		angle += 0.05f;
		if(angle >= 10)
			angleup = false;
	}
	else
	{
		angle -= 0.05f;
		if(angle <= 0)
			angleup = true;
	}
	twirl->SetCustomParameter(L"Angle",angle,0,0,0);
	
	lightAngle += 0.01f;
	if(lightAngle > 6.282)
		lightAngle -= 6.282;
	lx = 3 + cos(lightAngle);
	ly = -2 + sin(lightAngle);
	light->SetPosition(lx,ly,10);
	litlakus->SetCustomParameter(L"Light",cos(lightAngle),sin(lightAngle),0,0);

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

		quality++;
		quality = quality & 1;
		graphicsEngine->SetQuality(quality);
		wstringstream qualityText;
		qualityText << L"Engine quality settings.\nEngine currently set to quality " << quality;
		qualityBlock->SetText(qualityText.str());

	}
	graphicsEngine->Commit();
}