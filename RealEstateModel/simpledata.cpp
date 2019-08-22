#include "simpledata.h"
#include <QDebug>

SimpleData::SimpleData(QObject *parent) : QObject(parent)
{

}

SimpleData::SimpleData(int nDataID, QString strDataName, QString strDisplayName, int nParentID)
{
    m_dataId = nDataID;
    m_dataDisplayName = strDisplayName;
    m_dataName = strDataName;
    m_dataParentId = nParentID;
}

int SimpleData::dataId()
{
    return m_dataId;
}

QString SimpleData::dataName()
{
    return m_dataName;
}

QString SimpleData::dataDisplayName()
{
    return m_dataDisplayName;
}

int SimpleData::dataParentId()
{
    return m_dataParentId;
}

void SimpleData::setDataId(int newValue)
{
    if(m_dataId != newValue){
        m_dataId= newValue;
        emit dataChanged();
    }
}

void SimpleData::setDataName(QString newValue)
{
    if(m_dataName != newValue){
        m_dataName= newValue;
        emit dataChanged();
    }
}

void SimpleData::setDataParentId(int newValue)
{
    if(m_dataParentId != newValue){
        m_dataParentId= newValue;
        emit dataChanged();
    }
}

void SimpleData::setDataDisplayName(QString newValue)
{
    if(m_dataDisplayName != newValue){
        m_dataDisplayName= newValue;
        emit dataChanged();
    }
}

QString SimpleData::convertToJSON()
{
    return QJsonDocument(convertToJSONObject()).toJson();
}

QJsonObject SimpleData::convertToJSONObject()
{
    QJsonObject jsObj;
    if (m_dataId != DEFAULT_INT_VALUE){
        jsObj[c_NHADATVN_Id] = m_dataId;
    }

    if (m_dataParentId != DEFAULT_INT_VALUE){
        jsObj[c_NHADATVN_ParentId] = m_dataParentId;
    }

    if (m_dataName != DEFAULT_TEXT){
        jsObj[c_NHADATVN_Name] = m_dataName;
    }

    if (m_dataDisplayName != DEFAULT_TEXT){
        jsObj[c_NHADATVN_DisplayName] = m_dataDisplayName;
    }
    return jsObj;
}

void SimpleData::importFromJSON(QString strData)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
    qDebug() << strData;
#endif

    QJsonDocument jsDoc = QJsonDocument::fromJson(strData.toUtf8());

    if (!jsDoc.object().value(c_NHADATVN_Id).isNull()
            && !jsDoc.object().value(c_NHADATVN_Id).isUndefined()
            && jsDoc.object().value(c_NHADATVN_Id).toInt() != DEFAULT_INT_VALUE)
    {
        m_dataId = jsDoc.object().value(c_NHADATVN_Id).toInt();
    }

    if (!jsDoc.object().value(c_NHADATVN_ParentId).isNull()
            && !jsDoc.object().value(c_NHADATVN_ParentId).isUndefined()
            && jsDoc.object().value(c_NHADATVN_ParentId).toInt() != DEFAULT_INT_VALUE)
    {
        m_dataParentId = jsDoc.object().value(c_NHADATVN_ParentId).toInt();
    }

    if (!jsDoc.object().value(c_NHADATVN_Name).isNull()
            && !jsDoc.object().value(c_NHADATVN_Name).isUndefined()
            && jsDoc.object().value(c_NHADATVN_Name).toString() != DEFAULT_TEXT)
    {
        m_dataName = jsDoc.object().value(c_NHADATVN_Name).toString();
    }

    if (!jsDoc.object().value(c_NHADATVN_DisplayName).isNull()
            && !jsDoc.object().value(c_NHADATVN_DisplayName).isUndefined()
            && jsDoc.object().value(c_NHADATVN_DisplayName).toString() != DEFAULT_TEXT)
    {
        m_dataDisplayName = jsDoc.object().value(c_NHADATVN_DisplayName).toString();
    }
}

void SimpleData::importFromJSON(QJsonObject jsObj)
{
    if (!jsObj.value(c_NHADATVN_Id).isNull()
            && !jsObj.value(c_NHADATVN_Id).isUndefined()
            && jsObj.value(c_NHADATVN_Id).toInt() != DEFAULT_INT_VALUE)
    {
        m_dataId = jsObj.value(c_NHADATVN_Id).toInt();
    }

    if (!jsObj.value(c_NHADATVN_ParentId).isNull()
            && !jsObj.value(c_NHADATVN_ParentId).isUndefined()
            && jsObj.value(c_NHADATVN_ParentId).toInt() != DEFAULT_INT_VALUE)
    {
        m_dataParentId = jsObj.value(c_NHADATVN_ParentId).toInt();
    }

    if (!jsObj.value(c_NHADATVN_Name).isNull()
            && !jsObj.value(c_NHADATVN_Name).isUndefined()
            && jsObj.value(c_NHADATVN_Name).toString() != DEFAULT_TEXT)
    {
        m_dataName = jsObj.value(c_NHADATVN_Name).toString();
    }

    if (!jsObj.value(c_NHADATVN_DisplayName).isNull()
            && !jsObj.value(c_NHADATVN_DisplayName).isUndefined()
            && jsObj.value(c_NHADATVN_DisplayName).toString() != DEFAULT_TEXT)
    {
        m_dataDisplayName = jsObj.value(c_NHADATVN_DisplayName).toString();
    }
}

int SimpleData::getDataPoint()
{
    return 0;
}
