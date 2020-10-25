#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    main_model(new QStandardItemModel),
    arch_model(new QStandardItemModel),
    lists(new QStackedLayout)
{
    ui->setupUi(this);

    topGif = new QMovie("src/N6.gif");
    ui->labelGif->setMovie(topGif);
    topGif->start();

    ui->listViewMain->setModel(main_model);
    ui->listViewArchieve->setModel(arch_model);

    this->lists->addWidget(ui->listViewArchieve);
    this->lists->addWidget(ui->listViewMain);

    this->lists->setCurrentWidget(ui->listViewMain);

    setWindowTitle("Notes");

    readingNotesFromFile("files/dataNotes.txt", notes, main_model);
    readingNotesFromFile("files/dataArchievedNotes.txt", archieve, arch_model);
}

MainWindow::~MainWindow()
{
    writtingDataNotesToFile("files/dataNotes.txt", notes);
    writtingDataNotesToFile("files/dataArchievedNotes.txt", archieve);

    writtingNotesTextToFile();
    delete ui;
}

void MainWindow::addNoteToList(const Note& note, QVector<Note>& list, QStandardItemModel  *model)
{
    int position = binSearchNotePosition(0, std::max(0,list.size()-1), list, note);
    list.insert(list.begin() + position, note);
    model->insertRow(position);
    auto item = new QStandardItem(note.header);
    model->setItem(position, item);
}

int MainWindow::binSearchNotePosition(int left, int right, QVector<Note>& list, const Note& note)
{
    if (left == right)
        return left;
    int middle = (left+right)/2;
    if (list[middle].dateTime > note.dateTime)
        binSearchNotePosition(left, middle, list, note);
    else
        binSearchNotePosition(middle+1, right, list, note);
}

void MainWindow::readingNotesFromFile(const QString& fileName, QVector<Note>& list, QStandardItemModel *model)
{
    QFile dataNotes(fileName);
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
        addNoteToList(newNote, list, model);
    }

    dataNotes.close();
}

void MainWindow::writtingDataNotesToFile(const QString& fileName, const QVector<Note>& list)
{
    QFile dataNotes(fileName);
    dataNotes.open(QIODevice::WriteOnly);
    QTextStream out(&dataNotes);
    for (int i = 0; i < list.size(); i++)
    {
        out << list[i].header << "\n";
        out << list[i].dateTime.time().hour() << "\n";
        out << list[i].dateTime.time().minute() << "\n";
        out << list[i].dateTime.time().second() << "\n";
        out << list[i].dateTime.date().year() << "\n";
        out << list[i].dateTime.date().month() << "\n";
        out << list[i].dateTime.date().day() << "\n";
        out << list[i].types.size() << "\n";
        for (int j = 0; j < list[i].types.size(); j++)
            out << list[i].types[j] << "\n";
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

    for (int i = 0; i < archieve.size(); i++)
    {
        QString fileName = archieve[i].dateToFileName();
        QFile textNotes("files/notesText/"+fileName);
        if (!textNotes.open(QIODevice::WriteOnly | QIODevice::Text)){
            return;
        }
        QTextStream out(&textNotes);
        out << archieve[i].text;
        textNotes.close();
    }
}

// slot

void MainWindow::on_pushButtonMainNotes_clicked()
{
    lists->setCurrentWidget(ui->listViewMain);
}

void MainWindow::on_pushButtonArchievedNotes_clicked()
{
    lists->setCurrentWidget(ui->listViewArchieve);
}

void MainWindow::on_listViewMain_clicked(const QModelIndex &index)
{
    QMessageBox msgBox;

    msgBox.setText("Choose action");
    QPushButton *openButton = msgBox.addButton(tr("Open"), QMessageBox::ActionRole);
    QPushButton *deleteButton = msgBox.addButton(tr("Delete"), QMessageBox::ActionRole);
    QPushButton *archiveButton = msgBox.addButton(tr("Archive"), QMessageBox::ActionRole);
    msgBox.setStandardButtons(QMessageBox::Cancel);

    msgBox.exec();

    if (msgBox.clickedButton() == openButton){
        Note selectedNote = notes[index.row()];
        noteWindow.setNote(selectedNote);
        noteWindow.show();
    }

    if (msgBox.clickedButton() == deleteButton){
        QFile file("files/notesText/"+notes[index.row()].dateToFileName());
        file.remove();
        notes.erase(notes.begin()+index.row());
        main_model->removeRow(index.row());
    }

    if (msgBox.clickedButton() == archiveButton){
        addNoteToList(notes[index.row()], archieve, arch_model);
        notes.erase(notes.begin()+index.row());
        main_model->removeRow(index.row());
    }

}

void MainWindow::on_listViewArchieve_clicked(const QModelIndex &index)
{
    QMessageBox msgBox;

    msgBox.setText("Choose action");
    QPushButton *openButton = msgBox.addButton(tr("Open"), QMessageBox::ActionRole);
    QPushButton *deleteButton = msgBox.addButton(tr("Delete"), QMessageBox::ActionRole);
    QPushButton *archiveButton = msgBox.addButton(tr("To main"), QMessageBox::ActionRole);
    msgBox.setStandardButtons(QMessageBox::Cancel);

    msgBox.exec();

    if (msgBox.clickedButton() == openButton){
        Note selectedNote = archieve[index.row()];
        noteWindow.setNote(selectedNote);
        noteWindow.show();
    }

    if (msgBox.clickedButton() == deleteButton){
        QFile file("files/notesText/"+archieve[index.row()].dateToFileName());
        file.remove();
        archieve.erase(archieve.begin()+index.row());
        arch_model->removeRow(index.row());
    }

    if (msgBox.clickedButton() == archiveButton){
        addNoteToList(archieve[index.row()], notes, main_model);
        archieve.erase(archieve.begin()+index.row());
        arch_model->removeRow(index.row());
    }
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->newHeader->text() == ""){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("The note hasn't got header.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        switch (ret) {
            case QMessageBox::Save:
                break;
            case QMessageBox::Cancel:
                return;
        }
    }

    //add to QVector
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

    //add to list
    main_model->insertRow(notes.size()-1);
    auto item = new QStandardItem(newNote.header);
    main_model->setItem(notes.size()-1, item);
}
