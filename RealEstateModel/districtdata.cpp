#include "districtdata.h"

DistrictData::DistrictData(QObject *parent) : QObject(parent)
{

}

void DistrictData::setId(int newValue)
{
    if(m_id != newValue){
        m_id= newValue;
    }
}
void DistrictData::setName(QString newValue)
{
    if(m_name != newValue){
        m_name= newValue;
    }
}
void DistrictData::setParentid(int newValue)
{
    if(m_parentId != newValue){
        m_parentId= newValue;
    }
}
void DistrictData::setActive(bool newValue)
{
    if(m_active != newValue){
        m_active= newValue;
    }
}

int DistrictData::getId()
{
    return m_id;
}
QString DistrictData::getName()
{
    return m_name;
}
int DistrictData::getParentid()
{
    return m_parentId;
}
bool DistrictData::getActive()
{
    return m_active;
}
