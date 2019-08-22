#include "imagedata.h"
#include <QDebug>

ImageData::ImageData(QObject *parent) : QObject(parent)
{

}

ImageData::ImageData(QString strImgId, QString strImgPath, QString strImgPreview)
{
    m_imageId = strImgId;
    m_imagePath = strImgPath;
    m_imagePreview = strImgPreview;
}

QString ImageData::getImageId()
{
    return m_imageId;
}

QString ImageData::getImagePath()
{
    return m_imagePath;
}

QString ImageData::getImagePreview()
{
    return m_imagePreview;
}

QString ImageData::getImageType()
{
    return m_imageType;
}

QString ImageData::getImageUrl()
{
    return m_imageUrl;
}

QString ImageData::getImageSrc()
{
    if (m_imagePreview != ""){
        return m_imagePreview;
    }else if (m_imagePath != ""){
        return m_imagePath;
    }else if (m_imageUrl != ""){
        return m_imageUrl;
    }
    return "";
}


void ImageData::setImageId(QString newVal)
{
    m_imageId = newVal;
    emit imageDataChanged();
}

void ImageData::setImagePath(QString newVal)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    m_imagePath = newVal;
    emit imageDataChanged();
}

void ImageData::setImagePreview(QString newVal)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    m_imagePreview = newVal;
    emit imageDataChanged();
}

void ImageData::setImageType(QString newVal)
{
    m_imageType = newVal;
    emit imageDataChanged();
}

void ImageData::setImageUrl(QString newVal)
{
    m_imageUrl = newVal;
    emit imageDataChanged();
}

void ImageData::importFromJSON(QByteArray jsonData)
{
    QJsonObject jsObj = QJsonDocument::fromJson(jsonData).object();
    importFromJSONObject(jsObj);
}

void ImageData::importFromJSONObject(QJsonObject jsObj)
{
    m_imageUrl = jsObj.value(c_NHADATVN_Link).toString();
    int tempimageType = jsObj.value(c_NHADATVN_Type).toInt();
    if (tempimageType == 1){
        m_imageType = c_NHADATVN_IMAGE_TYPE_JURIDICAL;
    }else if(tempimageType == 2){
        m_imageType = c_NHADATVN_IMAGE_TYPE_HOUSE;
    }else if(tempimageType == 3){
        m_imageType = c_NHADATVN_IMAGE_TYPE_LANDPLANNING;
    }
    m_imageId = QString::number(jsObj.value(c_NHADATVN_Id).toInt());
}

QString ImageData::convertToJSON()
{
    return QJsonDocument(convertToJSONObject()).toJson();
}

QJsonObject ImageData::convertToJSONObject()
{
    QJsonObject jsObj;
    if (m_imageId != DEFAULT_INT_VALUE){
        jsObj[c_NHADATVN_Id] = m_imageId;
    }

    if (m_imageType != DEFAULT_TEXT){
        if(m_imageType == c_NHADATVN_IMAGE_TYPE_JURIDICAL){
            jsObj[c_NHADATVN_Type] = 1;
        }else if(m_imageType == c_NHADATVN_IMAGE_TYPE_LANDPLANNING){
            jsObj[c_NHADATVN_Type] = 3;
        }else{
            jsObj[c_NHADATVN_Type] = 2;
        }
    }

    if (m_imageUrl != DEFAULT_TEXT){
        jsObj[c_NHADATVN_Link] = m_imageUrl;
    }

    return jsObj;
}


