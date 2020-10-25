#ifndef NOTEWINDOW_H
#define NOTEWINDOW_H

#include <QDialog>
#include "note.h"


namespace Ui {
class NoteWindow;
}

class NoteWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NoteWindow(QWidget *parent = nullptr);
    ~NoteWindow();

    void setNote(const Note& newNote);

private:
    Ui::NoteWindow *ui;

    Note note;
};

#endif // NOTEWINDOW_H
