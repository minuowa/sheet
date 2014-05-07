#pragma once
#include "EditorSheetBase.h"
#include "propertysheet_global.h"
#include "..\src\corelib\kernel\qobject.h"
class QFrame;
class QTreeView;
class QWidget;
class TreeModel;
class EPropertySheetDelegate;
class QStandardItemModel;
class QStandardItem;
class QMenu;
class QModelIndex;
class QItemSelection;

class  PROPERTYSHEET_EXPORT EObjectListSheet: public QObject, public Actor
{
	Q_OBJECT
public:
    EObjectListSheet (QWidget *parent=0 );
    ~EObjectListSheet();
    void show();

public:
    virtual bool OnNotify ( const EditorEvent& event );
	QStandardItem* GetObj ( const char* name );
protected:
    void AddObj ( const char* name, const char* parentName = 0 );
	void onSelect ( const QModelIndex& index );
public slots:
    void onSelectionChanged ( const QItemSelection &selected, const QItemSelection &deselected );
private:
    QTreeView* mTreeView;
    QStandardItemModel* mTreeModel;
    EPropertySheetDelegate*	mDelegate;

public:
	inline QTreeView* GetView() const
	{
		return mTreeView;
	}
};

