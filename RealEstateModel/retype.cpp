#include "retype.h"

REType::REType(QObject *parent) : SimpleData(parent)
{

}

REType::REType(int nTypeID, QString strTypeName)
{
    setDataId(nTypeID);
    setDataName(strTypeName);
}
