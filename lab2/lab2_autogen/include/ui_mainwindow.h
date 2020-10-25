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
    QPushButton *pushButton;
    QListView *listViewMain;
    QListView *listViewArchieve;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonMainNotes;
    QPushButton *pushButtonArchievedNotes;
    QLabel *labelGif;
    QLabel *label_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(549, 600);
        MainWindow->setMinimumSize(QSize(549, 600));
        MainWindow->setMaximumSize(QSize(549, 600));
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(260, 258, 281, 341));
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
        QFont font;
        font.setFamily(QString::fromUtf8("Perpetua Titling MT"));
        font.setPointSize(8);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        newHeader = new QLineEdit(verticalLayoutWidget_3);
        newHeader->setObjectName(QString::fromUtf8("newHeader"));

        horizontalLayout->addWidget(newHeader);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        work = new QCheckBox(verticalLayoutWidget_3);
        work->setObjectName(QString::fromUtf8("work"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Perpetua Titling MT"));
        font1.setPointSize(6);
        work->setFont(font1);

        verticalLayout_2->addWidget(work);

        learning = new QCheckBox(verticalLayoutWidget_3);
        learning->setObjectName(QString::fromUtf8("learning"));
        learning->setFont(font1);

        verticalLayout_2->addWidget(learning);

        personal = new QCheckBox(verticalLayoutWidget_3);
        personal->setObjectName(QString::fromUtf8("personal"));
        personal->setFont(font1);

        verticalLayout_2->addWidget(personal);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(verticalLayoutWidget_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Plain);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        newText = new QTextEdit(verticalLayoutWidget_3);
        newText->setObjectName(QString::fromUtf8("newText"));
        newText->setMinimumSize(QSize(0, 0));
        newText->setMaximumSize(QSize(16777215, 300));
        newText->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(newText);

        pushButton = new QPushButton(verticalLayoutWidget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(pushButton);


        verticalLayout_3->addLayout(verticalLayout);

        listViewMain = new QListView(centralwidget);
        listViewMain->setObjectName(QString::fromUtf8("listViewMain"));
        listViewMain->setGeometry(QRect(0, 389, 251, 211));
        QPalette palette;
        QBrush brush(QColor(85, 170, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        listViewMain->setPalette(palette);
        QFont font2;
        font2.setFamily(QString::fromUtf8("MV Boli"));
        font2.setPointSize(10);
        listViewMain->setFont(font2);
        listViewMain->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        listViewArchieve = new QListView(centralwidget);
        listViewArchieve->setObjectName(QString::fromUtf8("listViewArchieve"));
        listViewArchieve->setGeometry(QRect(0, 389, 251, 211));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MV Boli"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        listViewArchieve->setFont(font3);
        listViewArchieve->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        listViewArchieve->setLayoutDirection(Qt::LeftToRight);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 260, 251, 111));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButtonMainNotes = new QPushButton(horizontalLayoutWidget);
        pushButtonMainNotes->setObjectName(QString::fromUtf8("pushButtonMainNotes"));
        QPalette palette1;
        QBrush brush2(QColor(170, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        pushButtonMainNotes->setPalette(palette1);
        pushButtonMainNotes->setFont(font);
        pushButtonMainNotes->setFlat(false);

        horizontalLayout_3->addWidget(pushButtonMainNotes);

        pushButtonArchievedNotes = new QPushButton(horizontalLayoutWidget);
        pushButtonArchievedNotes->setObjectName(QString::fromUtf8("pushButtonArchievedNotes"));
        pushButtonArchievedNotes->setFont(font);

        horizontalLayout_3->addWidget(pushButtonArchievedNotes);

        labelGif = new QLabel(centralwidget);
        labelGif->setObjectName(QString::fromUtf8("labelGif"));
        labelGif->setGeometry(QRect(30, 0, 501, 251));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 350, 71, 21));
        label_5->setFont(font);
        label_5->setAutoFillBackground(false);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Creating new note", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Header", nullptr));
        newHeader->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter header of note here...", nullptr));
        work->setText(QCoreApplication::translate("MainWindow", "Work", nullptr));
        learning->setText(QCoreApplication::translate("MainWindow", "Learning", nullptr));
        personal->setText(QCoreApplication::translate("MainWindow", "Personal", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Text", nullptr));
        newText->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter text of note here...", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Create new note", nullptr));
        pushButtonMainNotes->setText(QCoreApplication::translate("MainWindow", "Main notes", nullptr));
        pushButtonArchievedNotes->setText(QCoreApplication::translate("MainWindow", "Archived Notes", nullptr));
        labelGif->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
#if QT_CONFIG(whatsthis)
        label_5->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_5->setText(QCoreApplication::translate("MainWindow", "All notes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
