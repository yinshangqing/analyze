/********************************************************************************
** Form generated from reading UI file 'analyzefun.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYZEFUN_H
#define UI_ANALYZEFUN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnalyzeFun
{
public:
    QGroupBox *groupBox;
    QPushButton *DataInputBtn;
    QPushButton *GraphBtn;
    QPushButton *PartAnalyzeBtn;
    QPushButton *DataCatBtn;
    QPushButton *MarkBtn;
    QPushButton *AnalyzeBtn;
    QPushButton *ArgsBtn;
    QPushButton *PictureBtn;
    QPushButton *PackageBtn;
    QGroupBox *groupBox_3;
    QTextEdit *textEdit;
    QPushButton *StartBtn;
    QLabel *label;
    QPushButton *combkBtn;

    void setupUi(QWidget *AnalyzeFun)
    {
        if (AnalyzeFun->objectName().isEmpty())
            AnalyzeFun->setObjectName(QStringLiteral("AnalyzeFun"));
        AnalyzeFun->resize(800, 500);
        groupBox = new QGroupBox(AnalyzeFun);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 201, 321));
        QFont font;
        font.setPointSize(12);
        groupBox->setFont(font);
        DataInputBtn = new QPushButton(groupBox);
        DataInputBtn->setObjectName(QStringLiteral("DataInputBtn"));
        DataInputBtn->setGeometry(QRect(0, 30, 131, 31));
        DataInputBtn->setCheckable(false);
        DataInputBtn->setChecked(false);
        GraphBtn = new QPushButton(groupBox);
        GraphBtn->setObjectName(QStringLiteral("GraphBtn"));
        GraphBtn->setGeometry(QRect(0, 240, 131, 31));
        PartAnalyzeBtn = new QPushButton(groupBox);
        PartAnalyzeBtn->setObjectName(QStringLiteral("PartAnalyzeBtn"));
        PartAnalyzeBtn->setGeometry(QRect(0, 210, 131, 31));
        DataCatBtn = new QPushButton(groupBox);
        DataCatBtn->setObjectName(QStringLiteral("DataCatBtn"));
        DataCatBtn->setGeometry(QRect(0, 180, 131, 31));
        MarkBtn = new QPushButton(groupBox);
        MarkBtn->setObjectName(QStringLiteral("MarkBtn"));
        MarkBtn->setGeometry(QRect(0, 150, 131, 31));
        AnalyzeBtn = new QPushButton(groupBox);
        AnalyzeBtn->setObjectName(QStringLiteral("AnalyzeBtn"));
        AnalyzeBtn->setGeometry(QRect(0, 120, 131, 31));
        ArgsBtn = new QPushButton(groupBox);
        ArgsBtn->setObjectName(QStringLiteral("ArgsBtn"));
        ArgsBtn->setGeometry(QRect(0, 90, 131, 31));
        PictureBtn = new QPushButton(groupBox);
        PictureBtn->setObjectName(QStringLiteral("PictureBtn"));
        PictureBtn->setGeometry(QRect(0, 60, 131, 31));
        PackageBtn = new QPushButton(groupBox);
        PackageBtn->setObjectName(QStringLiteral("PackageBtn"));
        PackageBtn->setGeometry(QRect(0, 270, 131, 31));
        groupBox_3 = new QGroupBox(AnalyzeFun);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 340, 791, 111));
        groupBox_3->setFont(font);
        textEdit = new QTextEdit(groupBox_3);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 20, 771, 81));
        StartBtn = new QPushButton(AnalyzeFun);
        StartBtn->setObjectName(QStringLiteral("StartBtn"));
        StartBtn->setGeometry(QRect(0, 460, 131, 31));
        label = new QLabel(AnalyzeFun);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 10, 51, 21));
        combkBtn = new QPushButton(AnalyzeFun);
        combkBtn->setObjectName(QStringLiteral("combkBtn"));
        combkBtn->setGeometry(QRect(730, 460, 61, 31));

        retranslateUi(AnalyzeFun);

        QMetaObject::connectSlotsByName(AnalyzeFun);
    } // setupUi

    void retranslateUi(QWidget *AnalyzeFun)
    {
        AnalyzeFun->setWindowTitle(QApplication::translate("AnalyzeFun", "Form", 0));
        groupBox->setTitle(QApplication::translate("AnalyzeFun", "\345\212\237\350\203\275\346\240\217", 0));
        DataInputBtn->setText(QApplication::translate("AnalyzeFun", "\346\225\260\346\215\256\345\257\274\345\205\245", 0));
        GraphBtn->setText(QApplication::translate("AnalyzeFun", "\350\256\276\345\256\232\346\233\262\347\272\277", 0));
        PartAnalyzeBtn->setText(QApplication::translate("AnalyzeFun", "\345\261\200\351\203\250\345\210\206\346\236\220", 0));
        DataCatBtn->setText(QApplication::translate("AnalyzeFun", "\346\225\260\346\215\256\346\237\245\347\234\213", 0));
        MarkBtn->setText(QApplication::translate("AnalyzeFun", "\350\260\220\346\263\242\346\240\207\350\256\260", 0));
        AnalyzeBtn->setText(QApplication::translate("AnalyzeFun", "\345\237\272\351\242\221\345\210\206\346\236\220", 0));
        ArgsBtn->setText(QApplication::translate("AnalyzeFun", "\345\217\202\346\225\260\350\256\276\345\256\232", 0));
        PictureBtn->setText(QApplication::translate("AnalyzeFun", "\345\233\276\345\275\242\347\273\230\345\210\266", 0));
        PackageBtn->setText(QApplication::translate("AnalyzeFun", "\346\211\223\345\214\205\345\212\237\350\203\275", 0));
        groupBox_3->setTitle(QApplication::translate("AnalyzeFun", "\346\217\220\347\244\272", 0));
        textEdit->setHtml(QApplication::translate("AnalyzeFun", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        StartBtn->setText(QApplication::translate("AnalyzeFun", "\345\274\200\345\247\213\345\210\206\346\236\220", 0));
        label->setText(QApplication::translate("AnalyzeFun", "\346\230\276\347\244\272\347\252\227\345\217\243", 0));
        combkBtn->setText(QApplication::translate("AnalyzeFun", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class AnalyzeFun: public Ui_AnalyzeFun {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYZEFUN_H
