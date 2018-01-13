#include "parmeter.h"
#include "ui_parmeter.h"

ParMeter *ParMeter::m_instance = NULL;
ParMeter::ParMeter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParMeter)
{
    ui->setupUi(this);
    m_strMax = ui->MaxLab->text();
    m_strMin = ui->MinLab->text();

    connect(&timer,SIGNAL(timeout()),this,SLOT(UpdataSlot()));
    timer.start(1000);
}

ParMeter::~ParMeter()
{
    delete ui;
}

ParMeter *ParMeter::Instance()
{
    if(m_instance == NULL)
        m_instance = new ParMeter;
    return m_instance;
}

void ParMeter::on_okBtn_clicked()
{
    m_lSetNum = ui->lineEdit->text().toInt();
    this->hide();
}

void ParMeter::UpdataSlot()
{
    QString strMax;
    QString strMin;
	strMax.sprintf("%d",m_lMaxNum);
	strMin.sprintf("%d",m_lMinNum);
	strMax = m_strMax + strMax;
	strMin = m_strMin + strMin;
    //strMax.append('%1').arg(m_lMaxNum);
    //strMin.append('%1').arg(m_lMinNum);
    ui->MaxLab->setText(strMax);
    ui->MinLab->setText(strMin);

}





