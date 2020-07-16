#include "widget.h"
#include <QApplication>
#include <QtWidgets>
#include "client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;


  QTextEdit texedit1,texedit2, IPadress, port, Name;
  IPadress.setFixedHeight(30);
  port.setFixedHeight(30);
  IPadress.setText("127.0.0.1");
  port.setText("2323");
  texedit1.setFontWeight(200);
  texedit2.setFontWeight(200);


  QPushButton button1("exit"),button2("Connect"),button3("Send");
  QVBoxLayout VLayout;
  QHBoxLayout HLayout1,HLayout2;
  QLabel Label_IP, Label_Port, LName;
  Client _client(&IPadress, &port, &texedit1, &texedit2, &Name);

  Label_IP.setText("IP adress");
  Label_Port.setText("PORT");
  LName.setText("Name");
  Label_IP.setFixedWidth(50);
  Label_Port.setFixedWidth(50);
  LName.setFixedWidth(50);

  IPadress.setFixedSize(200,30);
  port.setFixedSize(100,30);
  texedit2.setFixedHeight(200);
  Name.setFixedSize(100,30);

  HLayout1.addWidget(&Label_IP);
  HLayout1.addWidget(&IPadress);
  HLayout1.addWidget(&Label_Port);
  HLayout1.addWidget(&port);
  HLayout1.addWidget(&LName);
  HLayout1.addWidget(&Name);

  HLayout1.addWidget(&button1);
  HLayout1.addWidget(&button2);
  VLayout.addLayout(&HLayout1);

  VLayout.addWidget(&texedit1);
  VLayout.addWidget(&texedit2);
  HLayout2.addWidget(&button3);

  VLayout.addLayout(&HLayout2);
  w.setLayout(&VLayout);
  w.setWindowTitle("<<Client>> test task indeema" );

  QObject::connect(&button1, SIGNAL(clicked()), qApp, SLOT(quit()));
  QObject::connect(&button2, SIGNAL(clicked()), &_client, SLOT(SlotConnectbutton()));
  QObject::connect(&button3, SIGNAL(clicked()), &_client, SLOT(SlotSendToServer()));


  w.show();

    return a.exec();
}
