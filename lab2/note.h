#ifndef NOTE_H
#define NOTE_H
#include <QString>
#include <vector>
#include <QDateTime>
#include "mainwindow.h"


class Note
{
    QString text;
    QString header;
    std::vector<QString> types;
    QDateTime dateTime;
public:
    Note();
    Note(QString newHeader, QString newText, std::vector<QString> newTypes, QDateTime newDateTime);
    friend class MainWindow;
};

#endif // NOTE_H
