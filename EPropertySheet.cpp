#include "EPropertySheet.h"
#include <QtGui/qwidget.h>
#include <QtGui/qtreeview.h>
#include <QtGui/qframe.h>
#include "../src/gui/itemviews/qstandarditemmodel.h"
#include "../src/corelib/codecs/qtextcodec_p.h"
#include "EPropertySheetDelegate.h"
#include <assert.h>
#include "EPropertySheetTreeItem.h"
EPropertySheet::~EPropertySheet()
{

}

EPropertySheet::EPropertySheet ( QWidget* parent/*=0*/ )
    : mTreeView ( 0 )
    , mTreeModel ( 0 )
{
    mTreeView = new QTreeView ( parent );
    mTreeModel = new QStandardItemModel();
    mTreeView->setModel ( mTreeModel );
    //mTreeView->setGeometry(parent->childrenRect());
    mTreeView->setWindowTitle ( "Simple Tree Model" );
    mDelegate = new EPropertySheetDelegate;
    mTreeView->setItemDelegate ( mDelegate );
    mTreeView->setBaseSize ( 300, 300 );
    QSizePolicy sizePolicy ( QSizePolicy::Expanding, QSizePolicy::Expanding );
    mTreeView->setSizePolicy ( sizePolicy );

    //mTreeModel->setRowCount ( 1 );
    //mTreeModel->setColumnCount ( 2 );
    //mTreeView->setColumnWidth ( 1,100 );
    mTreeModel->setRowCount ( 1 );
    mTreeModel->setColumnCount ( 2 );
    mTreeView->setColumnWidth ( 1, 100 );
}

void EPropertySheet::show()
{
    mTreeView->show();
}

void PROPERTYSHEET_EXPORT EPropertySheet::SetObject ( MObject* obj )
{
    //mTreeModel->setHeaderData ( 0, Qt::Horizontal, "EObject", Qt::DisplayRole );
    //mTreeModel->setHeaderData ( 1, Qt::Horizontal, obj->GetObjectName().c_str(), Qt::DisplayRole );
  //  const CategoryPropertyMap& propMap = obj->GetPropertyMap();
  //  mTreeModel->setRowCount ( 1 + propMap.size() );
  //  CategoryPropertyMap::const_iterator walk = propMap.begin();
  //  CategoryPropertyMap::const_iterator end = propMap.end();
  //  int row = 0;
  //  for ( ; walk != end; ++walk )
  //  {
  //      EPropertyVar* evar = walk->second;

		//CXASSERT_RETURN(evar->CategoryName.length());

		//QStandardItem* categoryItem = GetCategory(evar->CategoryName);
		//int curRow=row;
		//if (!categoryItem)
		//{
		//	row++;
		//	categoryItem=new QStandardItem(QString(evar->CategoryName.c_str()));
		//}
		//categoryItem->setEditable(false);

		//QList<QStandardItem*> lists;
  //      EPropertySheetTreeItem* item  = new EPropertySheetTreeItem ( QString ( walk->first.c_str() ) );
  //      item->setBackground ( QBrush ( Qt::lightGray ) );
  //      item->setEditable ( false );
		//lists.push_back(item);

  //      item  = new EPropertySheetTreeItem();
  //      item->SetExtraData ( evar );
  //      item->setData ( evar->QVar, Qt::EditRole );
		//lists.push_back(item);

		//categoryItem->appendRow(lists);
		//if(!mTreeModel->item(curRow, 0))
		//	mTreeModel->setItem ( curRow, 0, categoryItem );
		//mTreeView->expand(categoryItem->index());
  //  }
}

QStandardItem* EPropertySheet::GetCategory( const char* name )
{
	int row = mTreeModel->rowCount();
	QStandardItem* item = 0;
	for ( int i = 0; i < row; ++i )
	{
		QStandardItem* child = mTreeModel->item ( i, 0 );
		if ( child )
		{
			if ( child->text() == name )
			{
				item = child;
				return item;
			}
		}
	}
	return item;
}

void EPropertySheet::ClearPropertyies()
{
	mTreeModel->clear();
	mTreeModel->setColumnCount ( 2 );
	mTreeView->setColumnWidth ( 1, 100 );
}

