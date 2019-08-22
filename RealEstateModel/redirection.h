#ifndef REDIRECTION_H
#define REDIRECTION_H

#include <QObject>
#include "simpledata.h"

class REDirection : public SimpleData
{
public:
    explicit REDirection(QObject *parent = nullptr);
    REDirection(int nTypeID, QString strTypeName);
};

#endif // REDIRECTION_H
