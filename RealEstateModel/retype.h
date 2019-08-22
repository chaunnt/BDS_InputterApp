#ifndef RETYPE_H
#define RETYPE_H

#include <QObject>
#include "simpledata.h"

class REType : public SimpleData
{
    Q_OBJECT

public:
    explicit REType(QObject *parent = nullptr);
    REType(int nTypeID, QString strTypeName);

signals:

public slots:
};

#endif // RETYPE_H
