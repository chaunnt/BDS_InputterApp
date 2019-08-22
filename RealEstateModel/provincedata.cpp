#include "provincedata.h"

ProvinceData::ProvinceData(QObject *parent) : QObject(parent)
{

}

ProvinceData::ProvinceData(int nID, QString strName, int nParentID, bool bActive)
{
    m_id = nID;
    m_name = strName;
    m_parentId = nParentID;
    m_active = bActive;
}

void ProvinceData::setId(int newValue)
{
    if(m_id != newValue){
        m_id= newValue;
    }
}
void ProvinceData::setName(QString newValue)
{
    if(m_name != newValue){
        m_name= newValue;
    }
}
void ProvinceData::setParentid(int newValue)
{
    if(m_parentId != newValue){
        m_parentId= newValue;
    }
}
void ProvinceData::setActive(bool newValue)
{
    if(m_active != newValue){
        m_active= newValue;
    }
}

int ProvinceData::getId()
{
    return m_id;
}
QString ProvinceData::getName()
{
    return m_name;
}
int ProvinceData::getParentid()
{
    return m_parentId;
}
bool ProvinceData::getActive()
{
    return m_active;
}
