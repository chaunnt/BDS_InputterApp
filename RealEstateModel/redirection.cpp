#include "redirection.h"

REDirection::REDirection(QObject *parent) : SimpleData(parent)
{

}

REDirection::REDirection(int nTypeID, QString strTypeName)
{
    setDataId(nTypeID);
    setDataName(strTypeName);
}
