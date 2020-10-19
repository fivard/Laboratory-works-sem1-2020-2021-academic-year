#ifndef NOTE_H
#define NOTE_H
#include <QString>
#include <QDateTime>
#include <QVector>
#include <QDebug>


class Note
{
    QString text;
    QString header;
    QVector<QString> types;
    QDateTime dateTime;
    int id;

public:
    Note();
    Note(const QString& newHeader, const QString& newText, const QVector<QString>& newTypes, const QDateTime& newDateTime);
    Note(const QString& newHeader, const QVector<QString>& newTypes, const QDateTime& newDateTime);
    QString dateToFileName();
    friend QDebug operator<<(QDebug d, Note& note);
    friend class MainWindow;
};

#endif // NOTE_H
