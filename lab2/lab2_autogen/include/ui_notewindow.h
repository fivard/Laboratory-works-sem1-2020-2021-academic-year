/********************************************************************************
** Form generated from reading UI file 'notewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEWINDOW_H
#define UI_NOTEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NoteWindow
{
public:
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelDate;
    QLineEdit *lineHeader;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBoxWork;
    QCheckBox *checkBoxLearning;
    QCheckBox *checkBoxPersonal;
    QTextEdit *textNote;

    void setupUi(QDialog *NoteWindow)
    {
        if (NoteWindow->objectName().isEmpty())
            NoteWindow->setObjectName(QString::fromUtf8("NoteWindow"));
        NoteWindow->resize(648, 417);
        verticalLayoutWidget_3 = new QWidget(NoteWindow);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 9, 631, 401));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        labelDate = new QLabel(verticalLayoutWidget_3);
        labelDate->setObjectName(QString::fromUtf8("labelDate"));

        verticalLayout_4->addWidget(labelDate);

        lineHeader = new QLineEdit(verticalLayoutWidget_3);
        lineHeader->setObjectName(QString::fromUtf8("lineHeader"));

        verticalLayout_4->addWidget(lineHeader);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        checkBoxWork = new QCheckBox(verticalLayoutWidget_3);
        checkBoxWork->setObjectName(QString::fromUtf8("checkBoxWork"));

        verticalLayout_2->addWidget(checkBoxWork);

        checkBoxLearning = new QCheckBox(verticalLayoutWidget_3);
        checkBoxLearning->setObjectName(QString::fromUtf8("checkBoxLearning"));

        verticalLayout_2->addWidget(checkBoxLearning);

        checkBoxPersonal = new QCheckBox(verticalLayoutWidget_3);
        checkBoxPersonal->setObjectName(QString::fromUtf8("checkBoxPersonal"));

        verticalLayout_2->addWidget(checkBoxPersonal);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        textNote = new QTextEdit(verticalLayoutWidget_3);
        textNote->setObjectName(QString::fromUtf8("textNote"));

        verticalLayout_3->addWidget(textNote);


        retranslateUi(NoteWindow);

        QMetaObject::connectSlotsByName(NoteWindow);
    } // setupUi

    void retranslateUi(QDialog *NoteWindow)
    {
        NoteWindow->setWindowTitle(QCoreApplication::translate("NoteWindow", "Dialog", nullptr));
        labelDate->setText(QCoreApplication::translate("NoteWindow", "TextLabel", nullptr));
        checkBoxWork->setText(QCoreApplication::translate("NoteWindow", "Work", nullptr));
        checkBoxLearning->setText(QCoreApplication::translate("NoteWindow", "Learning", nullptr));
        checkBoxPersonal->setText(QCoreApplication::translate("NoteWindow", "Personal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoteWindow: public Ui_NoteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEWINDOW_H
