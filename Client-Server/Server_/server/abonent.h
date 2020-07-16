#ifndef ABONENT_H
#define ABONENT_H
#include <QString>
#include <QTcpSocket>
#include <QTextEdit>

class Abonent
{
public:
    Abonent(QTextEdit*, QTcpSocket*, int*);
    ~Abonent();

public:
QString         _AbName;
QTcpSocket     *_AbSocket;
int   *_AbNumber;//, _abonent_number;
QTextEdit      *_AbText;
// int _Anumber_line_abonent_in_TextEdid2, _Afirst_line, _Aend_line ;
QColor _color;
};

#endif // ABONENT_H
