#include <QApplication>

#include <octoon/editor/mainwindow.h>
#include <octoon/editor/qtmain.h>

int qtmain(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
