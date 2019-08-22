#ifndef WARDDATA_H
#define WARDDATA_H

#include <QObject>
#include "globaldefine.h"

class WardData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY WardDataChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY WardDataChanged)
    Q_PROPERTY(int parentId READ getParentid WRITE setParentid NOTIFY WardDataChanged)
    Q_PROPERTY(bool active READ getActive WRITE setActive NOTIFY WardDataChanged)

    int m_id = 0;
    QString m_name = DEFAULT_TEXT;
    int m_parentId = 0;
    bool m_active = true;

public:
    explicit WardData(QObject *parent = nullptr);
    int getId();
    QString getName();
    int getParentid();
    bool getActive();
    void setId(int newValue);
    void setName(QString newValue);
    void setParentid(int newValue);
    void setActive(bool newValue);


signals:
    void WardDataChanged();

public slots:
};

#endif // WARDDATA_H
