#include "note.h"

Note::Note()
{
    text = "";
    header = "";
    types.clear();
    dateTime.currentDateTime();
}

Note::Note(QString newHeader, QString newText, std::vector<QString> newTypes, QDateTime newDateTime)
{
    text = newText;
    header = newHeader;
    types = newTypes;
    dateTime = newDateTime;
}
