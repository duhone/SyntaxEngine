#include "StdAfx.h"
#include "DeviceWindowsMobile.h"
#include<sstream>
#include "../GraphicsImpl.h"
#include "../ISurface.h"

using namespace std;
using namespace Syntax;
using namespace Syntax::Graphics;
using namespace Syntax::Math;

static HRESULT PASCAL EnumSurface(LPDIRECTDRAWSURFACE _backBuffer,
             LPDDSURFACEDESC _surfaceDesc, void*  _context)
{
    static bool bCalled = false;

    if (!bCalled)
	{

        *((LPDIRECTDRAWSURFACE *)_context) = _backBuffer;
        bCalled = true;
        return DDENUMRET_OK;
    }
    else
	{

        OutputDebugString(L"DDEX1: Enumerated more than surface?");
        _backBuffer->Release();
        return DDENUMRET_CANCEL;
    }
}

DeviceWindowsMobile::DeviceWindowsMobile(void) :
device(NULL), frontBuffer(NULL), backBuffer(NULL), hardwareDevice(NULL), surface(NULL)
{
	
}

DeviceWindowsMobile::~DeviceWindowsMobile(void)
{
	if(backBuffer)
	{
		backBuffer->Release();
		backBuffer = NULL;
	}
	if(frontBuffer)
	{
		frontBuffer->Release();
		frontBuffer = NULL;
	}
	if(device)
	{
		device->Release();
		device = NULL;
	}
}

bool DeviceWindowsMobile::Initialize(std::wstring* const _errors)
{
    HRESULT hResult;
    hResult = DirectDrawCreate(NULL, &device, NULL);
	if(hResult != DD_OK)
	{
		(*_errors) += _T("Failed to create a DirectDraw device");
		return false;
	}
	hResult = device->SetCooperativeLevel(GraphicsImpl::Instance().Hwnd(), DDSCL_FULLSCREEN);
    if (hResult != DD_OK)
	{
		(*_errors) += _T("Failed to set DirectDraw cooperative level");
		return false;
	}

	DDCAPS halCaps;
    DDCAPS helCaps;
	halCaps.dwSize = sizeof(DDCAPS);
	helCaps.dwSize = sizeof(DDCAPS);

    device->GetCaps(&halCaps, &helCaps);

	hardwareDevice = true;
    if (!(halCaps.ddsCaps.dwCaps & DDSCAPS_BACKBUFFER)) 
    {
		hardwareDevice = false;
    }

    if (!(halCaps.ddsCaps.dwCaps & DDSCAPS_FLIP)) 
    {
		hardwareDevice = false;
    }

	if(hardwareDevice)
	{
		DDSURFACEDESC surfaceDesc;
		memset(&surfaceDesc, 0, sizeof(surfaceDesc));
		surfaceDesc.dwSize = sizeof(surfaceDesc);
		surfaceDesc.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
		surfaceDesc.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE |
							  DDSCAPS_FLIP;
		surfaceDesc.dwBackBufferCount = 1;
		hResult = device->CreateSurface(&surfaceDesc, &frontBuffer, NULL);
		if (hResult != DD_OK)
		{
			(*_errors) += _T("DirectDraw: Failed to create primary surface");
			return false;
		}

		hResult = frontBuffer->EnumAttachedSurfaces(&backBuffer, EnumSurface);
		if (hResult != DD_OK)
		{
			(*_errors) += _T("DirectDraw: Failed to create back buffer");
			return false;
		}
	}
	else
	{
		DDSURFACEDESC surfaceDesc;
		memset(&surfaceDesc, 0, sizeof(surfaceDesc));
		surfaceDesc.dwSize = sizeof(surfaceDesc);
		surfaceDesc.dwFlags = DDSD_CAPS;
		surfaceDesc.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
		hResult = device->CreateSurface(&surfaceDesc, &frontBuffer, NULL);
		if (hResult != DD_OK)
		{
			(*_errors) += _T("DirectDraw: Failed to create primary surface");
			return false;
		}

		memset(&surfaceDesc, 0, sizeof(surfaceDesc));
		surfaceDesc.dwSize = sizeof(surfaceDesc);
		surfaceDesc.dwFlags = DDSD_CAPS;
		surfaceDesc.ddsCaps.dwCaps = DDSCAPS_SYSTEMMEMORY;
		hResult = device->CreateSurface(&surfaceDesc, &backBuffer, NULL);
		if (hResult != DD_OK)
		{
			(*_errors) += _T("DirectDraw: Failed to create back buffer");
			return false;
		}
	}

	return true;
}

