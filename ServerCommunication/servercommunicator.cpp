#include "servercommunicator.h"
#include <QFileInfo>

static QString API_GET_PROVINCE = "/Location/GetProvinces";
static QString API_GET_DISTRICT = "/Location/GetDistrictsInProvince";
static QString API_GET_LOOKUP_DATA = "/RealEstate/GetLookupDatas";
static QString API_GET_REAL_ESTATE_BY_ID = "/RealEstate/GetById";
static QString API_ADD_REAL_ESTATE = "/RealEstate/AddRealEstate";
static QString API_UPDATE_REAL_ESTATE = "/RealEstate/UpdateRealEstate";
static QString API_GET_REAL_ESTATE_WITH_FILTER = "/RealEstate/GetRealEstatesWithFilter";
static QString PARAM_PROVINCE_ID = "provinceId=";
static QString PARAM_USER_ID = "id=";
static QString FILTER = "{\"ItemsPerPage\": %1},\"PageNumber\": %2";
ServerCommunicator::ServerCommunicator(QObject *parent) : QObject(parent)
{
    m_serverAccessManager = new QNetworkAccessManager;
    connect(m_serverAccessManager, &QNetworkAccessManager::finished, this, &ServerCommunicator::serverResponse);
}

void ServerCommunicator::getAllAssignedProvince()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    QUrl url = QUrl(CLOUD_HOST_NHA_DAT + API_GET_PROVINCE + PARAM_MARK + PARAM_TOKENKEY + TokenKey);
    QNetworkRequest request;

    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    executeGETrequest(request);
}

void ServerCommunicator::getAllAssignedDistrict(int nProvinceId)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    QUrl url = QUrl(CLOUD_HOST_NHA_DAT + API_GET_DISTRICT + PARAM_MARK + PARAM_PROVINCE_ID + QString::number(nProvinceId) + AND + PARAM_TOKENKEY + TokenKey);
    QNetworkRequest request;

    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    executeGETrequest(request);
}

QByteArray ServerCommunicator::getAllBDSDataFromServer(int nItemsPerPage, int nPageNumber,bool bWaiting)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    QUrl url = QUrl(CLOUD_HOST_NHA_DAT + API_GET_REAL_ESTATE_WITH_FILTER + PARAM_MARK + PARAM_TOKENKEY + TokenKey);
    QNetworkRequest request;

    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray filterData = FILTER.arg(nItemsPerPage).arg(nPageNumber).toUtf8();
//    qDebug() << filterData;
    return executePOSTrequest(request, filterData, bWaiting);
}

QByteArray ServerCommunicator::getBDSDataFromServerWithID(int strID)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    QUrl url = QUrl(CLOUD_HOST_NHA_DAT + API_GET_REAL_ESTATE_BY_ID + PARAM_MARK + PARAM_USER_ID + QString::number(strID) + AND + PARAM_TOKENKEY + TokenKey);
    QNetworkRequest request;

    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return executeGETrequest(request, true);
}

void exportJson(QString strFileName, QJsonDocument jsDoc)
{
    QFile file(strFileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << jsDoc.toJson();
    file.close();
}

QByteArray ServerCommunicator::submitBDSData(QJsonObject submitData)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    QUrl url = QUrl(CLOUD_HOST_NHA_DAT + API_ADD_REAL_ESTATE + PARAM_MARK + PARAM_TOKENKEY + TokenKey);
    QNetworkRequest request;

    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QByteArray responseData = executePOSTrequest(request, QJsonDocument(submitData).toJson(), true);
    return responseData;
}

QByteArray ServerCommunicator::updateBDSData(QJsonObject submitData)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    QUrl url = QUrl(CLOUD_HOST_NHA_DAT + API_UPDATE_REAL_ESTATE + PARAM_MARK + PARAM_TOKENKEY + TokenKey);
    QNetworkRequest request;

    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject tempCreatedBy;
    tempCreatedBy[c_NHADATVN_Id] = 0;
    tempCreatedBy[c_NHADATVN_FullName] = c_NHADATVN_FullName;
    tempCreatedBy[c_NHADATVN_Email] = c_NHADATVN_Email;
    tempCreatedBy[c_NHADATVN_Phone] = c_NHADATVN_Phone;
    tempCreatedBy[c_NHADATVN_Address] = c_NHADATVN_Address;
    submitData["CreatedBy"] = tempCreatedBy;

    QByteArray responseData = executePOSTrequest(request, QJsonDocument(submitData).toJson(), true);
    return responseData;
}

