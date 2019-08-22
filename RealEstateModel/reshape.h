#ifndef REHINHDANG_H
#define REHINHDANG_H

#include <QObject>
#include "simpledata.h"

class REShape : public SimpleData
{
    Q_OBJECT

public:
    explicit REShape(QObject *parent = nullptr);
    REShape(int nTypeID, QString strTypeName);

signals:

public slots:

};

#endif // REHINHDANG_H
