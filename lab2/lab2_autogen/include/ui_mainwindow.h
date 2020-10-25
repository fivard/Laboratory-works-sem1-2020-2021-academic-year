/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *newHeader;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *work;
    QCheckBox *learning;
    QCheckBox *personal;
    QLabel *label;
    QTextEdit *newText;
    QListView *listViewMain;
    QListView *listViewArchieve;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonMainNotes;
    QPushButton *pushButtonArchievedNotes;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(660, 320, 141, 281));
        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(310, 180, 351, 444));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

        verticalLayout->addLayout(horizontalLayout_2);

        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        newHeader = new QLineEdit(verticalLayoutWidget_3);
        newHeader->setObjectName(QString::fromUtf8("newHeader"));

        horizontalLayout->addWidget(newHeader);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        work = new QCheckBox(verticalLayoutWidget_3);
        work->setObjectName(QString::fromUtf8("work"));

        verticalLayout_2->addWidget(work);

        learning = new QCheckBox(verticalLayoutWidget_3);
        learning->setObjectName(QString::fromUtf8("learning"));

        verticalLayout_2->addWidget(learning);

        personal = new QCheckBox(verticalLayoutWidget_3);
        personal->setObjectName(QString::fromUtf8("personal"));

        verticalLayout_2->addWidget(personal);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(verticalLayoutWidget_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Plain);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        newText = new QTextEdit(verticalLayoutWidget_3);
        newText->setObjectName(QString::fromUtf8("newText"));
        newText->setMinimumSize(QSize(0, 300));
        newText->setMaximumSize(QSize(16777215, 300));

        verticalLayout->addWidget(newText);


        verticalLayout_3->addLayout(verticalLayout);

        listViewMain = new QListView(centralwidget);
        listViewMain->setObjectName(QString::fromUtf8("listViewMain"));
        listViewMain->setGeometry(QRect(0, 300, 301, 300));
        listViewArchieve = new QListView(centralwidget);
        listViewArchieve->setObjectName(QString::fromUtf8("listViewArchieve"));
        listViewArchieve->setGeometry(QRect(0, 300, 300, 300));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 210, 301, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButtonMainNotes = new QPushButton(horizontalLayoutWidget);
        pushButtonMainNotes->setObjectName(QString::fromUtf8("pushButtonMainNotes"));

        horizontalLayout_3->addWidget(pushButtonMainNotes);

        pushButtonArchievedNotes = new QPushButton(horizontalLayoutWidget);
        pushButtonArchievedNotes->setObjectName(QString::fromUtf8("pushButtonArchievedNotes"));

        horizontalLayout_3->addWidget(pushButtonArchievedNotes);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Create new note", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Creating new note", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Header", nullptr));
        work->setText(QCoreApplication::translate("MainWindow", "Work", nullptr));
        learning->setText(QCoreApplication::translate("MainWindow", "Learning", nullptr));
        personal->setText(QCoreApplication::translate("MainWindow", "Personal", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Text", nullptr));
        pushButtonMainNotes->setText(QCoreApplication::translate("MainWindow", "Main notes", nullptr));
        pushButtonArchievedNotes->setText(QCoreApplication::translate("MainWindow", "Archived Notes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
