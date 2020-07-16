#ifndef SERVER_H
#define SERVER_H
#include "widget.h"
#include <QObject>
#include <QtWidgets>
#include <QHostAddress>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QTime>
#include "abonent.h"


class Server: public QObject
{
Q_OBJECT
public:

    Server(QLabel *LClients, QTextEdit *port, QTextEdit *textedit1, QTextEdit *textedit2);
    ~Server()
    {}

    //void retransmit();
 void sendToClient(QTcpSocket*);
 int findAbonent(const QTcpSocket*);
 Abonent* findAbonent();
 void clear_objeckts_in_vector();
public slots:
 void  StartServer();
 void slotNewConnection();
 void slotReadClient();
 void disconnect();
 void sendMessageClient();
 void slot_return_Client();

private:
QHostAddress _hostAddress;
QTcpServer _server;
QTcpSocket* _Clientsocket;
QTextEdit  *_port, *_textedit1, *_textedit2;
QLabel *_LClients;
QVector<Abonent*> _vector;
Abonent *_Abonent, *TempAbonent;
QTime _time;
QDate _date;
QMessageBox _ms;
int _clients;
bool status;
};

#endif // SERVER_H
