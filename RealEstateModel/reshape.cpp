#include "reshape.h"

REShape::REShape(QObject *parent) : SimpleData(parent)
{

}

REShape::REShape(int nTypeID, QString strTypeName)
{
    setDataId(nTypeID);
    setDataName(strTypeName);
}

