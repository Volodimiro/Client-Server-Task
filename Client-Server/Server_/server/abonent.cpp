#include "abonent.h"
#include <QColor>




Abonent::Abonent(QTextEdit *textedit, QTcpSocket* socket, int *client):_AbText(textedit), _AbSocket(socket), _AbNumber(client)
{
 _color.setRgb(rand()%125,rand()%125,rand()%125);
// _Afirst_line = _AbText->document()->lineCount();
// _Aend_line   = _AbText->document()->lineCount();
// _abonent_number = *_AbNumber;
 (*_AbNumber)++;
_AbText->setTextColor(_color);
_AbSocket->open(QIODevice::ReadWrite);
//_AbText->append("Abonent "+ _AbName +" is conected");
//_Anumber_line_abonent_in_TextEdid2 = _AbText->textCursor().blockNumber();
}


Abonent::~Abonent()
{  _AbText->setTextColor(_color);
  _AbText->append("Abonent "+ _AbName +" is disconnected");
  _AbSocket->close();
  (*_AbNumber)--;

}
