// "single_application.h"

#ifndef SINGLEAPPLICATION_H
#define SINGLEAPPLICATION_H

#include <QApplication>
#include <QSharedMemory>
#include <QLocalServer>

class SingleApplication : public QApplication

{
    Q_OBJECT
public:

    SingleApplication(int &argc, char *argv[], const QString uniqueKey);
    bool isRunning();
    bool sendMessage(const QString &message);
public slots:
    void receiveMessage();
signals:
    void messageAvailable(QString message);
private:
    bool _isRunning;
    QString _uniqueKey;
    QSharedMemory sharedMemory;
    QLocalServer *localServer;
    static const int timeout = 1000;
};

class SingleApplicationWithSharedMemory : public QApplication
{
    Q_OBJECT
public:
    SingleApplicationWithSharedMemory(int &argc, char *argv[], const QString uniqueKey);
    bool isRunning();
    bool sendMessage(const QString &message);
public slots:
    void checkForMessage();
signals:
    void messageAvailable(QString message);
private:
    bool _isRunning;
    QSharedMemory sharedMemory;
};

#endif
