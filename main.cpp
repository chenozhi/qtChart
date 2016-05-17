#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{

//    QApplication app(argc, argv);
//    LineChart lc;
//    lc.show();
//    return app.exec();
    QApplication a(argc, argv);
    MainWindow w;

    QWidget* lc = new LineChart();


    w.setCentralWidget(lc);
    w.show();

    return a.exec();
}
