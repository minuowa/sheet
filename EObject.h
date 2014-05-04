#pragma once
#include "XString.h"
#include "XMap.h"
#include "qvariant.h"
#include "qtcore\qnamespace.h"
#include "propertysheet_global.h"
#include "XMultimap.h"
using namespace Qt;

typedef CharString EPropertyString;

#define DeclareCategoryName(className)\
		public:\
		virtual const char* CategoryName() const\
{\
	return #className;\
}\
 
struct PROPERTYSHEET_EXPORT EPropertyVar
{
    void* Ptr;
    EPropertyString CategoryName;
    QVariant QVar;
    void ToString ( std::string& str );
    EPropertyVar();
};
typedef CXMap<EPropertyString, EPropertyVar*> PropertyMap;
typedef CXMap<EPropertyString, PropertyMap*> CategoryPropertyMap;
class PROPERTYSHEET_EXPORT MObject
{
    DeclareCategoryName ( MObject );
public:
    MObject ( void );
    ~MObject ( void );
public:
    template<typename T>
    void RegisterProperty ( const char* categoryName, const char* propName, const T& var )
    {
        PropertyMap* propMap = 0;
        if ( !mOption.Get ( categoryName, propMap ) )
        {
            propMap = new PropertyMap;
            mOption.Insert ( categoryName, propMap );
        }

        EPropertyVar* evar = 0;
        if ( !propMap->Get ( propName, evar ) )
        {
            EPropertyVar* evar = new EPropertyVar;
            evar->QVar = QVariant ( var );
            evar->Ptr = ( void* ) &var;
            propMap->Insert ( propName, evar );
            evar->CategoryName = categoryName;
        }
        else
        {
            assert ( 0 && "already exist property" );
        }
    }
    template<>
    void RegisterProperty ( const char* categoryName, const char* propName, const EPropertyString& var )
    {
		PropertyMap* propMap = 0;
		if ( !mOption.Get ( categoryName, propMap ) )
		{
			propMap = new PropertyMap;
			mOption.Insert ( categoryName, propMap );
		}

		EPropertyVar* evar = 0;
		if ( !propMap->Get ( propName, evar ) )
		{
			EPropertyVar* evar = new EPropertyVar;
			evar->QVar = QVariant ( var.c_str() );
			evar->Ptr = ( void* ) &var;
			propMap->Insert ( propName, evar );
			evar->CategoryName = categoryName;
		}
		else
		{
			assert ( 0 && "already exist property" );
		}
    }
    virtual void RegisterAll();
    const CategoryPropertyMap& GetPropertyMap() const
    {
        return mOption;
    }
    CategoryPropertyMap& GetPropertyMap()
    {
        return mOption;
    }
protected:
    EPropertyString	mNodeName;
    int	mID;
    CategoryPropertyMap mOption;
public:
    bool IsRegisterAll()
    {
        return mOption.size();
    }
    const EPropertyString& GetObjectName() const
    {
        return mNodeName;
    }
};


#define __RegisterProperty(mem) RegisterProperty(CategoryName(),#mem,mem)
