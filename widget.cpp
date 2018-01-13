#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget * Widget::m_instance = NULL;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(800,500);
    this->setFixedSize(800,500);
    this->setWindowTitle(WND_TITLE_STR);


    QFrame *frame = new QFrame(this);
    frame->setObjectName("myframe");
    frame->resize(800,500);
    frame->setFixedSize(800,500);
    frame->setStyleSheet("QFrame#myframe{border-image:url(:/background.jpg)}");

    TitleLabel = new QLabel(frame);
    LoginBtn = new QPushButton(frame);
    ExitBtn = new QPushButton(frame);
    HelpBtn = new QPushButton(frame);

    TitleLabel->setText(WND_TITLE_STR);
    TitleLabel->setGeometry(160,100,600,40);
    TitleLabel->setStyleSheet("color:white;font:30pt;font-weight:bold;");

    LoginBtn->setGeometry(600,270,160,40);
    LoginBtn->setText("进入系统");
    LoginBtn->setStyleSheet("color:white;font:20pt;border:2px solid white;");

    ExitBtn->setGeometry(600,320,160,40);
    ExitBtn->setText("\351\200\200\345\207\272\347\263\273\347\273\237");
	ExitBtn->setStyleSheet("color:white;font:20pt;border:2px solid white;");

    HelpBtn->setGeometry(600,370,160,40);
    HelpBtn->setText("帮助");
    HelpBtn->setStyleSheet("color:white;font:20pt;border:2px solid white;");

    connect(LoginBtn,SIGNAL(clicked()),this,SLOT(Login_click()));
    connect(ExitBtn,SIGNAL(clicked()),this,SLOT(Exit_click()));
    connect(HelpBtn,SIGNAL(clicked()),this,SLOT(Help_click()));

}

Widget::~Widget()
{
    delete ui;
}

Widget *Widget::Instance()
{
    if(m_instance == NULL)
        m_instance = new Widget;
    return m_instance;
}

void Widget::Login_click()
{
    AnalyzeFun *af = new AnalyzeFun;
    af->show();

    this->hide();
}
void Widget::Exit_click()
{
    exit(0);
}

void Widget::Help_click()
{
    QMessageBox::information(NULL,"提示","      电磁发射测试频谱，是被试品的固有属性，具有离散型、复杂性、视在频谱的特点.作为一个因果系统，电磁发射测试数据能反映设备内部发射源的特征，因此从被试品的电磁发射测试频谱及其他类型数据中必能提取其发射源的特征，进而对电磁干扰源进行针对性的整改或者量化设计的.\n      本设备基于电磁发射要素理论，重点关注频谱特征，导入或者测试得到相应的传导/辐射发射测试数据，根据数据中的梳状谱找到引起设备电磁兼容性测试超标的电磁发射干扰源的特征数据，进而给出需要排查的方向.");
}
