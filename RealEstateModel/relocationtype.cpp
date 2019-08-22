#include "relocationtype.h"

RELocationType::RELocationType(QObject *parent) : SimpleData(parent)
{

}

RELocationType::RELocationType(int nTypeID, QString strTypeName)
{
    setDataId(nTypeID);
    setDataName(strTypeName);
}
