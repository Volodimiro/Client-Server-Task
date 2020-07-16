#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtWidgets>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>

class Client : public QObject //, public QTcpSocket
{
    Q_OBJECT
public:
    explicit Client(QTextEdit *hostIP, QTextEdit *port, QTextEdit *textedit1, QTextEdit *textedit2, QTextEdit *Name);
 QMessageBox _ms;

signals:

public slots:
  void  SlotConnectbutton();
  void  slotReadyRead();
  void  SlotSendToServer();

private:
    QHostAddress _hostAddress;

    QTcpSocket* _Clientsocket;
    QTextEdit *_hostIP, *_port, *_textedit1, *_textedit2, *_Name;
    QString _S_hostIP;//, _S_port, _S_texedit1, _S_texedit2 ;
    bool _status;
};

#endif // CLIENT_H
