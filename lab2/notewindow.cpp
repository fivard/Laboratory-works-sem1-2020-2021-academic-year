#include "notewindow.h"
#include "ui_notewindow.h"

NoteWindow::NoteWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoteWindow)
{
    ui->setupUi(this);
    setWindowTitle("Current note");
}

NoteWindow::~NoteWindow()
{
    delete ui;
}

void NoteWindow::setNote(const Note &newNote)
{
    note = newNote;
    ui->checkBoxWork->setChecked(false);
    ui->checkBoxLearning->setChecked(false);
    ui->checkBoxPersonal->setChecked(false);

    ui->labelDate->setText(newNote.dateTime.toString());
    ui->lineHeader->setText(newNote.header);
    ui->textNote->setText(newNote.text);
    for (int i = 0; i < newNote.types.size(); i++){
        if (newNote.types[i] == "Work")
            ui->checkBoxWork->setChecked(true);
        if (newNote.types[i] == "Learning")
            ui->checkBoxLearning->setChecked(true);
        if (newNote.types[i] == "Personal")
            ui->checkBoxPersonal->setChecked(true);
    }
}
