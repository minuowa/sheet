#pragma once
#include "EditorSheetBase.h"
#include "EditorSheetEvent.h"
#include "propertysheet_global.h"
class QFrame;
class QTreeView;
class QWidget;
class TreeModel;
class EPropertySheetDelegate;
class QStandardItemModel;
class QStandardItem;
class QMenu;


class  PROPERTYSHEET_EXPORT EObjectListSheet: public EEditorWatcher
{
public:
    EObjectListSheet ( QWidget* parent = 0, QMenu* popupMenu = 0 );
    ~EObjectListSheet();
    void show();


    QTreeView* GetView() const
    {
        return mTreeView;
    }

    void onSelect ( const QModelIndex& index );
public:
    virtual bool OnNotify ( const EditorEvent& event );
protected:
    void AddObj ( const char* name, const char* parentName = 0 );

    QStandardItem* GetObj ( const char* name );


    QTreeView* mTreeView;
    QStandardItemModel* mTreeModel;
    EPropertySheetDelegate*	mDelegate;
    EEditorEventAgent	mEditorSheetEvent;
};

