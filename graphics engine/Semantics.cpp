#include "StdAfx.h"
#include "Semantics.h"

using namespace graphicsengine;
using namespace graphicsengine::implementation;
using namespace std;
using namespace stdext;

Semantics::Semantics(void)
{
	semanticLookup[L"world"] = World;
	semanticLookup[L"worldinverse"] = WorldInverse;
	semanticLookup[L"view"] = View;
	semanticLookup[L"viewinverse"] = ViewInverse;
	semanticLookup[L"worldview"] = WorldView;
	semanticLookup[L"worldviewinverse"] = WorldViewInverse;
	semanticLookup[L"worldviewprojection"] = WorldViewProjection;
	semanticLookup[L"worldviewparallel"] = WorldViewParallel;
	semanticLookup[L"color"] = Color;
	semanticLookup[L"texture0"] = Texture0;
	semanticLookup[L"texture1"] = Texture1;
	semanticLookup[L"texture2"] = Texture2;
	semanticLookup[L"texture3"] = Texture3;
	semanticLookup[L"texture4"] = Texture4;
	semanticLookup[L"texture5"] = Texture5;
	semanticLookup[L"texture6"] = Texture6;
	semanticLookup[L"texture7"] = Texture7;

	//sprite semantic setup
	semanticLookup[L"framewidth"] = FrameWidth;
	semanticLookup[L"framenumber"] = FrameNumber;

}

Semantics::~Semantics(void)
{
}
