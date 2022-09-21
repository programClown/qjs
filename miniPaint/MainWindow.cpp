#include "MainWindow.h"

#include <QWebEngineView>
#include <QWebChannel>
#include <QWebEngineProfile>

class MainWindow::Private
{
public:
    Private() : webChannel(nullptr), webEngineView(nullptr) { }

    QWebChannel *webChannel;
    QWebEngineView *webEngineView;
};

MainWindow::MainWindow(QWidget *parent) : d(new Private()), QMainWindow(parent)
{
    d->webChannel    = new QWebChannel(this);
    d->webEngineView = new QWebEngineView(this);
    setCentralWidget(d->webEngineView);

    d->webChannel->registerObject(QString("motionityapp"), this);
    d->webEngineView->page()->setWebChannel(d->webChannel);

    connect(d->webEngineView, &QWebEngineView::loadFinished, this, &MainWindow::onLoadFinished);

    //加载html
    d->webEngineView->setContextMenuPolicy(Qt::NoContextMenu);
    d->webEngineView->load(QUrl("qrc:/www/index.html"));
    d->webEngineView->show();
}

MainWindow::~MainWindow() { }

void MainWindow::onLoadFinished(bool) { }
