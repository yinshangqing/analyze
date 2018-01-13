#ifndef PARAMETER_H
#define PARAMETER_H

#include <QWidget>
#include <QDialog>

class Parameter : public QDialog
{
    Q_OBJECT
public:
    explicit Parameter(QDialog *parent = 0);
    ~Parameter();
    static Parameter *m_instance;
    static Parameter *Instance();

signals:

public slots:
};

#endif // PARAMETER_H
