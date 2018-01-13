#include "widget.h"
#include <QApplication>
#include <QTextCodec>
#include "analyzefun.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    a.setStyleSheet("menu-");
//    Widget::Instance();
    Widget::Instance()->show();

//    AnalyzeFun af;
//    af.show();


    return a.exec();
}
