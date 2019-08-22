#ifndef SERVERCOMMUNICATOR_H
#define SERVERCOMMUNICATOR_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QFile>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include "globaldefine.h"
#include "RealEstateModel/bdsdata.h"

class ServerCommunicator : public QObject
{
    Q_OBJECT
public:
    QString TokenKey = "";
    explicit ServerCommunicator(QObject *parent = nullptr);
    QNetworkAccessManager* m_serverAccessManager;

    void getAllAssignedProvince();
    void getAllAssignedDistrict(int nProvinceId);
    QByteArray getAllBDSDataFromServer(int nItemsPerPage = 20, int nPageNumber = 0, bool bWaiting = false);
    QByteArray getBDSDataFromServerWithID(int strID);
    QByteArray submitBDSData(QJsonObject submitData);
    QByteArray updateBDSData(QJsonObject submitData);
    QByteArray uploadImage(QString newFileName);
    QByteArray getLookupDatas();
signals:
    void getAllAssignedProvinceResponsed(QNetworkReply* newResponse);
    void getAllAssignedDistrictResponsed(QNetworkReply* newResponse);
    void getAllBDSDataFromServerResponsed(QNetworkReply* newResponse);
    void getLookupDatasResponsed(QNetworkReply* newResponse);
    void submitBDSDataResponsed(QNetworkReply* newResponse);
    void updateBDSDataResponsed(QNetworkReply* newResponse);
    void requestFinished(QNetworkReply* newResponse);
    void requestError(QNetworkReply* newResponse);
private slots:
    void serverResponse(QNetworkReply* newResponse);
private:
    QByteArray executeGETrequest(QNetworkRequest newRequest, bool isHaveToWait = false);
    QByteArray executePOSTrequest(QNetworkRequest newRequest, QByteArray newBodyData, bool isHaveToWait = false);
    QByteArray executePUTrequest(QNetworkRequest newRequest, QByteArray newBodyData, bool isHaveToWait = false);
};

#endif // SERVERCOMMUNICATOR_H
