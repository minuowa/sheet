#include "EditorSheetBase.h"

void Actor::Notify( const EditorEvent& event)
{
	EEditorWatherArr::iterator walk=mWatchers.begin();
	EEditorWatherArr::iterator end=mWatchers.end();
	for (;walk!=end;++walk)
	{
		Watcher* watcher=*walk;
		watcher->OnNotify(event);
	}
}

void Actor::AddWatcher( Watcher* watcher )
{
	mWatchers.push_back(watcher);
}



Actor::~Actor( void )
{

}

Actor::Actor()
{

}



bool Watcher::OnNotify( const EditorEvent& event )
{
	return true;
}

Watcher::~Watcher( void )
{

}
