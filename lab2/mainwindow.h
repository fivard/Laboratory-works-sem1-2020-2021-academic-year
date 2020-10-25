#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QStandardItemModel>
#include <QStackedLayout>
#include <QFile>
#include <QMessageBox>
#include "notewindow.h"




QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void readingNotesFromFile(const QString& fileName, QVector<Note>& list, QStandardItemModel *model);

    void writtingDataNotesToFile(const QString& fileName, const QVector<Note>& list);

    void writtingNotesTextToFile();

    void addNoteToList(const Note& note, QVector<Note>& list, QStandardItemModel  *model);

    int binSearchNotePosition(int left, int right, QVector<Note>& list, const Note& note);

private slots:

    void on_pushButton_clicked();

    void on_pushButtonMainNotes_clicked();

    void on_pushButtonArchievedNotes_clicked();

    void on_listViewMain_clicked(const QModelIndex &index);

    void on_listViewArchieve_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

    QVector<Note> notes;
    QVector<Note> archieve;

    QStandardItemModel *main_model;
    QStandardItemModel *arch_model;
    QStackedLayout *lists;

    NoteWindow noteWindow;
};
#endif // MAINWINDOW_H
