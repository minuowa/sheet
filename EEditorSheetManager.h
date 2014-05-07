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
class QAction;
class PROPERTYSHEET_EXPORT EEditorManager: public QObject, public Actor
{
    //CXDeclareSingleton(EEditorSheetManager);
	Q_OBJECT
public:
    EEditorManager ( void );
    ~EEditorManager ( void );

    bool Init ( QMainWindow* parent );

    QTreeView* GetPropertyView() const;
    QTreeView* GetObjectListView() const;
    EObjectListSheet* GetObjectListSheet() const;

    const EditorEventArr&  GetEventArr() const;
    void ClearEvent();
    void AddGameObjType ( const char* gameobjType );
    void SetWndProc ( void* proc );
    void* GetWindowProc() const;
    void ProcWindowEvent ( MSG* msg );

    void InitObjectMenu ( const CharStringArr& gameobjTypeArr );
    void InitComponentMenu ( const CharStringArr& componentTypeArr );
    void SetComponentMenuState ( const char* componentType, bool checked, bool enabled );
    void ResetComponentMenuState();

    virtual bool OnNotify ( const EditorEvent& event );
public slots:
    void onAddObjectAction ( QAction* );
    void onComponentAction ( QAction* );
protected:
    EPropertySheet* mPropertySheet;
    EObjectListSheet* mObjectListSheet;
    EditorEventArr	mCurEventArr;

    void* mWindowProc;
    QMainWindow* mParent;
    QMenu* mComponentMenu;
    QMenu* mObjectMenu;
	QString mCurSelectObj;

public:

    inline EPropertySheet* GetPropertySheet() const
    {
        return mPropertySheet;
    }
	inline 	const QString& GetSelectObj() const
	{
		return mCurSelectObj;
	}
	inline void SetSelectObj(const char* obj)
	{
		mCurSelectObj=obj;
	}
};

#define SheetMgr CXSingleton<EEditorManager>::GetSingletonPtr()
