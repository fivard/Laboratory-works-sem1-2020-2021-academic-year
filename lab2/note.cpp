#include "note.h"

Note::Note()
{
    text = "";
    header = "";
    types.clear();
    dateTime.currentDateTime();
}

Note::Note(const QString& newHeader, const QString& newText, const QVector<QString>& newTypes, const QDateTime& newDateTime)
{
    text = newText;
    header = newHeader;
    types = newTypes;
    dateTime = newDateTime;
}

Note::Note(const QString& newHeader, const QVector<QString>& newTypes, const QDateTime& newDateTime)
{
    header = newHeader;
    types = newTypes;
    dateTime = newDateTime;
    text = "";
}

QDebug operator<<(QDebug d, Note& note){
    d << note.header << '\n' << note.text << "\n" << note.dateTime.toString() << '\n';
    for (int i = 0; i < note.types.size(); i++)
        d << note.types[i] << " ";
    d << '\n';
    return d;
}
