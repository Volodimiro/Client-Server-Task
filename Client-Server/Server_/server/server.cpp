#include "server.h"
#include <qdebug.h>


Server::Server(QLabel *LClients, QTextEdit *port, QTextEdit *textedit1, QTextEdit *textedit2):_LClients(LClients), _port(port),_textedit1(textedit1),_textedit2(textedit2)
{
  _clients = 0;
  _LClients->setText("Connects: ");
  status = false;


};


void Server::StartServer()
{
   QPushButton *button = dynamic_cast<QPushButton*>(sender());
   if(!status)
   {
   button->setText("Server is started");
   status = true;
   if(!_server.listen(QHostAddress::Any,_port->toPlainText().toUInt()))
    {
      _ms.setText("Server is not started!");
      _ms.show();
      _server.close();
      button->setText("Start Server");

    }
    else
    {
      connect(&_server, SIGNAL(newConnection()),this,SLOT(slotNewConnection()));
    }

   }
   else
   {
       button->setText("Start Server");
       status = false;
      _server.close();
      _server.disconnect(&_server, SIGNAL(newConnection()),this,SLOT(slotNewConnection()));
      _server.disconnect(_Clientsocket, SIGNAL(readyRead()),this,SLOT(slotReadClient()));

   }


};



void Server::slotNewConnection()
{
   _Clientsocket = _server.nextPendingConnection();
  _Abonent = new Abonent(_textedit1,_Clientsocket, &_clients);
  _LClients->setText("Connects: "+ QString::number(_clients));
  _vector.append(_Abonent);

  connect(_Clientsocket, SIGNAL(disconnected()),this, SLOT(disconnect()));
  connect(_Clientsocket, SIGNAL(readyRead()),this,SLOT(slotReadClient()));

};



void Server::sendToClient(QTcpSocket *_Clientsocket_)
{
    _Clientsocket_->write(_textedit2->toPlainText().toStdString().c_str());
};



void Server::slotReadClient()
{
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());
    QString str;
    str = sock->readAll();
  if( 0 < str.count("_Client_: "))
  {
   _Abonent ->_AbName = str;
   _textedit1 ->append("Abonent "+ _Abonent->_AbName +" is conected");
  }
  else
  {
   str = "\n" + _date.currentDate().toString() + " " + _time.currentTime().toString() + ": "  + str + "\n\n";
   _textedit1->setTextColor(_vector.at(findAbonent(sock))->_color);
   _textedit1->append(str);
    sock->write(str.toStdString().c_str());
  }
};




void Server::disconnect()
{
 QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());
 int a;
 Abonent* ab ;
    a = findAbonent(sock);
   if(a >= 0)ab = _vector.at(a);
   if(ab != NULL)
   {
     _vector.remove(a);

       delete ab;
     _LClients->setText("Connects: "+ QString::number(_clients));
   }
   else
   {
     _LClients->setText("Abonent " + ab->_AbSocket->peerAddress().toString() + " had not connect to base!!!");
   }
};



void Server::sendMessageClient()
{
  sendToClient(TempAbonent->_AbSocket);
}




int Server::findAbonent(const QTcpSocket *_sock)
{
    for(int i = 0 ; i < _vector.size(); i++)
    {
        if(_sock == _vector.at(i)->_AbSocket)return i;
    }
    return -1;
};


void Server::slot_return_Client()
{

  TempAbonent = findAbonent();
  if(TempAbonent != NULL)
  {
    _textedit2->setText("Send massage server to " + TempAbonent->_AbName + "\n" );
  }
};


Abonent* Server::findAbonent()
{
    for(int i = 0 ; i < _vector.size(); i++)
    {
     if(_textedit1->textColor() == _vector.at(i)->_color)return _vector.at(i);
    }
    return NULL;
};

void Server::clear_objeckts_in_vector()
{
    for(int i = 0 ; i < _vector.size(); i++)
    {
     delete _vector.at(i);
    }
    _vector.clear();

};

