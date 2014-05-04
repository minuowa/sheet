#include "EditorSheetEvent.h"
#include "EObjectListSheet.h"
#include "EEditorSheetManager.h"
#include "..\src\gui\kernel\qaction.h"

EEditorEventAgent::EEditorEventAgent ()
{
}

EEditorEventAgent::~EEditorEventAgent()
{

}

void EEditorEventAgent::onSelectionChanged ( const QItemSelection &selected, const QItemSelection &deselected )
{
    const QModelIndexList&  indexlist = selected.indexes();
    CXASSERT ( indexlist.size() == 1 );
    {
        SheetMgr->GetObjectListSheet()->onSelect ( indexlist.front() );
    }
}

void EEditorEventAgent::onAddObjectAction ( QAction* action )
{
    QString typeName = action->text();

    EditorEvent event;
    event.mType = eEditorToScene_Add;
    event.mArgs.push_back ( typeName.toStdString().c_str() );
    SheetMgr->PostEvent ( event );
}

void EEditorEventAgent::onComponentAction ( QAction* action )
{
    QString componentTypeName = action->text();
    const QString& name = SheetMgr->GetSelectObj();
    EditorEvent editorevent;
    editorevent.mType = action->isChecked() ? eEditorToScene_ComponentAttach
                        : eEditorToScene_ComponentDettach;
    editorevent.mArgs.push_back ( CharString ( name.toStdString().c_str() ) );
    editorevent.mArgs.push_back ( CharString ( componentTypeName.toStdString().c_str() ) );
    SheetMgr->PostEvent ( editorevent );
}
