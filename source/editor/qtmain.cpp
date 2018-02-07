#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QCoreApplication>
#include <QDir>

#include <octoon/editor/mainwindow.h>
#include <octoon/editor/OMainWindow.h>
#include <octoon/editor/qtmain.h>


QString getQssContent(const QString &path)
{
	QFile styleSheet(path);
	if (!styleSheet.open(QIODevice::ReadOnly))
	{
		qWarning("Can't open the style sheet file.");
		qDebug() << QDir::currentPath();
		return "";
	}
	return styleSheet.readAll();
}

int qtmain(int argc, char *argv[])
{
    QApplication a(argc, argv);
    octoon::editor::OMainWindow w;
    w.show();

	a.setStyleSheet(getQssContent("resource/qss/default_qss.qss"));

    return a.exec();
}
