#ifndef PROPERTYSHEET_H
#define PROPERTYSHEET_H

#include "propertysheet_global.h"
#include "EObject.h"
#include "EditorSheetBase.h"

class QFrame;
class QTreeView;
class QWidget;
class TreeModel;
class EPropertySheetDelegate;
class QStandardItemModel;
class QStandardItem;
class PROPERTYSHEET_EXPORT EPropertySheet: public EEditorWatcher
{
public:
    EPropertySheet ( QWidget* parent = 0 );
    ~EPropertySheet();
    void ClearPropertyies();
    template<typename T>
    void AddProperty ( const char* categoryName, const char* propName );
    void show();
    void SetObject ( MObject* obj );
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
