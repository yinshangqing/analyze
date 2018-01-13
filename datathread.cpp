#include "datathread.h"

//extern COMMAND com;

DataThread::DataThread()
{

}

DataThread::~DataThread()
{

}

void DataThread::run()
{
    while(1)
    {
        if(com.run)
        msleep(20);
    }
}

