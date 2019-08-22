#ifndef RELOCATIONTYPE_H
#define RELOCATIONTYPE_H

#include <QObject>
#include "simpledata.h"

class RELocationType : public SimpleData
{
    Q_OBJECT
public:
    explicit RELocationType(QObject *parent = nullptr);
    RELocationType(int nTypeID, QString strTypeName);
signals:

public slots:
};

#endif // RELOCATIONTYPE_H
