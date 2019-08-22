#include "warddata.h"

WardData::WardData(QObject *parent) : QObject(parent)
{

}

void WardData::setId(int newValue)
{
    if(m_id != newValue){
        m_id= newValue;
    }
}
void WardData::setName(QString newValue)
{
    if(m_name != newValue){
        m_name= newValue;
    }
}
void WardData::setParentid(int newValue)
{
    if(m_parentId != newValue){
        m_parentId= newValue;
    }
}
void WardData::setActive(bool newValue)
{
    if(m_active != newValue){
        m_active= newValue;
    }
}

int WardData::getId()
{
    return m_id;
}
QString WardData::getName()
{
    return m_name;
}
int WardData::getParentid()
{
    return m_parentId;
}
bool WardData::getActive()
{
    return m_active;
}
