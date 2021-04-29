#include "desktop.h"
#include <QDebug>
#include <QWebEngineView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

Desktop::Desktop(QDesktopWidget* desktop,QWidget *parent) :
    QFrame(parent)
{
    setFocusPolicy(Qt::StrongFocus);
      // Изменять размеры QML объекта под размеры окна
    //setResizeMode(QDeclarativeView::SizeRootObjectToView);

    QRect geom = desktop->screenGeometry();
    //rootContext()->setContextProperty("window", this);
    setWindowFlags(Qt::X11BypassWindowManagerHint | Qt::FramelessWindowHint);
    //setSource(QUrl::fromLocalFile("desktop.qml"));
    //root = rootObject();
    setGeometry(geom);
    QVBoxLayout *layout =new QVBoxLayout();
    setLayout(layout);
    QWebEngineView *view = new QWebEngineView(this);
    view->load(QUrl("https://www.google.com/"));
    layout->addWidget(view);
    QFrame *bottomBar = new QFrame(this);
    layout->addWidget(bottomBar);
    
    QHBoxLayout *barlayout =new QHBoxLayout();
    bottomBar->setLayout(barlayout);
    barlayout->addWidget(new QPushButton("Test"));
}

Desktop::~Desktop()
{

}

QRect Desktop::getWorkflow()
{
   /*
    QObject* workflow = root->findChild<QObject*>("workflow");
    workflowRect.setX(QDeclarativeProperty::read((QObject*)workflow, "x").toInt());
    workflowRect.setY(QDeclarativeProperty::read((QObject*)workflow, "y").toInt());
    workflowRect.setHeight(QDeclarativeProperty::read((QObject*)workflow, "height").toInt());
    workflowRect.setWidth(QDeclarativeProperty::read((QObject*)workflow, "width").toInt());
    */
    return workflowRect;
}

//void Desktop::chooseClient(int index)
//{
//}

void Desktop::runProcess(QString str)
{
    QStringList command = str.split(" ");
    QProcess::startDetached(command.takeFirst(),command);
}

