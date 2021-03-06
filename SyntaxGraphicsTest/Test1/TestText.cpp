#include "TestText.h"
#include<sstream>

using namespace std;
using namespace graphicsengine;
using namespace Syntax::Database;

TestText::TestText(HWND hwnd)
{
	database = Syntax::Database::SyntaxDatabaseFactory::Instance()->CreateDatabase(L"data.edf");
	graphicsEngine = IGraphicsEngine::getInstance();
	WindowSettings* setting = new WindowSettings();
	setting->hwnd = hwnd;
	setting->renderingQuality = 1;
	graphicsEngine->Initialize(setting);
	graphicsEngine->setBackgroundColor(0,0.2f,0);
	graphicsEngine->SetDatabase(database);
	fpsBlock = graphicsEngine->CreateLabel(L"statblock");
	fpsBlock->SetLocation(0.3f,0.02f);
	fpsBlock->SetColor(1.0f,1.0f,1.0f,1.0f);
	fpsBlock->SetText(L"Frame Rate = 0.0fps");
	memBlock = graphicsEngine->CreateLabel(L"statblock");
	memBlock->SetLocation(0.6f,0.02f);
	memBlock->SetColor(1.0f,1.0f,1.0f,1.0f);
	memBlock->SetText(L"Used Memory = 0meg");
	bigText = graphicsEngine->CreateLabel(L"largeblock");
	bigText->SetLocation(0.8f,0.6f);
	bigText->SetColor(1.0f,1.0f,0.0f,1.0f);
	bigText->SetText(L"Large Font");
	anchorTLText = graphicsEngine->CreateLabel(L"anchorblock");
	anchorTLText->SetLocation(0.01f,0.01f);
	anchorTLText->SetColor(1.0f,0.0f,1.0f,1.0f);
	anchorBRText = graphicsEngine->CreateLabel(L"anchorblock");
	anchorBRText->SetColor(0.0f,1.0f,1.0f,1.0f);
	anchorBRText->SetText(L"Anchored bottom right");
	anchorBRText->SetAnchor(ILabel::ANCHOR_BOTTOM | ILabel::ANCHOR_RIGHT);
	anchorBRText->SetLocation(-0.25f,-0.05f);
	transText = graphicsEngine->CreateLabel(L"largeblock");
	transText->SetLocation(0.75f,0.595f);
	transText->SetColor(1.0f,0.0f,0.0f,0.5f);
	transText->SetText(L"Alpha Blended text");
	paraText = graphicsEngine->CreateLabel(L"statblock");
	paraText->SetLocation(0.3f,0.2f);
	paraText->SetColor(0.0f,0.0f,1.0f,1.0f);
	paraText->SetText(L"text\nwith\nline\nbreaks");
	moveText = graphicsEngine->CreateLabel(L"statblock");
	moveText->SetLocation(-0.5f,-0.5f);
	moveText->SetColor(0.0f,1.0f,0.0f,1.0f);
	moveText->SetText(L"Moving Text");
	moveText2 = graphicsEngine->CreateLabel(L"statblock");
	moveText2->SetLocation(0.5f,-0.5f);
	moveText2->SetColor(1.0f,0.0f,0.0f,1.0f);
	moveText2->SetText(L"Slow Moving Text\nwith line breaks\nA paragraph");

	
	uniText = graphicsEngine->CreateLabel(L"largeblock");
	uniText->SetLocation(0.1f,0.4f);
	uniText->SetColor(0.2f,0.3f,1.0f,1.0f);
	uniText->SetText(L"Now Supports Unicode(starting in v0.4)");
	japText = graphicsEngine->CreateLabel(L"japblock");
	japText->SetLocation(0.1f,0.45f);
	japText->SetColor(0.2f,0.3f,1.0f,1.0f);
	japText->SetText(L"こんにちは");
	rusText = graphicsEngine->CreateLabel(L"rusblock");
	rusText->SetLocation(0.1f,0.5f);
	rusText->SetColor(0.2f,0.3f,1.0f,1.0f);
	rusText->SetText(L"здравствулте!");
	chiText = graphicsEngine->CreateLabel(L"chiblock");
	chiText->SetLocation(0.1f,0.55f);
	chiText->SetColor(0.2f,0.3f,1.0f,1.0f);
	chiText->SetText(L"你好");

	LARGE_INTEGER temp;
	QueryPerformanceFrequency(&temp);
	timerfreq = 1.0/temp.QuadPart;
	QueryPerformanceCounter(&starttime);
	QueryPerformanceCounter(&endtime);
	fpscount = 0;

	textx = graphicsEngine->GetAspectRatio()/2.0f;
	texty = 0;
	swidth = graphicsEngine->GetAspectRatio();
	xv = 0.002f;
	yv = 0.002f;

	textx2 = graphicsEngine->GetAspectRatio()/2.0f - 0.2f;
	texty2 = 0.4f;
	xv2 = 0.0005f;
	yv2 = 0.0005f;

}

TestText::~TestText(void)
{
	graphicsEngine = IGraphicsEngine::getInstance();
	fpsBlock->Release();
	memBlock->Release();
	bigText->Release();
	anchorTLText->Release();
	anchorBRText->Release();
	transText->Release();
	paraText->Release();
	moveText->Release();
	moveText2->Release();
	japText->Release();
	chiText->Release();
	rusText->Release();
	uniText->Release();

	graphicsEngine->Shutdown();
	database->Release();
}

void TestText::Iterate(void)
{
	textx += xv;
	texty += yv;
	
	if(xv > 0 && textx>swidth)
		xv = -xv;
	else if(xv < 0 && textx<0)
		xv = -xv;
	if(yv > 0 && texty>1)
		yv = -yv;
	else if(yv < 0 && texty<0)
		yv = -yv;

	moveText->SetLocation(textx,texty);

	textx2 += xv2;
	texty2 += yv2;
	
	if(xv2 > 0 && textx2>swidth)
		xv2 = -xv2;
	else if(xv2 < 0 && textx2<0)
		xv2 = -xv2;
	if(yv2 > 0 && texty2>1)
		yv2 = -yv2;
	else if(yv2 < 0 && texty2<0)
		yv2 = -yv2;

	moveText2->SetLocation(textx2,texty2);


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
