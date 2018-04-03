#include "mainwindow.h"
#include <QApplication>
#include <QSettings>
#include <QDir>

void appAutoRun(bool bAutoRun)
{
    // for all users
    //HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run

    //for current user.Do not need the admin power
    //HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run
    QSettings  reg("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",QSettings::NativeFormat);
    QString strAppPath=bAutoRun ? QDir::toNativeSeparators(QCoreApplication::applicationFilePath()) :
    QString();
    //strAppPath.replace(QChar('/'),QChar('\\'),Qt::CaseInsensitive);
    reg.setValue("wirtepad",strAppPath);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    appAutoRun(true);
    MainWindow w;
    w.show();

    return a.exec();
}
