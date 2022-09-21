#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_UseOpenGLES);
    QApplication a(argc, argv);

    QFont f = QFont("Microsoft Yahei", 9);
    f.setStyleStrategy(QFont::PreferAntialias);
    a.setFont(f);

    //更改程序启动后任务栏图标
    a.setWindowIcon(QIcon(":/www/favicon.ico"));

    MainWindow w;
    w.showMaximized();
    return a.exec();
}
