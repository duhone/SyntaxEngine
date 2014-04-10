#include "StdAfx.h"
#include "Resource.h"

using namespace Syntax;
using namespace Syntax::Graphics;


Resource::Resource(const Syntax::Database::IRecord *record)
{
	this->record = record;
	refCount = 0;
}

Resource::~Resource(void)
{
}

void Resource::AddRef(void)
{
	if(refCount == 0) BuildResource();
	refCount++;
	
}

void Resource::SubRef(void)
{
	if(refCount == 0) return;
	refCount--;
	if(refCount == 0) FreeResource();
}

void Resource::Release(void)
{
	this->SubRef();
}