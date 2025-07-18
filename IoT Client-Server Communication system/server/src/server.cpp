#include <QApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

class Server : public QWidget {
    Q_OBJECT
public:
    Server(QWidget *parent = nullptr) : QWidget(parent) {
        textEdit = new QTextEdit(this);
        textEdit->setReadOnly(true);

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(textEdit);
        setLayout(layout);

        server = new QTcpServer(this);
        connect(server, &QTcpServer::newConnection, this, &Server::handleNewConnection);

        if (!server->listen(QHostAddress::AnyIPv4, 1234)) {
            textEdit->append("❌ Server failed to start");
        } else {
            textEdit->append("✅ Server started on port 1234");
        }
    }

public slots:
    void handleNewConnection() {
        QTcpSocket *clientSocket = server->nextPendingConnection();
        textEdit->append("📡 Client connected");

        connect(clientSocket, &QTcpSocket::readyRead, [this, clientSocket]() {
            QByteArray data = clientSocket->readAll();
            QString message = QString("Received: %1").arg(QString(data));
            textEdit->append(message);

            if (data.trimmed() == "ON") {
                textEdit->append("💡 LED Status: ON");
            } else if (data.trimmed() == "OFF") {
                textEdit->append("💡 LED Status: OFF");
            }
        });

        connect(clientSocket, &QTcpSocket::disconnected, [this]() {
            textEdit->append("❌ Client disconnected");
        });
    }

private:
    QTcpServer *server;
    QTextEdit *textEdit;
};

#include "server.moc"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Server serverApp;
    serverApp.setWindowTitle("IoT Server GUI");
    serverApp.resize(400, 300);
    serverApp.show();
    return app.exec();
}
