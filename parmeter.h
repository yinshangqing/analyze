#ifndef PARMETER_H
#define PARMETER_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class ParMeter;
}

class ParMeter : public QDialog
{
    Q_OBJECT

public:
    explicit ParMeter(QWidget *parent = 0);
    ~ParMeter();

    static ParMeter *m_instance;
    static ParMeter *Instance();

    void SetLMaxNumber(long lMaxNum){m_lMaxNum = lMaxNum;}
    void SetLMinNumber(long lMinNum){m_lMinNum = lMinNum;}
    long GetLSetNumber(){return m_lSetNum;}

private slots:
    void on_okBtn_clicked();
    void UpdataSlot();

private:
    Ui::ParMeter *ui;
    QTimer timer;
    QString m_strMax;
    QString m_strMin;
    long m_lMaxNum;
    long m_lMinNum;
    long m_lSetNum;
};

#endif // PARMETER_H
