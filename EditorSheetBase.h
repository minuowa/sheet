#pragma once
#include "XString.h"
#include "..\src\corelib\kernel\qobject.h"
enum eEditorEventType
{
	eEditorEvent_Null,
	eSceneToEditor_Add,
	eSceneToEditor_Del,
	eSceneToEditor_Sel,
	eSceneToEditor_Cut,
	eSceneToEditor_Copy,

	eEditorToScene_Add,
	eEditorToSecne_Select,
	//-------------------------------------------------------------------------
	// arg0:objectName,arg1:componentName
	//-------------------------------------------------------------------------
	eEditorToScene_ComponentAttach,
	eEditorToScene_ComponentDettach,
};
typedef CXDynaArray<CharString> CharStringArr;
struct EditorEvent
{
	eEditorEventType mType;
	CharStringArr	mArgs;
	bool			mCancel;
	EditorEvent()
		:mType(eEditorEvent_Null)
		,mCancel(false)
	{

	}
};
typedef CXDynaArray<EditorEvent> EditorEventArr;
class Watcher
{
public:
	virtual ~Watcher(void);
	virtual bool OnNotify(const EditorEvent& event);
};
typedef CXDynaArray<Watcher*> EEditorWatherArr;

class Actor:public Watcher
{
public:
	Actor();
	virtual ~Actor(void);
	void AddWatcher(Watcher* watcher);
	void Notify(const EditorEvent&);
protected:
	EEditorWatherArr mWatchers;
};

