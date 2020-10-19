#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Notes");
    readingNotesFromFile();
}

MainWindow::~MainWindow()
{
    writtingDataNotesToFile();
    writtingNotesTextToFile();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QDateTime newDateTime = QDateTime::currentDateTime();
    QString newText = ui->newText->toPlainText();
    QString newHeader = ui->newHeader->text();
    QVector<QString> types;
    if(ui->work->isChecked())
        types.push_back("Work");
    if(ui->learning->isChecked())
        types.push_back("Learning");
    if(ui->personal->isChecked())
        types.push_back("Personal");
    ui->newHeader->clear();
    ui->newText->clear();
    ui->work->setChecked(false);
    ui->learning->setChecked(false);
    ui->personal->setChecked(false);

    Note newNote(newHeader, newText, types, newDateTime);
    notes.push_back(newNote);
}

void MainWindow::readingNotesFromFile()
{
    QFile dataNotes("files/dataNotes.txt");
    if (!dataNotes.open(QIODevice::ReadOnly))
        return;
    while(!dataNotes.atEnd()){
        //create header
        QString newHeader = dataNotes.readLine();
        newHeader.remove(newHeader.size()-1,1);

        //create date
        QString hour, minute, second, year, month, day, countOfTypes, type;
        hour = dataNotes.readLine();
        minute = dataNotes.readLine();
        second = dataNotes.readLine();
        year = dataNotes.readLine();
        month = dataNotes.readLine();
        day = dataNotes.readLine();
        QTime time(hour.toInt(),minute.toInt(), second.toInt());
        QDate date(year.toInt(),month.toInt(), day.toInt());
        QDateTime newDateTime(date, time);

        //create types
        countOfTypes = dataNotes.readLine();
        QVector<QString> newTypes;
        for (int i = 0; i < countOfTypes.toInt(); i++){
            type = dataNotes.readLine();
            type.remove(type.size()-1,1);
            newTypes.push_back(type);
        }

        //create text
        QString fileName = newDateTime.date().toString("dd.MM.yyyy")
                + "_" + newDateTime.time().toString("hh.mm.ss") + ".txt";
        QFile textNotes("files/notesText/"+fileName);
        if (!textNotes.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        QString newText = textNotes.readAll();
        textNotes.close();

        Note newNote(newHeader,newText, newTypes, newDateTime);
        qDebug() << newNote;
        notes.push_back(newNote);

    }

    dataNotes.close();
}

void MainWindow::writtingDataNotesToFile()
{
    QFile dataNotes("files/dataNotes.txt");
    dataNotes.open(QIODevice::WriteOnly);
    QTextStream out(&dataNotes);
    for (int i = 0; i < notes.size(); i++)
    {
        out << notes[i].header << "\n";
        out << notes[i].dateTime.time().hour() << "\n";
        out << notes[i].dateTime.time().minute() << "\n";
        out << notes[i].dateTime.time().second() << "\n";
        out << notes[i].dateTime.date().year() << "\n";
        out << notes[i].dateTime.date().month() << "\n";
        out << notes[i].dateTime.date().day() << "\n";
        out << notes[i].types.size() << "\n";
        for (int j = 0; j < notes[i].types.size(); j++)
            out << notes[i].types[j] << "\n";
    }
    dataNotes.close();
}

void MainWindow::writtingNotesTextToFile()
{
    for (int i = 0; i < notes.size(); i++)
    {
        QString fileName = notes[i].dateToFileName();
        QFile textNotes("files/notesText/"+fileName);
        if (!textNotes.open(QIODevice::WriteOnly | QIODevice::Text)){
            return;
        }
        QTextStream out(&textNotes);
        out << notes[i].text;
        textNotes.close();
    }
}
