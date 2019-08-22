#include "dbcommunicator.h"

DBCommunicator::DBCommunicator(QObject *parent) : QObject(parent)
{   
    //Initialize target page database
    QSqlDatabase::database(DBCON_DATA_MANAGEMENT, false).close();
    QSqlDatabase::removeDatabase(DBCON_DATA_MANAGEMENT);
    m_dbBDSData = QSqlDatabase::addDatabase(DBTYPE, DBCON_DATA_MANAGEMENT);
    m_dbBDSData.setDatabaseName(DBFILENAME_DATA_MANAGEMENT);
    if(m_dbBDSData.isOpen() || m_dbBDSData.open()){
        if(!m_dbBDSData.tables().contains(DBTBL_BDS_DATA)){
            QSqlQuery query("", m_dbBDSData);
            query.exec("create table " + DBTBL_BDS_DATA + " (data varchar)");
        }
    }else{
        qDebug() << "Can not create database";
    }
    qDebug() << DBCON_DATA_MANAGEMENT;
}

bool DBCommunicator::addBDSData(QString strData)
{
    if(m_dbBDSData.isOpen() || m_dbBDSData.open()){
        if(!m_dbBDSData.tables().contains(DBTBL_BDS_DATA)){
            qDebug() << "create new table";
            QSqlQuery query("", m_dbBDSData);
            query.exec("create table " + DBTBL_BDS_DATA + " (messageContent varchar, messageDate varchar, phonenumber varchar,  messageStatus varchar)");
        }

        QSqlQuery query ("",m_dbBDSData);
        query.prepare("INSERT INTO " + DBTBL_BDS_DATA + " (data) VALUES (:data)");
        query.bindValue(":data", strData);
        if(!query.exec()){
            qDebug() << "insert failed: " << query.lastError().text() ;
            return false;
        }
    }else{
        qDebug() << "Can not create database";
        return false;
    }
    return true;
}

bool DBCommunicator::updateBDSData(QString strData, QString index)
{
//    if(m_dbBDSData.isOpen() || m_dbBDSData.open()){
//        if(!m_dbBDSData.tables().contains(DBTBL_BDS_DATA)){
//            return addBDSData(strData);
//        }

//        QSqlQuery query ("",m_dbBDSData);
//        query.prepare("UPDATE " + DBTBL_BDS_DATA + " SET data = :data WHERE ID = :index");
//        query.bindValue(":data", strData);
//        query.bindValue(":index", index);
//        if(!query.exec()){
//            qDebug() << "insert failed: " << query.lastError().text() ;
//            return false;
//        }
//    }else{
//        qDebug() << "Can not create database";
//        return false;
//    }
    return true;
}

QList<QObject *> DBCommunicator::loadAllBDSData()
{
    qDebug() << Q_FUNC_INFO;
    QList<QObject *> lstBDS;
    if(m_dbBDSData.isOpen() || m_dbBDSData.open()){
        if(m_dbBDSData.tables().contains(DBTBL_BDS_DATA)){
            QString selectQuery = "SELECT * FROM " + DBTBL_BDS_DATA ;
            QSqlQuery query(selectQuery, m_dbBDSData);
            if(query.exec()){
                QJsonDocument jsDoc;
                QSqlRecord record = query.record();
                int nColData = record.indexOf("data");
                while(query.next()){
                    QJsonDocument jsTempDoc;
                    QString strTempData = query.value(nColData).toString();
                    QByteArray arrayResponse = strTempData.toUtf8();
                    QJsonDocument JSdoc = QJsonDocument::fromJson(arrayResponse);
                    BDSData* newBDS= new BDSData();
                    newBDS->importFromJsonObj(JSdoc.object());
                    lstBDS.append(newBDS);
                }
            }else{
                qDebug() << "Load data from database failed";
                qDebug() << "result: " << query.lastError().text();
            }
        }else{
            qDebug() << DBTBL_BDS_DATA << " do not exist";
        }
    }else{
        qDebug() << "Can not open database";
    }

    m_dbBDSData.close();
    return lstBDS;
}

