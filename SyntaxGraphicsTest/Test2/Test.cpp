#include "StdAfx.h"
#include "Test.h"
#include<sstream>

#include "FunctionObjects.h"

using namespace std;
using namespace Syntax::Database;
using namespace Syntax::Utility;

#define NUMSPRITES 4000

Test::Test(HWND hwnd)
{
	database = Syntax::Database::SyntaxDatabaseFactory::Instance()->CreateDatabase(L"data.edf");
	
	srand(GetTickCount());
	graphicsEngine = IGraphicsEngine::getInstance();
	WindowSettings* setting = new WindowSettings();
	setting->hwnd = hwnd;
	setting->renderingQuality = 1;
	graphicsEngine->Initialize(setting);
	graphicsEngine->setBackgroundColor(0,0,0);
	graphicsEngine->SetDatabase(database);
	graphicsEngine->SetQuality(0);

	fpsBlock = graphicsEngine->CreateLabel(L"stdblock");
	fpsBlock->SetLocation(-0.45f,-0.45f);
	fpsBlock->SetColor(1.0f,1.0f,1.0f,1.0f);
	fpsBlock->SetText(L"Frame Rate = 0.0fps");
	memBlock = graphicsEngine->CreateLabel(L"stdblock");
	memBlock->SetLocation(-0.1f,-0.45f);
	memBlock->SetColor(1.0f,1.0f,1.0f,1.0f);
	memBlock->SetText(L"Used Memory = 0meg");
	rotxBlock = graphicsEngine->CreateLabel(L"stdblock");
	rotxBlock->SetLocation(-0.6f,-0.4f);
	rotxBlock->SetColor(1.0f,1.0f,1.0f,1.0f);
	rotxBlock->SetText(L"Rotation around axis x, y, and z");

	rotxSprite = graphicsEngine->CreateSprite(L"photo");
	rotxSprite->SetPosition(-5,2,10);
	rotySprite = graphicsEngine->CreateSprite(L"photo");
	rotySprite->SetPosition(-3.5,2,10);
	rotzSprite = graphicsEngine->CreateSprite(L"photo");
	rotzSprite->SetPosition(-2.0,2,10);

	colorBlock = graphicsEngine->CreateLabel(L"stdblock");
	colorBlock->SetLocation(-0.6f,-0.1f);
	colorBlock->SetColor(1.0f,1.0f,1.0f,1.0f);
	colorBlock->SetText(L"Color Modulation");
	colorSprite1 = graphicsEngine->CreateSprite(L"photo");
	colorSprite1->SetColor(0.2,1,0.2,1);
	colorSprite1->SetPosition(-5,0,10);
	colorSprite2 = graphicsEngine->CreateSprite(L"photo");
	colorSprite2->SetColor(1,0.2,1,1);
	colorSprite2->SetPosition(-3,0,10);


	zBlock = graphicsEngine->CreateLabel(L"stdblock");
	zBlock->SetLocation(-0.7f,0.1f);
	zBlock->SetColor(1.0f,1.0f,1.0f,1.0f);
	zBlock->SetText(L"Basic Z sprites");
	zSprite1 = graphicsEngine->CreateSprite(L"photo");
	zSprite1->SetPosition(-5,-2,10);
	zSprite2 = graphicsEngine->CreateSprite(L"ship");
	zSprite2->SetScale(1,1);
	zSprite2->SetPosition(-5,-2,12);
	zup = true;

	knightBlock = graphicsEngine->CreateLabel(L"stdblock");
	knightBlock->SetLocation(-0.2f,0.1f);
	knightBlock->SetColor(1.0f,1.0f,1.0f,1.0f);
	knightBlock->SetText(L"Animation walking set");
	knightSprite = graphicsEngine->CreateSprite(L"knight");
	knightSprite->SetPosition(-1,-2,10);
	knightSprite->SetFrameSet(L"walk");
	knightSprite->Animate(true);
	walk = true;

	stressBlock = graphicsEngine->CreateLabel(L"stdblock");
	stressBlock->SetLocation(0.2f,-0.4f);
	stressBlock->SetColor(1.0f,1.0f,1.0f,1.0f);
	stressBlock->SetText(L"4000 sprite stress test");
	
	for(int i = 0;i < NUMSPRITES;i++)
	{
		int type = rand()%3;
		switch(type)
		{
		case 0:
			stress.push_back(new Stress(graphicsEngine->CreateSprite(L"photo")));
			break;
		case 1:
			stress.push_back(new Stress(graphicsEngine->CreateSprite(L"ship")));
			break;
		case 2:
			ISprite* temp = graphicsEngine->CreateSprite(L"knight");
			temp->Animate(true);
			stress.push_back(new Stress(temp));
			break;
		};
		
	}

	LARGE_INTEGER temp;
	QueryPerformanceFrequency(&temp);
	timerfreq = 1.0/temp.QuadPart;
	QueryPerformanceCounter(&starttime);
	QueryPerformanceCounter(&endtime);
	fpscount = 0;
}

Test::~Test(void)
{
	fpsBlock->Release();
	memBlock->Release();
	rotxBlock->Release();
	rotxSprite->Release();
	rotySprite->Release();
	rotzSprite->Release();
	colorBlock->Release();
	colorSprite1->Release();
	colorSprite2->Release();
	zBlock->Release();
	zSprite1->Release();
	zSprite2->Release();
	knightBlock->Release();
	knightSprite->Release();
	ForEach(stress,DeleteFO());
	
	graphicsEngine->Shutdown();
}

void Test::Iterate(void)
{
	rotxSprite->RotateX(0.05);
	rotySprite->RotateY(0.05);
	rotzSprite->RotateZ(0.05);
	if(zup)
	{
		zSprite2->Move(0,0,-0.05);
		if(zSprite2->Z() <= 8)
			zup = false;
	}
	else
	{
		zSprite2->Move(0,0,0.05);
		if(zSprite2->Z() >= 12)
			zup = true;
	}
	ForEach(stress,mem_fun(&Stress::move));
	
	fpscount++;
	if(fpscount >= 100)
	{
		QueryPerformanceCounter(&endtime);
		double fps = fpscount / ((endtime.QuadPart-starttime.QuadPart)*timerfreq);
		wstringstream tempstring;
		tempstring << "Frame Rate = " << fps << " fps";
		fpsBlock->SetText(tempstring.str());
		starttime = endtime;
		fpscount = 0;

		MEMORYSTATUSEX memstatus;
		memstatus.dwLength = sizeof(MEMORYSTATUSEX);
		GlobalMemoryStatusEx(&memstatus);
		wstringstream memstring;
		memstring << "Used Memory = " << (memstatus.ullTotalVirtual - memstatus.ullAvailVirtual)/(1024.0*1024.0) << " Meg";
		memBlock->SetText(memstring.str());

		walk = !walk;
		if(walk)
		{
			knightBlock->SetText(L"Animation walking set");
			knightSprite->SetFrameSet(L"walk");
	
		}
		else
		{
			knightBlock->SetText(L"Animation running set");
			knightSprite->SetFrameSet(L"run");
		}
	}
	graphicsEngine->Commit();
}