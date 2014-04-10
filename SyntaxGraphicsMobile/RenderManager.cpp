#include "StdAfx.h"
#include "RenderManager.h"
#include "Panel.h"
#include "ResourceManager.h"
#include "Sorting.h"
#include "FunctionObjects.h"

using namespace Syntax::Graphics;
using namespace Syntax::Utility;
using namespace std;
using namespace boost;

struct PanelPredicate
{
	bool operator()(IPanel* _arg1, IPanel *_arg2)
	{
		if(_arg1->Z() > _arg2->Z())
			return true;
		else
			return false;
	}
};

RenderManager::RenderManager(void)
{
}

RenderManager::~RenderManager(void)
{
}

shared_ptr<IPanel> RenderManager::CreatePanel(const Guid &_id)
{
	PanelPrototype *panelPrototype = ResourceManager::Instance().GetPanel(_id);
	Panel *panel = new Panel(*this,panelPrototype);
	
	InsertIntoSorted(panels,panel,PanelPredicate());
	
	return shared_ptr<IPanel>(panel,mem_fun(&Panel::Release));
}

void RenderManager::RemovePanel(IPanel *_panel)
{
	vector<Panel*>::iterator iterator = find(panels.begin(),panels.end(),_panel);
	if(iterator != panels.end())
		panels.erase(iterator);
}

void RenderManager::PanelChangeZ(IPanel *_panel)
{
	vector<Panel*>::iterator iterator = find(panels.begin(),panels.end(),_panel);
	assert(iterator != panels.end());
	if(iterator != panels.begin() && (*iterator)->Z() < (*(iterator-1))->Z()) //push up
	{
		swap(*iterator,*(iterator-1));
		--iterator;
		while(iterator != panels.begin() && (*iterator)->Z() < (*(iterator-1))->Z())
		{
			swap(*iterator,*(iterator-1));
			--iterator;
		}
	}
	else if(iterator != (panels.end()-1) && (*iterator)->Z() > (*(iterator+1))->Z())
	{
		swap(*iterator,*(iterator+1));
		++iterator;
		while(iterator != (panels.end()-1) && (*iterator)->Z() > (*(iterator+1))->Z())
		{
			swap(*iterator,*(iterator+1));
			++iterator;
		}
	}
}

void RenderManager::Render()
{
	ForEach(panels,mem_fun(&Panel::Render));
}