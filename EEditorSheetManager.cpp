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

bool EEditorManager::Init ( QMainWindow* parent )
{
    mParent = parent;
    mPropertySheet = new EPropertySheet ( parent );
    mObjectListSheet = new EObjectListSheet ( parent );

	AddWatcher(mObjectListSheet);
	AddWatcher(mPropertySheet);


    mComponentMenu = new QMenu ( mParent );
    connect ( mComponentMenu, SIGNAL ( triggered ( QAction* ) ), this, SLOT ( onComponentAction (  QAction* ) ) );

    ( ( EObjListSheetTreeView* ) mObjectListSheet->GetView() )->SetPopupMenu ( mComponentMenu );

    mObjectMenu = new QMenu ( "&GameObject"  );
    mParent->menuBar()->addMenu ( mObjectMenu );

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


const EditorEventArr& EEditorManager::GetEventArr() const
{
    return mCurEventArr;
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



void EEditorManager::InitComponentMenu ( const CharStringArr& componentTypeArr )
{
    CharStringArr::const_iterator it ( componentTypeArr.begin() );
    CharStringArr::const_iterator iend ( componentTypeArr.end() );
    for ( ; it != iend; ++it )
    {
        const CharString& name = *it;
        QAction* action = new QAction ( name.c_str(), mParent );
        action->setCheckable ( true );
        action->setChecked ( false );
        mComponentMenu->addAction ( action );
    }
}

void EEditorManager::InitObjectMenu ( const CharStringArr& gameobjTypeArr )
{
    QMenu* menu = mObjectMenu->addMenu ( "AddObject" );
    CharStringArr::const_iterator it ( gameobjTypeArr.begin() );
    CharStringArr::const_iterator iend ( gameobjTypeArr.end() );
    for ( ; it != iend; ++it )
    {
        const CharString& name = *it;
        menu->addAction ( name.c_str() );
    }
    connect ( menu, SIGNAL ( triggered ( QAction* ) ), this, SLOT ( onAddObjectAction (  QAction* ) ) );
}

void EEditorManager::SetComponentMenuState ( const char* componentType, bool checked, bool enabled )
{
    assert ( mComponentMenu );
    QList<QAction*> actionList = mComponentMenu->actions();
    int cnt = actionList.count();

    for ( int i = 0; i < cnt; ++i )
    {
        QAction* action = actionList[i];
        if ( action->text() == componentType )
        {
            action->setChecked ( checked );
            action->setEnabled ( enabled );
        }
    }
}

void EEditorManager::ResetComponentMenuState()
{
    assert ( mComponentMenu );
    QList<QAction*> actionList = mComponentMenu->actions();
    int cnt = actionList.count();

    for ( int i = 0; i < cnt; ++i )
    {
        QAction* action = actionList[i];
        action->setChecked ( false );
        action->setEnabled ( true );
    }
}

bool EEditorManager::OnNotify( const EditorEvent& event )
{
	Notify(event);
	return true;
}


void EEditorManager::onAddObjectAction ( QAction* action )
{
	QString typeName = action->text();

	EditorEvent event;
	event.mType = eEditorToScene_Add;
	event.mArgs.push_back ( typeName.toStdString().c_str() );
	Notify(event);
}

void EEditorManager::onComponentAction ( QAction* action )
{
	QString componentTypeName = action->text();
	const QString& name = GetSelectObj();
	EditorEvent editorevent;
	editorevent.mType = action->isChecked() ? eEditorToScene_ComponentAttach
		: eEditorToScene_ComponentDettach;
	editorevent.mArgs.push_back ( CharString ( name.toStdString().c_str() ) );
	editorevent.mArgs.push_back ( CharString ( componentTypeName.toStdString().c_str() ) );
	Notify( editorevent );
}