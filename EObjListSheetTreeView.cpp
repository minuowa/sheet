#include "EObjListSheetTreeView.h"
#include "..\src\gui\kernel\qwidget.h"
#include "..\src\gui\kernel\qevent.h"
#include "base.h"
#include "QMenu.h"


EObjListSheetTreeView::EObjListSheetTreeView ( QWidget *parent /*= 0*/, QMenu* popmenu/*=0 */ )
    : QTreeView ( parent )
    , mPopupMenu ( popmenu )
{
    setContextMenuPolicy ( Qt::ActionsContextMenu );
}


EObjListSheetTreeView::~EObjListSheetTreeView ( void )
{
}

void EObjListSheetTreeView::mouseReleaseEvent ( QMouseEvent *event )
{
    __super::mouseReleaseEvent ( event );
    if ( event->button( ) == Qt::RightButton )
    {
        //CXASSERT ( 0 );
        //CreatePopupMenu();

    }
}

void EObjListSheetTreeView::SetPopupMenu ( QMenu* menu )
{
    mPopupMenu = menu;
}
bool EObjListSheetTreeView::event ( QEvent* event )
{
    switch ( event->type() )
    {
    case QEvent::ContextMenu:
    {
        QContextMenuEvent* menuEvent = ( QContextMenuEvent* ) event;
        //mPopupMenu->exec(menuEvent->pos());
        mPopupMenu->exec (menuEvent->globalPos() );
    }
    break;
    }
    return __super::event ( event );
}
