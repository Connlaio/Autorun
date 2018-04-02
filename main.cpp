#include "mainwindow.h"
#include <QApplication>

//#include <winreg.h>
#include <QDebug>

#include <QSettings>
#include <QDir>

void appAutoRun(bool bAutoRun)
{
    // for all users
    //HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run

    //for current user.Do not need the admin power
    //HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run
    QSettings  reg("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",QSettings::NativeFormat);

    if (bAutoRun)
    {
         QString strAppPath=QDir::toNativeSeparators(QCoreApplication::applicationFilePath());
        //strAppPath.replace(QChar('/'),QChar('\\'),Qt::CaseInsensitive);
        reg.setValue("wirtepad",strAppPath);
    }
    else
    {
        reg.setValue("wirtepad","");
    }

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    appAutoRun(true);
    MainWindow w;
    w.show();

    return a.exec();
}
