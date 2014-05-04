#ifndef EDITORSHEETEVENT_H
#define EDITORSHEETEVENT_H

#include <QObject>
#include "..\src\gui\itemviews\qitemselectionmodel.h"
#include "XSingleton.h"

class QAction;
class EEditorEventAgent : public QObject
{
	Q_OBJECT

public:
	EEditorEventAgent();
	~EEditorEventAgent();

	public slots:
		void onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
		void onAddObjectAction ( QAction* );
		void onComponentAction ( QAction* );
public:
	
};
#define EditorEventAgent CXSingleton<EEditorEventAgent>::GetSingletonPtr()
#endif // EDITORSHEETEVENT_H
