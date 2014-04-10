// Test4.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Test4.h"

#include<windows.h>
#include<stdlib.h>
#include<TCHAR.h>
#include<memory.h>
#include "test.h"

#include "Syntax Database.h"

using namespace std;
using namespace Syntax;
using namespace Syntax::Utility;
using namespace Syntax::Database;

bool done;
bool mouse_first = true;
unsigned int mousexi;
unsigned int mouseyi;
HWND hwndm;
Test *test;

LRESULT CALLBACK WndProcsaver(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	switch(message)
	{
	  case WM_SYSCOMMAND:
		 if (wParam==SC_SCREENSAVE)
        {
          return FALSE;
        }
		 break;
		case WM_DESTROY:
			PostQuitMessage(0);
			done = true;
			return false;
		case WM_INPUT:
			UINT dwSize;

			GetRawInputData((HRAWINPUT)lParam, RID_INPUT, NULL, &dwSize, 
							sizeof(RAWINPUTHEADER));
			LPBYTE lpb = new BYTE[dwSize];
			if (lpb == NULL) 
			{
				return false;
			} 

			if (GetRawInputData((HRAWINPUT)lParam, RID_INPUT, lpb, &dwSize, 
				 sizeof(RAWINPUTHEADER)) != dwSize )
				 OutputDebugString (TEXT("GetRawInputData doesn't return correct size !\n")); 

			RAWINPUT* raw = (RAWINPUT*)lpb;

			if (raw->header.dwType == RIM_TYPEKEYBOARD) 
			{
				if(raw->data.keyboard.VKey == VK_ESCAPE)
				{
					PostQuitMessage(0);
					done = true;
				}
				if(raw->data.keyboard.VKey == 'W')
				{
					if(raw->data.keyboard.Message == WM_KEYDOWN)
						test->Forward(true);
					else
						test->Forward(false);
				}
				if(raw->data.keyboard.VKey == 'S')
				{
					if(raw->data.keyboard.Message == WM_KEYDOWN)
						test->Backward(true);
					else
						test->Backward(false);
				}
				if(raw->data.keyboard.VKey == 'A')
				{
					if(raw->data.keyboard.Message == WM_KEYDOWN)
						test->Left(true);
					else
						test->Left(false);
				}
				if(raw->data.keyboard.VKey == 'D')
				{
					if(raw->data.keyboard.Message == WM_KEYDOWN)
						test->Right(true);
					else
						test->Right(false);
				}
				if(raw->data.keyboard.VKey == VK_UP)
				{
					if(raw->data.keyboard.Message == WM_KEYDOWN)
						test->ScaleUp(true);
					else
						test->ScaleUp(false);
				}
				if(raw->data.keyboard.VKey == VK_DOWN)
				{
					if(raw->data.keyboard.Message == WM_KEYDOWN)
						test->ScaleDn(true);
					else
						test->ScaleDn(false);
				}
			}

			delete[] lpb; 
			
			return false;

	};
	return DefWindowProc(hwnd,message,wParam,lParam);
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{

	done = false;
	srand(GetTickCount());
	MSG msg;

	int width = GetSystemMetrics(SM_CXSCREEN); 
	int height = GetSystemMetrics(SM_CYSCREEN);

 	WNDCLASS wc;
	wc.style = 0;
	wc.lpfnWndProc = WndProcsaver;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(hInstance,NULL/*MAKEINTRESOURCE(IDI_ICON1)*/);
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	wc.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = _T("test4EXE");
	RegisterClass(&wc);

	hwndm = CreateWindowEx(0/*WS_EX_TOPMOST*/,_T("test4EXE"),NULL,WS_POPUP,0,0,width,height,NULL,NULL,hInstance,NULL);
		if(PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	ShowWindow(hwndm,SW_SHOW);
	SetFocus(hwndm);
	
	ShowCursor(false);
	test = new Test(hwndm);
	
	RAWINPUTDEVICE Rid[2];
        
	Rid[0].usUsagePage = 0x01; 
	Rid[0].usUsage = 0x02; 
	Rid[0].dwFlags = RIDEV_NOLEGACY;   // adds HID mouse and also ignores legacy mouse messages
	Rid[0].hwndTarget = 0;

	Rid[1].usUsagePage = 0x01; 
	Rid[1].usUsage = 0x06; 
	Rid[1].dwFlags = RIDEV_NOLEGACY;   // adds HID keyboard and also ignores legacy keyboard messages
	Rid[1].hwndTarget = 0;

	if (RegisterRawInputDevices(Rid, 2, sizeof(Rid[0])) == FALSE) {
		//registration failed. Call GetLastError for the cause of the error
	}

	while(!done)
	{
		if(PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		test->Iterate();
	}
	delete test;
	ShowCursor(true);
	return 0;
}
