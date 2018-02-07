#ifndef OCTOON_OMAINWINDOW_H
#define OCTOON_OMAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QMenu>
#include <QMenuBar>

#include <octoon\editor\OTitleBar.h>

namespace octoon
{
    namespace editor
    {
        class OMainWindow:public QMainWindow
        {
            Q_OBJECT
        public:
            explicit OMainWindow(QWidget *parent = Q_NULLPTR)
                :QMainWindow(parent)
            {
                // layout
                windowCentralWidget = new QWidget(this);
                vLayout = new QVBoxLayout(windowCentralWidget);
                // titlebar
                setWindowFlags(Qt::FramelessWindowHint | windowFlags());
                titleBar = new OTitleBar(windowCentralWidget);
                menuBar = new QMenuBar(windowCentralWidget);
                installEventFilter(titleBar);

                setWindowTitle("MainWindow");
                setWindowIcon(QIcon(":/rsc/images/logo/logo.png"));

                vLayout->setMargin(0);
                vLayout->addWidget(titleBar);
                vLayout->addWidget(menuBar);
                vLayout->addWidget(&winFrame);

                windowCentralWidget->setLayout(vLayout);
				setCentralWidget(windowCentralWidget);
            }

            ~OMainWindow()
            {
            }
        protected:
            QMainWindow winFrame;
            QWidget * windowCentralWidget;
            QVBoxLayout *vLayout;
            OTitleBar *titleBar;
            QMenuBar *menuBar;
        };
    }

}


#endif // OCTOON_OMAINWINDOW_H