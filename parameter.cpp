#include "parameter.h"

Parameter *Parameter::m_instance = NULL;

Parameter::Parameter(QDialog *parent)
    : QDialog(parent)
{

}

Parameter::~Parameter()
{

}

Parameter *Parameter::Instance()
{
    if(m_instance == NULL)
        m_instance = new Parameter;
    return m_instance;
}

