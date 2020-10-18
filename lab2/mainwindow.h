#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "note.h"

class Note;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void readingNotesFromFile();
    void writtingNotesToFile();

private slots:

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<Note> notes;
};
#endif // MAINWINDOW_H
