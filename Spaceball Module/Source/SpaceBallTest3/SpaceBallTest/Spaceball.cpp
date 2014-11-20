#define _AFXDLL

#include <afxwin.h>  
#include <Windowsx.h>
#include <stdio.h>
#include <iostream>  
#include "Spaceball.h"
#include "spwmacro.h"  /* Common macros used by SpaceWare functions. */
#include "si.h"        /* Required for any SpaceWare support within an app.*/
#include "siapp.h"     /* Required for siapp.lib symbols */

SiOpenData oData;      /* Platform-specific device data */
SiGetEventData eData;  /* Platform-specific event data */
SiHdl hdl;             /* 3DxWare device handle */
SiSpwEvent siEvent;    /* 3DxWare data event */

WMRA::Pose p;

HINSTANCE _hInstance;
HINSTANCE _hPrevInstance; 
PSTR _szCmdLine; 
int _iCmdShow;


LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

int mainThread (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT ("Spaceball") ;
	HWND         hwnd, buttonHwndX, buttonHwndY, buttonHwndZ, buttonHwndrX, buttonHwndrY, buttonHwndrZ ;
	MSG          msg ;
	WNDCLASS     wndclass ;

	wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
	wndclass.lpfnWndProc   = WndProc ;
	wndclass.cbClsExtra    = 8 ;
	wndclass.cbWndExtra    = 0 ;
	wndclass.hInstance     = hInstance ;
	wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
	wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
	wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
	wndclass.lpszMenuName  = NULL ;
	wndclass.lpszClassName = szAppName ;

	if (!RegisterClass (&wndclass))
	{
		MessageBox (NULL, TEXT ("This program requires Windows NT!"), 
			szAppName, MB_ICONERROR) ;
		return 0 ;
	}
	hwnd = CreateWindow (szAppName,                  // window class name
		TEXT ("Spaceball"),      // window caption
		WS_OVERLAPPEDWINDOW,        // window style
		100,              // initial x position
		100,              // initial y position
		100,              // initial x size
		200,              // initial y size
		NULL,                       // parent window handle
		NULL,                       // window menu handle
		hInstance,                  // program instance handle
		NULL) ;                     // creation parameters

	//Buttons
	buttonHwndX = CreateWindow(TEXT("static"),         //lpClassName = type of window to create
		                    TEXT("X"),        //lpWindowName = Name that appears on the button
                            WS_VISIBLE | WS_CHILD,  //dwStyle = Window style flags
							10, 10,                // x and y coordinates of the button in pixels
							20, 15,                //width and height of the button in pixels
							hwnd,                   //hWndParent = handle of the parent or main window
							(HMENU) 1,              //Menu item ID = 1
							NULL, NULL);            //Set the last 2 params as null

	buttonHwndY = CreateWindow(TEXT("static"),         //lpClassName = type of window to create
		                    TEXT("Y"),        //lpWindowName = Name that appears on the button
                            WS_VISIBLE | WS_CHILD,  //dwStyle = Window style flags
							10, 30,                // x and y coordinates of the button in pixels
							20, 15,                //width and height of the button in pixels
							hwnd,                   //hWndParent = handle of the parent or main window
							(HMENU) 1,              //Menu item ID = 1
							NULL, NULL);            //Set the last 2 params as null

	buttonHwndZ = CreateWindow(TEXT("static"),         //lpClassName = type of window to create
		                    TEXT("Z"),        //lpWindowName = Name that appears on the button
                            WS_VISIBLE | WS_CHILD,  //dwStyle = Window style flags
							10, 50,                // x and y coordinates of the button in pixels
							20, 15,                //width and height of the button in pixels
							hwnd,                   //hWndParent = handle of the parent or main window
							(HMENU) 1,              //Menu item ID = 1
							NULL, NULL);            //Set the last 2 params as null

	buttonHwndrX = CreateWindow(TEXT("static"),         //lpClassName = type of window to create
		                    TEXT("rX"),        //lpWindowName = Name that appears on the button
                            WS_VISIBLE | WS_CHILD,  //dwStyle = Window style flags
							10, 70,                // x and y coordinates of the button in pixels
							20, 15,                //width and height of the button in pixels
							hwnd,                   //hWndParent = handle of the parent or main window
							(HMENU) 1,              //Menu item ID = 1
							NULL, NULL);            //Set the last 2 params as null

	buttonHwndrY = CreateWindow(TEXT("static"),         //lpClassName = type of window to create
		                    TEXT("rY"),        //lpWindowName = Name that appears on the button
                            WS_VISIBLE | WS_CHILD,  //dwStyle = Window style flags
							10, 90,                // x and y coordinates of the button in pixels
							20, 15,                //width and height of the button in pixels
							hwnd,                   //hWndParent = handle of the parent or main window
							(HMENU) 1,              //Menu item ID = 1
							NULL, NULL);            //Set the last 2 params as null

	buttonHwndrZ = CreateWindow(TEXT("static"),         //lpClassName = type of window to create
		                    TEXT("rZ"),        //lpWindowName = Name that appears on the button
                            WS_VISIBLE | WS_CHILD,  //dwStyle = Window style flags
							10, 110,                // x and y coordinates of the button in pixels
							20, 15,                //width and height of the button in pixels
							hwnd,                   //hWndParent = handle of the parent or main window
							(HMENU) 1,              //Menu item ID = 1
							NULL, NULL);            //Set the last 2 params as null


	ShowWindow (hwnd, iCmdShow) ;
	UpdateWindow (hwnd) ;

	SiOpenWinInit (&oData, hwnd);
	if ( (hdl = SiOpen ("app name", SI_ANY_DEVICE, SI_NO_MASK,
		SI_EVENT, &oData)) == SI_NO_HANDLE)
	{
		/* Get and display initialization error */
		MessageBox (hwnd, "Could not open a 3DxWare device", NULL,
			MB_ICONSTOP | MB_OK);
	}

	while (GetMessage (&msg, NULL, 0, 0))
	{
		SiGetEventWinInit (&eData, msg.message, msg.wParam,	msg.lParam);
		if (SiGetEvent (hdl, 0, &eData, &siEvent) == SI_IS_EVENT)
		{
			switch (siEvent.type)
			{
			case SI_MOTION_EVENT:
				break;

			case SI_ZERO_EVENT:
				break;

			case SI_BUTTON_EVENT:
				break;

			default:
				break;
			} /* end switch on 3DxWare event type*/
				   /* put the actual ball data into the buffers */
			p.x = siEvent.u.spwData.mData[SI_TZ];
			p.y = siEvent.u.spwData.mData[SI_TX];
			p.z = siEvent.u.spwData.mData[SI_TY];
			p.pitch = siEvent.u.spwData.mData[SI_RZ];
			p.roll = siEvent.u.spwData.mData[SI_RX];
			p.yaw = siEvent.u.spwData.mData[SI_RY];
			

			char LPCbuffer[20];
			
			//X
			_itoa_s(p.x,LPCbuffer,20,10);
			LPCSTR tempLPSZ = LPCbuffer;
			Button_SetText(buttonHwndX,tempLPSZ);

			//Y
			_itoa_s(p.y,LPCbuffer,20,10);
			tempLPSZ = LPCbuffer;
			Button_SetText(buttonHwndY,tempLPSZ);

			//Z
			_itoa_s(p.z,LPCbuffer,20,10);
			tempLPSZ = LPCbuffer;
			Button_SetText(buttonHwndZ,tempLPSZ);

			//rX
			_itoa_s(p.pitch,LPCbuffer,20,10);
			tempLPSZ = LPCbuffer;
			Button_SetText(buttonHwndrX,tempLPSZ);

			//rY
			_itoa_s(p.roll ,LPCbuffer,20,10);
			tempLPSZ = LPCbuffer;
			Button_SetText(buttonHwndrY,tempLPSZ);

			//rZ
			_itoa_s(p.yaw,LPCbuffer,20,10);
			tempLPSZ = LPCbuffer;
			Button_SetText(buttonHwndrZ,tempLPSZ);

		} /* end if the event was a 3DxWare event */
		else
		{
			TranslateMessage (&msg);
			DispatchMessage (&msg);
		}
	}

	/*
	* Close connection to the 3DxWare driver.
	*/
	SiClose (hdl);
	SiTerminate ();

	return msg.wParam ;
}

UINT testThread( LPVOID pParam )
{
	mainThread(_hInstance, _hPrevInstance, _szCmdLine, _iCmdShow);
	return 1;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC         hdc ;
	PAINTSTRUCT ps ;

	switch (message)
	{
	case WM_CREATE:
		return 0 ;

	case WM_PAINT:
		hdc = BeginPaint (hwnd, &ps) ;
		EndPaint (hwnd, &ps) ;
		printf("Paint");
		return 0 ;

	case WM_DESTROY:
		PostQuitMessage (0) ;
		return 0 ;
	}
	return DefWindowProc (hwnd, message, wParam, lParam) ;
}


Spaceball::Spaceball()
{
	if(initialize())
		std::cout << "SpaceBall Initialized" << std::endl;
	else
		std::cout << "SpaceBall Failed to Initialize" << std::endl;
}

int Spaceball::initialize()
{
	AfxBeginThread(testThread,NULL);
	return 1;
}

WMRA::Pose Spaceball::getDeltaPose()
{
	return p;
}