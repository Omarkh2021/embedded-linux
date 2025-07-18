#include <QCoreApplication>
#include <QTcpSocket>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QTcpSocket socket;
    socket.connectToHost("192.168.1.13", 1234);  // Replace with host machine IP

    if (socket.waitForConnected(3000)) {
        qDebug() << "Connected to server";

        socket.write("ON");
        socket.flush();
        socket.waitForBytesWritten(1000);
        socket.disconnectFromHost();
    } else {
        qDebug() << "Connection failed.";
    }

    return 0;
}
