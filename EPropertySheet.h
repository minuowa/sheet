#ifndef PROPERTYSHEET_H
#define PROPERTYSHEET_H

#include "propertysheet_global.h"
#include "GObject.h"
#include "EditorSheetBase.h"

class QFrame;
class QTreeView;
class QWidget;
class TreeModel;
class EPropertySheetDelegate;
class QStandardItemModel;
class QStandardItem;
class PROPERTYSHEET_EXPORT EPropertySheet: public QObject,public Actor
{
	Q_OBJECT
public:
    EPropertySheet ( QWidget* parent = 0 );
    ~EPropertySheet();
    void ClearPropertyies();
    void AddProperty ( const char* categoryName, const char* propName,EPropertyVar* propVar );
	//void SetCategoryCount(int cnt);
    void show();
    void SetObject ( GObject* obj );
    QTreeView* GetView() const
    {
        return mTreeView;
    }
protected:
	QStandardItem* GetCategory ( const char* name );

    QTreeView* mTreeView;
    QStandardItemModel* mTreeModel;
    EPropertySheetDelegate*	mDelegate;
};

#endif // PROPERTYSHEET_H
