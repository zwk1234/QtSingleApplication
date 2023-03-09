#include "mainwindow.h"

#include <QApplication>
#include "singleapplication.h"

int main(int argc, char *argv[])
{
    SingleApplicationWithSharedMemory app(argc, argv, "some unique key string");
    if (app.isRunning())
    {
        app.sendMessage("message from other instance.");
        return 0;
    }

    MainWindow *mainWindow = new MainWindow();

        // connect message queue to the main window.
    QObject::connect(&app, SIGNAL(messageAvailable(QString)), mainWindow, SLOT(receiveMessage(QString)));

        // show mainwindow.
    mainWindow->show();
    return app.exec();
}
