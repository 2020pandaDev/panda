#include "ctcpsv.h"
#include <QHostAddress>



CTcpSv::CTcpSv(QObject *parent):QTcpServer (parent)
{

}

void CTcpSv::incomingConnection(qintptr socketDescriptor)
{

   emit sendSocket(socketDescriptor);

}

