#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPalette>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QLabel>
#include "analyzefun.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    static Widget *m_instance;
    static Widget *Instance();

public slots:
    void Login_click();
    void Exit_click();
    void Help_click();



private slots:


private:
    Ui::Widget *ui;
    QLabel *TitleLabel;
    QPushButton *LoginBtn,*ExitBtn,*HelpBtn;

};

#endif // WIDGET_H
