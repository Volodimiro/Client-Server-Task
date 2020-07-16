#include "widget.h"
#include "server.h"
#include <QtWidgets>


int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   Widget w;


  QTextEdit texedit1,texedit2, port;
  texedit1.setReadOnly(true);
  port.setText("2323");
  texedit1.setFontWeight(200);
  texedit2.setFontWeight(200);


  port.setFixedHeight(30);

  QPushButton button1("exit"),button2("Start Server"),button3("Send");
  QVBoxLayout VLayout;
  QHBoxLayout HLayout1,HLayout2;
  QLabel LClients, Label_Port;
  Server _ser(&LClients, &port, &texedit1, &texedit2);

  LClients.setFixedWidth(150);
  Label_Port.setText("PORT");
  Label_Port.setFixedWidth(50);
  port.setFixedSize(200,30);
  texedit2.setFixedHeight(200);

  HLayout1.addWidget(&LClients);
  HLayout1.addWidget(&Label_Port);
  HLayout1.addWidget(&port);
  HLayout1.addWidget(&button1);
  HLayout1.addWidget(&button2);
  VLayout.addLayout(&HLayout1);

  VLayout.addWidget(&texedit1);
  VLayout.addWidget(&texedit2);
  HLayout2.addWidget(&button3);

  VLayout.addLayout(&HLayout2);
  w.setLayout(&VLayout);
  w.setWindowTitle("<<Server>> test task indeema" );
  QObject::connect(&button1, SIGNAL(clicked()), qApp, SLOT(quit()));
  QObject::connect(&button2, SIGNAL(clicked()), &_ser, SLOT(StartServer()));
  QObject::connect(&button3, SIGNAL(clicked()), &_ser, SLOT(sendMessageClient()));
  QObject::connect(&texedit1, SIGNAL(selectionChanged()), &_ser, SLOT(slot_return_Client()));

  w.show();

    return a.exec();
}
