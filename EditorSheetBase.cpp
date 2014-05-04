#include "EditorSheetBase.h"


EditorActor::EditorActor(void)
{
}


EditorActor::~EditorActor(void)
{
}



void EditorActor::Notify( const EditorEvent& event)
{
	EEditorWatherArr::iterator walk=mWatchers.begin();
	EEditorWatherArr::iterator end=mWatchers.end();
	for (;walk!=end;++walk)
	{
		EEditorWatcher* watcher=*walk;
		watcher->OnNotify(event);
	}
}

void EditorActor::AddWatcher( EEditorWatcher* watcher )
{
	mWatchers.push_back(watcher);
}

bool EEditorWatcher::OnNotify( const EditorEvent& event )
{
	return true;
}
