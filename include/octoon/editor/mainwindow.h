#ifndef OCTOON_MAINWINDOW_H
#define OCTOON_MAINWINDOW_H

#include <QMainWindow>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

};

#endif // OCTOON_MAINWINDOW_H
