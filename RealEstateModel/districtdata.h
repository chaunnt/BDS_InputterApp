#ifndef DISTRICTDATA_H
#define DISTRICTDATA_H

#include <QObject>
#include "globaldefine.h"

class DistrictData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY DistrictDataChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY DistrictDataChanged)
    Q_PROPERTY(int parentId READ getParentid WRITE setParentid NOTIFY DistrictDataChanged)
    Q_PROPERTY(bool active READ getActive WRITE setActive NOTIFY DistrictDataChanged)


    int m_id = 0;
    QString m_name = DEFAULT_TEXT;
    int m_parentId = 0;
    bool m_active = true;

public:
    explicit DistrictData(QObject *parent = nullptr);
    int getId();
    QString getName();
    int getParentid();
    bool getActive();
    void setId(int newValue);
    void setName(QString newValue);
    void setParentid(int newValue);
    void setActive(bool newValue);


signals:
    void DistrictDataChanged();

public slots:
};

#endif // DISTRICTDATA_H
