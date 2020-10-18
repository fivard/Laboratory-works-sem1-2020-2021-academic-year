#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Notes");

}

MainWindow::~MainWindow()
{
    /*QFile dataNotes("dataNotes.txt");
    dataNotes.open(QIODevice::WriteOnly);
    QTextStream out(&dataNotes);
    for (std::size_t i = 0; i < notes.size(); i++){
        out << notes[i].header << "\n";
        out << notes[i].dateTime.toString() << "\n";
        out << notes[i].types.size();
        for (std::size_t j = 0; j < notes[i].types.size(); j++)
            if (notes[i].types[j] == "Робоча")
                out << " 1";
            else if (notes[i].types[j] == "Навчальна")
                out << " 2";
            else
                out << " 3";
        out << "\n";
    }
    dataNotes.close();*/
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QDateTime newDateTime = QDateTime::currentDateTime();
    qDebug() << newDateTime.toString() << '\n';
    QString newText = ui->newText->toPlainText();
    qDebug() << newText << '\n';
    QString newHeader = ui->newHeader->text();
    qDebug() << newHeader << '\n';
    std::vector<QString> types;
    Note newNote(newHeader, newText, types, newDateTime);
    //notes.push_back(newNote);
}
