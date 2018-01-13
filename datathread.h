#ifndef DATATHREAD_H
#define DATATHREAD_H

#include <QObject>
#include <QThread>
#include "stdafx.h"

class DataThread : public QThread
{
    Q_OBJECT
public:
    DataThread();
    ~DataThread();

    void run();
};

#endif // DATATHREAD_H
