#ifndef PROVINCEDATA_H
#define PROVINCEDATA_H

#include <QObject>
#include "globaldefine.h"

class ProvinceData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY ProvinceDataChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY ProvinceDataChanged)
    Q_PROPERTY(int parentId READ getParentid WRITE setParentid NOTIFY ProvinceDataChanged)
    Q_PROPERTY(bool active READ getActive WRITE setActive NOTIFY ProvinceDataChanged)

    int m_id = 0;
    QString m_name = DEFAULT_TEXT;
    int m_parentId = 0;
    bool m_active = true;

public:
    explicit ProvinceData(QObject *parent = nullptr);
    ProvinceData(int nID, QString strName, int nParentID, bool bActive);
signals:
    void ProvinceDataChanged();

public slots:
    int getId();
    QString getName();
    int getParentid();
    bool getActive();

    void setId(int newValue);
    void setName(QString newValue);
    void setParentid(int newValue);
    void setActive(bool newValue);

};

#endif // PROVINCEDATA_H