void DeviceWindowsMobile::Flip()
{
	if(hardwareDevice)
	{
		HRESULT hResult;
		hResult = frontBuffer->Flip(NULL, DDFLIP_WAITVSYNC | DDFLIP_WAITNOTBUSY);    
		if (hResult == DDERR_SURFACELOST)
		{
			hResult = frontBuffer->Restore();
		}
	}
	else
	{
		HRESULT hResult;
		DDBLTFX bltFX;

		memset(&bltFX, 0, sizeof(bltFX));
		bltFX.dwSize = sizeof(bltFX);
		hResult = frontBuffer->Blt(NULL, backBuffer, NULL,
			DDBLT_WAITNOTBUSY, &bltFX);
		if (hResult == DDERR_SURFACELOST)
		{
			hResult = frontBuffer->Restore();
		}
	}
}

void DeviceWindowsMobile::Clear(unsigned char _red,
		unsigned char _green, unsigned char _blue)
{
	unsigned short color = ((_red&0x0f8)<<8) | ((_green&0x0fc)<<3) | ((_blue>>3)&0x01f);

	unsigned short *start = surface;
	for(unsigned int i = 0;i < (Width()*Height());i++)
	{
		(*start) = color;
		++start;
	}

	/*DDBLTFX bltFX;

    memset(&bltFX, 0, sizeof(bltFX));
    bltFX.dwSize = sizeof(bltFX);
    bltFX.dwFillColor = color;
    backBuffer->Blt(NULL, NULL, NULL,
		DDBLT_COLORFILL | DDBLT_WAITNOTBUSY, &bltFX);*/

}

void DeviceWindowsMobile::BeginUpdate()
{
	DDSURFACEDESC surfaceDesc;
	surfaceDesc.dwSize = sizeof(DDSURFACEDESC);
	surfaceDesc.dwFlags = DDSD_PITCH|DDSD_XPITCH;
	backBuffer->Lock(NULL,&surfaceDesc,DDLOCK_DISCARD|DDLOCK_WAITNOTBUSY,NULL);

	surface = static_cast<unsigned short*>(surfaceDesc.lpSurface);
}

void DeviceWindowsMobile::EndUpdate()
{
	backBuffer->Unlock(NULL);
	surface = NULL;
}

void DeviceWindowsMobile::Blt(const Syntax::Math::Color32 &_clearColor,
				const Syntax::Math::RectangleI &_destination)
{
	unsigned short color = (_clearColor.Red()<<11) | (_clearColor.Green()<<5) | (_clearColor.Blue());
	unsigned char alpha = _clearColor.Alpha();

	unsigned short *start = surface+_destination.Top()*Width()+_destination.Left();
	unsigned int toNextRow = Width()-_destination.Width();
	if(alpha == 255)
	{
		for(unsigned int i = 0;i < _destination.Height();i++)
		{
			for(unsigned int j = 0;j < _destination.Width();j++)
			{
				(*start) = color;
				++start;
			}
			start += toNextRow;
		}
	}
	else
	{
		unsigned short source;
		Color32 temp;
		unsigned int working;
		for(unsigned int i = 0;i < _destination.Height();i++)
		{
			for(unsigned int j = 0;j < _destination.Width();j++)
			{
				source = (*start);
				temp = Color16To32(source);
				working = temp.Red() * (255-_clearColor.Alpha()) + (_clearColor.Red()*_clearColor.Alpha());
				temp.Red(working>>8);
				working = temp.Green() * (255-_clearColor.Alpha()) + (_clearColor.Green()*_clearColor.Alpha());
				temp.Green(working>>8);
				working = temp.Blue() * (255-_clearColor.Alpha()) + (_clearColor.Blue()*_clearColor.Alpha());
				temp.Blue(working>>8);
				(*start) = Color32To16(temp);
				++start;
			}
			start += toNextRow;
		}
	}
}

void DeviceWindowsMobile::Blt(const boost::shared_ptr<ISurface> &_surface,const Syntax::Math::RectangleI &_destination,
				const Syntax::Math::RectangleI &_source)
{
	unsigned long u,v,du,dv,dur,dvr,ur,vr;
	du = _source.Width()/_destination.Width();
	dur = _source.Width()%_destination.Width();
	dv = _source.Height()/_destination.Height();
	dvr = _source.Height()%_destination.Height();
	u = v = ur = vr = 0;

	unsigned short *start = surface+_destination.Top()*Width()+_destination.Left();
	unsigned int toNextRow = Width()-_destination.Width();
	const unsigned short *surface = _surface->Surface16();
	for(unsigned int i = 0;i < _destination.Height();i++)
	{
		for(unsigned int j = 0;j < _destination.Width();j++)
		{
			unsigned int index = _source.Left()+u+(_source.Top()+_source.Width()*v);
			(*start) = *(surface+index);
			u+=du;
			ur+=dur;
			if(ur >= _destination.Width())
			{
				u+=1;
				ur -= _destination.Width();
			}
			++start;
		}
		start += toNextRow;
		u=0;
		ur=0;
		v+=dv;
		vr+=dvr;
		if(vr > _destination.Height())
		{
			v+=1;
			vr -= _destination.Height();
		}
	}
}