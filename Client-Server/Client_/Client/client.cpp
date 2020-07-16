#include "client.h"


Client::Client(QTextEdit *hostIP, QTextEdit *port, QTextEdit *textedit1, QTextEdit *textedit2, QTextEdit *Name):_hostIP(hostIP), _port(port),_textedit1(textedit1),_textedit2(textedit2), _Name(Name)
{
 _status = false;
};



void Client::SlotConnectbutton()
{

QString str = "_Client_: <"  + _Name->toPlainText() + ">";

    QPushButton *button = dynamic_cast <QPushButton*>(sender());
   if(!_status)
    {
    button->setText("Client is connected");
    _status = true;
    _Clientsocket = new  QTcpSocket(this);
    _Clientsocket->connectToHost(_hostIP->toPlainText(), _port->toPlainText().toUInt());
     if(_Clientsocket->waitForConnected())
     {

       _Clientsocket->open(QIODevice::ReadWrite);
       _Clientsocket->write(str.toStdString().c_str());
       connect(_Clientsocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));
     }
     else
     {
        _Clientsocket->disconnected();
       _status = false;
       _ms.setText("Server is absent!");
       _ms.show();
       button->setText("Connect");
     }
   }
   else
   {
     button->setText("Connect");
     _status = false;
     _Clientsocket->disconnected();
     delete _Clientsocket;
   }

};




void Client::slotReadyRead()
{
     QColor color1(0,150, 0);
    _textedit1->setTextColor(color1);
    _textedit1->append(_Clientsocket->readAll());
};




void Client::SlotSendToServer()
{
QString str;
   str = "<" + _Name->toPlainText() + ">:\n " + _textedit2->toPlainText();
  _Clientsocket->write(str.toStdString().c_str());
  _textedit2->clear();

};
