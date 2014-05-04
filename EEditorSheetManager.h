#pragma once
#include "EditorSheetBase.h"
#include "EPropertySheet.h"
#include "..\src\corelib\tools\qvector.h"
class EPropertySheet;
class EObjectListSheet;
class QTreeView;
class QWidget;
class QMenu;
class QMainWindow;
class PROPERTYSHEET_EXPORT EEditorManager: public EditorActor
{
    //CXDeclareSingleton(EEditorSheetManager);
public:
    EEditorManager ( void );
    ~EEditorManager ( void );

	bool Init ( QMainWindow* parent );

    QTreeView* GetPropertyView() const;
    QTreeView* GetObjectListView() const;
	EObjectListSheet* GetObjectListSheet() const;

    void SetObject ( MObject* obj );
    void	PostEvent ( const EditorEvent&  event );
    const EditorEventArr&  GetEventArr() const;
    void ClearEvent();
    void AddGameObjType ( const char* gameobjType );
    void SetWndProc ( void* proc );
    void* GetWindowProc() const;
    void ProcWindowEvent ( MSG* msg );

	void InitObjectMenu (const CharStringArr& gameobjTypeArr );
	void InitComponentMenu (const CharStringArr& componentTypeArr );
	void SetComponentMenuState(int idx,bool checked);
protected:

    EPropertySheet* mPropertySheet;
    EObjectListSheet* mObjectListSheet;
    EditorEventArr	mCurEventArr;

	QString mCurSelectObj;
    void* mWindowProc;
	QMainWindow* mParent;
	QMenu* mComponentMenu;
	QMenu* mObjectMenu;

public:
	inline 	const QString& GetSelectObj() const
	{
		return mCurSelectObj;
	}
	inline EPropertySheet* GetPropertySheet() const
	{
		return mPropertySheet;
	}
};

#define SheetMgr CXSingleton<EEditorManager>::GetSingletonPtr()