QByteArray ServerCommunicator::uploadImage(QString newFileName)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    QFile newFile(newFileName);
    QUrl url = QUrl(FTP_HOST + QFileInfo(newFile).fileName());
    url.setUserName("admin_testftp");    // Set login
    url.setPassword("6o7A0T8HLT"); // Set пароль
    url.setPort(21);             // Protocol port, which we will work on

    QByteArray responseData;
    if(!newFile.open(QFile::ReadOnly)){
    }else{
        responseData = executePUTrequest(QNetworkRequest(url), newFile.readAll());
        newFile.close();
    }

    return responseData;
}

QByteArray ServerCommunicator::getLookupDatas()
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    QUrl url = QUrl(CLOUD_HOST_NHA_DAT + API_GET_LOOKUP_DATA + PARAM_MARK + PARAM_TOKENKEY + TokenKey);
    QNetworkRequest request;

    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return executeGETrequest(request, true);
}

QByteArray ServerCommunicator::executeGETrequest(QNetworkRequest newRequest, bool isHaveToWait)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    QByteArray responseData;
    if(isHaveToWait){
        QNetworkAccessManager tempNamLogin;
        QNetworkReply* newResponse = tempNamLogin.get(newRequest);
        QEventLoop tempLoop;
        connect(&tempNamLogin, SIGNAL(finished(QNetworkReply*)), &tempLoop, SLOT(quit()));
        tempLoop.exec();
        responseData = newResponse->readAll();

    }else{
        m_serverAccessManager->get(newRequest);
    }
    return responseData;
}

QByteArray ServerCommunicator::executePOSTrequest(QNetworkRequest newRequest, QByteArray newBodyData, bool isHaveToWait)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    QByteArray responseData;
    if(isHaveToWait){
        QNetworkAccessManager tempNamLogin;
        QNetworkReply* newResponse = tempNamLogin.post(newRequest, newBodyData);
        QEventLoop tempLoop;
        connect(&tempNamLogin, SIGNAL(finished(QNetworkReply*)), &tempLoop, SLOT(quit()));
        tempLoop.exec();
        responseData = newResponse->readAll();
    }else{
        m_serverAccessManager->post(newRequest, newBodyData);
    }
    return responseData;
}

QByteArray ServerCommunicator::executePUTrequest(QNetworkRequest newRequest, QByteArray newBodyData, bool isHaveToWait)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
    qDebug() << newBodyData.length();
#endif

    QByteArray responseData;
    if(isHaveToWait){
        QNetworkAccessManager tempNamLogin;
        QNetworkReply* newResponse = tempNamLogin.put(newRequest, newBodyData);
        QEventLoop tempLoop;
        connect(&tempNamLogin, SIGNAL(finished(QNetworkReply*)), &tempLoop, SLOT(quit()));
        tempLoop.exec();
        responseData = newResponse->readAll();
    }else{
        m_serverAccessManager->put(newRequest, newBodyData);
    }

    return responseData;
}

void ServerCommunicator::serverResponse(QNetworkReply *newResponse)
{
#ifdef DEBUG_MODE
    qDebug() << Q_FUNC_INFO;
#endif
    if(newResponse->error() == QNetworkReply::NoError){
        QString responseUrl = newResponse->request().url().toString();

        if(responseUrl.contains(API_GET_PROVINCE)){
            emit getAllAssignedProvinceResponsed(newResponse);

        }else if(responseUrl.contains(API_GET_DISTRICT)){
            emit getAllAssignedDistrictResponsed(newResponse);

        }else if(responseUrl.contains(API_GET_LOOKUP_DATA)){
            emit getLookupDatasResponsed(newResponse);

        }else if(responseUrl.contains(API_GET_REAL_ESTATE_WITH_FILTER)){
            emit getAllBDSDataFromServerResponsed(newResponse);

        }else if(responseUrl.contains(API_ADD_REAL_ESTATE)){
            emit submitBDSDataResponsed(newResponse);

        }else if(responseUrl.contains(API_UPDATE_REAL_ESTATE)){
            emit updateBDSDataResponsed(newResponse);

        }else{
            emit requestFinished(newResponse);
        }
    }else{
        emit requestError(newResponse);
    }
}


