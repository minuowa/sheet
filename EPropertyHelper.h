#pragma once
#include "..\src\gui\widgets\qspinbox.h"
#include "..\src\gui\widgets\qcheckbox.h"
#include "..\src\gui\widgets\qlineedit.h"
#include <string>
namespace EPropertyHelper
{
    bool WriteProperty ( void*& data,QSpinBox* editor );
    bool WriteProperty ( void*& data,QLineEdit* editor );
    bool WriteProperty ( void*& data,QCheckBox* editor );

    template<typename T>
    bool WriteProperty ( void*& data,QDoubleSpinBox* editor )
    {
        * ( ( T* ) data ) =editor->value();
        return true;
    }
};

