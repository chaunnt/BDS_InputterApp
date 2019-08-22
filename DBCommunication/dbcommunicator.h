#ifndef DBCOMMUNICATOR_H
#define DBCOMMUNICATOR_H

#include <QObject>
#include <QDebug>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlResult>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include "globaldefine.h"
#include "RealEstateModel/bdsdata.h"

class DBCommunicator : public QObject
{
    Q_OBJECT
    QSqlDatabase m_dbBDSData;
public:
    explicit DBCommunicator(QObject *parent = nullptr);

    bool addBDSData(QString strData);
    bool updateBDSData(QString strData, QString index);
    QList<QObject*> loadAllBDSData();
signals:

public slots:
};

#endif // DBCOMMUNICATOR_H
