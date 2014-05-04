#include "EObjectListSheet.h"
#include "..\src\gui\kernel\qwidget.h"
#include "..\src\gui\itemviews\qtreeview.h"
#include "..\src\gui\itemviews\qstandarditemmodel.h"
#include "EEditorSheetManager.h"
#include "EObjListSheetTreeView.h"
#include "EditorSheetEvent.h"




EObjectListSheet::EObjectListSheet ( QWidget* parent/*=0*/, QMenu* popupMenu )
{
    mTreeView = new EObjListSheetTreeView ( parent, popupMenu );
    mTreeModel = new QStandardItemModel();
    mTreeView->setModel ( mTreeModel );
    mTreeView->setWindowTitle ( "Simple Tree Model" );
    mTreeView->setBaseSize ( 200, 300 );
    QSizePolicy sizePolicy ( QSizePolicy::Expanding, QSizePolicy::Expanding );
    mTreeView->setSizePolicy ( sizePolicy );

    QItemSelectionModel* selectionModel = mTreeView->selectionModel();
    EditorEventAgent->connect ( selectionModel,
                                SIGNAL ( selectionChanged ( const QItemSelection &, const QItemSelection & ) ), &mEditorSheetEvent,
                                SLOT ( onSelectionChanged ( const QItemSelection &, const QItemSelection & ) ) );
}


EObjectListSheet::~EObjectListSheet ( void )
{
}

void EObjectListSheet::AddObj ( const char* name, const char* parentName/*=0*/ )
{
    QStandardItem* root = mTreeModel->item ( 0, 0 );
    QStandardItem* newobj = new QStandardItem ( name );
	newobj->setEditable(false);
    if ( root )
    {
        QStandardItem* parent = 0;
        if ( parentName )
        {
            parent = GetObj ( parentName );
        }
        CXASSERT_RETURN ( parent );
        mTreeModel->setRowCount ( mTreeModel->rowCount() + 1 );
        parent->appendRow ( newobj );
    }
    else
    {
        root = newobj;
        mTreeModel->setRowCount ( 1 );
        mTreeModel->setItem ( 0, 0, root );
        mTreeView->expand ( root->index() );
    }
    //if (mTreeView->parent())
    //{
    //	QWidget* p=(QWidget*)mTreeView->parent();
    //	p->adjustSize();
    //}
}

bool EObjectListSheet::OnNotify ( const EditorEvent& event )
{
    if ( !__super::OnNotify ( event ) )
        return false;
    switch ( event.mType )
    {
    case eSceneToEditor_Add:
    {
        CXASSERT_RETURN_FALSE ( event.mArgs.size() == 2 );
        CharString parentName = event.mArgs[1];
        AddObj ( event.mArgs[0].c_str(), parentName == "" ? 0 : parentName.c_str() );
    }
    break;
    }
    return true;
}

void FindItem ( QStandardItem* parent, const char* name, QStandardItem*& res )
{
    if ( !parent )
    {
        return;
    }
    if ( parent->hasChildren() )
    {
        int row = parent->rowCount();
        int col = parent->columnCount();

        for ( int i = 0; i < row; ++i )
        {
            for ( int j = 0; j < col; ++j )
            {
                QStandardItem* item = parent->child ( i, j );
                if ( item )
                {
                    if ( item->text() == name )
                    {
                        res = item;
                        return;
                    }
                    else
                    {
                        FindItem ( item, name, res );
                    }
                }
            }
        }
    }
}

QStandardItem* EObjectListSheet::GetObj ( const char* name )
{
    int row = mTreeModel->rowCount();
    int col = mTreeModel->columnCount();
    QStandardItem* item = 0;
    for ( int i = 0; i < row; ++i )
    {
        for ( int j = 0; j < col; ++j )
        {
            QStandardItem* child = mTreeModel->item ( i, j );
            if ( child )
            {
                if ( child->text() == name )
                {
                    item = child;
                    return item;
                }
                else
                {
                    FindItem ( child, name, item );
                    if ( item )
                        return item;
                }
            }
        }
    }
    return item;
}

void EObjectListSheet::show()
{
    mTreeView->show();
}

void EObjectListSheet::onSelect ( const QModelIndex& index )
{
    QVariant var = mTreeModel->data ( index );
    if ( var.type() != QVariant::String )
        return;

    EditorEvent event;
    event.mType = eEditorToSecne_Select;
    event.mArgs.push_back ( var.toString().toStdString().c_str() );
    SheetMgr->PostEvent ( event );
}

