#include <QCoreApplication>
#include <QNetworkRequest>
#include <QtSql>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QNetworkRequest request;
    request.setUrl(QUrl("https://cherepovets.hh.ru/"));
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setPort(5432);
    db.setDatabaseName("test_db");
    db.setUserName("postgres");
    db.setPassword("postgres");
    if(!db.open())
    {
    qDebug ()<<"ERROR: "<<QSqlError(db.lastError()).text();
    } else {
    qDebug ()<<"Ok";
    }

    return a.exec();
}
