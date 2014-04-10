#include "StdAfx.h"
#include "SyntaxCommandImpl.h"
#include "SyntaxDatabase.h"
#include "FunctionObjects.h"

using namespace Syntax;
using namespace Syntax::Command;
using namespace Syntax::Database;
using namespace Syntax::Utility;
using namespace boost;

SyntaxCommandImpl::SyntaxCommandImpl(void)
{
}

SyntaxCommandImpl::~SyntaxCommandImpl(void)
{
}

void SyntaxCommandImpl::SetDatabase(shared_ptr<ISyntaxDatabase> database)
{
	
}
void SyntaxCommandImpl::Observe(std::wstring &name,IObserver *observer)
{

}

ICommand* SyntaxCommandImpl::GetCommand(std::wstring &name)
{
	return Find(commands,name);
}