/********************************************************************************
** Form generated from reading UI file 'parmeter.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARMETER_H
#define UI_PARMETER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParMeter
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *MaxLab;
    QLabel *MinLab;
    QPushButton *okBtn;

    void setupUi(QDialog *ParMeter)
    {
        if (ParMeter->objectName().isEmpty())
            ParMeter->setObjectName(QStringLiteral("ParMeter"));
        ParMeter->resize(329, 174);
        layoutWidget = new QWidget(ParMeter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 100, 231, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit);

        MaxLab = new QLabel(ParMeter);
        MaxLab->setObjectName(QStringLiteral("MaxLab"));
        MaxLab->setGeometry(QRect(30, 30, 141, 21));
        MinLab = new QLabel(ParMeter);
        MinLab->setObjectName(QStringLiteral("MinLab"));
        MinLab->setGeometry(QRect(30, 60, 151, 21));
        okBtn = new QPushButton(ParMeter);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setGeometry(QRect(130, 130, 81, 23));

        retranslateUi(ParMeter);

        QMetaObject::connectSlotsByName(ParMeter);
    } // setupUi

    void retranslateUi(QDialog *ParMeter)
    {
        ParMeter->setWindowTitle(QApplication::translate("ParMeter", "Dialog", 0));
        label->setText(QApplication::translate("ParMeter", "\350\256\276\345\256\232\345\217\202\346\225\260\345\200\274", 0));
        MaxLab->setText(QApplication::translate("ParMeter", "\346\234\200\345\244\247\345\200\274\344\270\272\357\274\232", 0));
        MinLab->setText(QApplication::translate("ParMeter", "\346\234\200\345\260\217\345\200\274\344\270\272\357\274\232", 0));
        okBtn->setText(QApplication::translate("ParMeter", "\347\241\256\350\256\244\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class ParMeter: public Ui_ParMeter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARMETER_H
