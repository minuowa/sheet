#include "EEditorSheetManager.h"
#include "EPropertySheet.h"
#include "EObjectListSheet.h"
#include "..\src\gui\widgets\qmenu.h"
#include "EObjListSheetTreeView.h"
#include "..\src\gui\widgets\qmainwindow.h"
#include "..\src\gui\widgets\qmenubar.h"
#include "..\src\corelib\kernel\qcoreapplication.h"
#include "..\src\gui\kernel\qapplication.h"
//-------------------------------------------------------------------------
EEditorManager::EEditorManager ( void )
    : mWindowProc ( 0 )
    , mParent ( 0 )
{
}


EEditorManager::~EEditorManager ( void )
{
}

bool EEditorManager::Init( QMainWindow* parent )
{
    mParent = parent;
    mPropertySheet = new EPropertySheet ( 0 );
    mObjectListSheet = new EObjectListSheet ( 0 );

	AddWatcher(mObjectListSheet);

	EditorEventAgent->setParent(mParent);

    mComponentMenu = new QMenu ( mParent );
    EditorEventAgent->connect ( mComponentMenu, SIGNAL ( triggered ( QAction* ) ), EditorEventAgent, SLOT ( onComponentAction (  QAction* ) ) );

	( ( EObjListSheetTreeView* ) mObjectListSheet->GetView() )->SetPopupMenu ( mComponentMenu );

	mObjectMenu = new QMenu ( tr("&GameObject" ));
	mParent->menuBar()->addMenu(mObjectMenu);

    return true;
}



QTreeView* EEditorManager::GetPropertyView() const
{
    return mPropertySheet->GetView();
}

QTreeView* EEditorManager::GetObjectListView() const
{
    return mObjectListSheet->GetView();
}

void EEditorManager::SetObject ( MObject* obj )
{
    mPropertySheet->SetObject ( obj );
}

const EditorEventArr& EEditorManager::GetEventArr() const
{
    return mCurEventArr;
}

void EEditorManager::PostEvent ( const EditorEvent& event )
{
    switch ( event.mType )
    {
    case eEditorToSecne_Select:
    {
        const CharString& selectobj = event.mArgs[0];
        mCurSelectObj = selectobj.c_str();
    }
    break;
    }
    mCurEventArr.push_back ( event );
}

void EEditorManager::ClearEvent()
{
    mCurEventArr.clear();
}



void EEditorManager::SetWndProc ( void* proc )
{
    mWindowProc = proc;
}

void* EEditorManager::GetWindowProc() const
{
    return mWindowProc;
}

void EEditorManager::ProcWindowEvent ( MSG* msg )
{
    if ( mWindowProc )
    {
        WNDPROC proc = ( WNDPROC ) mWindowProc;
        proc ( msg->hwnd, msg->message, msg->wParam, msg->lParam );
    }
}

EObjectListSheet* EEditorManager::GetObjectListSheet() const
{
    return mObjectListSheet;
}



void EEditorManager::InitComponentMenu( const CharStringArr& componentTypeArr )
{
	CharStringArr::const_iterator it ( componentTypeArr.begin() );
	CharStringArr::const_iterator iend ( componentTypeArr.end() );
	for ( ; it != iend; ++it )
	{
		const CharString& name = *it;
		QAction* action = new QAction ( name.c_str(), this );
		action->setCheckable ( true );
		action->setChecked ( false );
		mComponentMenu->addAction ( action );
	}
}

void EEditorManager::InitObjectMenu( const CharStringArr& gameobjTypeArr )
{
	QMenu* menu = mObjectMenu->addMenu ( "AddObject" );
	CharStringArr::const_iterator it ( gameobjTypeArr.begin() );
	CharStringArr::const_iterator iend ( gameobjTypeArr.end() );
	for ( ; it != iend; ++it )
	{
		const CharString& name = *it;
		menu->addAction ( name.c_str() );
	}
	EditorEventAgent->connect ( menu, SIGNAL ( triggered ( QAction* ) ), EditorEventAgent, SLOT ( onAddObjectAction (  QAction* ) ) );
}

void EEditorManager::SetComponentMenuState( int idx,bool checked )
{
	assert ( mComponentMenu );
	QList<QAction*> actionList = mComponentMenu->actions();
	int cnt = actionList.count();
	CXASSERT_RETURN ( idx < cnt );
	QAction* act = actionList[idx];
	CXASSERT_RETURN ( act );
	act->setChecked ( checked );
}
