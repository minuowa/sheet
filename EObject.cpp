#include "EObject.h"

int gCount = 0;
MObject::MObject ( void )
{
    mNodeName.clear();
    mNodeName.Format ( "MObject%d", gCount );

    gCount++;
}


MObject::~MObject ( void )
{
}

void MObject::RegisterAll()
{
	RegisterProperty ( "MObject", "mEObjectName", mNodeName );
    RegisterProperty ( "MObject", "mID", mID );
    //__RegisterProperty(mEObjectName);
}

EPropertyVar::EPropertyVar()
    : Ptr ( 0 )
{

}
static const int BufferSize = 1024;
char gCharBuffer[BufferSize];
void EPropertyVar::ToString ( std::string& str )
{
    CXMemoryZeroArray ( gCharBuffer );

    switch ( QVar.type() )
    {
    case QVariant::Bool:
    {
        str = QVar.toBool() ? "true" : "false";
    }
    break;
    case QVariant::Int:
    {
        sprintf ( gCharBuffer, "%d", QVar.toInt() );
        str.assign ( gCharBuffer );
    }
    break;
    case QVariant::Double:
    case QMetaType::Float:
    {
        sprintf ( gCharBuffer, "%.f", QVar.toFloat() );
        str.assign ( gCharBuffer );
    }
    break;
    case QVariant::String:
    {
        str = QVar.toString().toStdString();
    }
    break;
    default:
    {
        CXASSERT ( 0 );
    }
    break;
    }
}
