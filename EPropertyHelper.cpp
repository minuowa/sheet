#include "EPropertyHelper.h"
#include "GObject.h"

bool EPropertyHelper::WriteProperty ( void*& data,QSpinBox* editor )
{
    * ( ( int* ) data ) =editor->value();
    return true;
}

//bool EPropertyHelper::WriteProperty( void*& data,QDoubleSpinBox* editor )
//{
//	*((double*)data)=editor->value();
//	return true;
//}

bool EPropertyHelper::WriteProperty ( void*& data,QLineEdit* editor )
{
    EPropertyString& str=* ( ( EPropertyString* ) data );
    str=editor->text().toStdString();
    return true;
}

bool EPropertyHelper::WriteProperty ( void*& data,QCheckBox* editor )
{
    * ( ( bool* ) data ) =editor->checkState() ==Qt::Checked;
    return true;
}
