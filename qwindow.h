#ifndef QWINDOW_H
#define QWINDOW_H

#include <QString>
#include <QIcon>
#include <QX11Info>
#include "panel.h"

#include <X11/Xlib.h>

class QWindow
{
public:
    QWindow();
    QWindow(Window id);
    Window id;
    QString title,wmname,icname;
    QIcon icon;
    QRect geometry;
    Panel* currentPanel;
    int tabIndex;
    bool dialog;

    void getWMName();
};

#endif // QWINDOW_H
