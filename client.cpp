#include "wmapp.h"
#include "client.h"

Client::Client()
{
}

Client::Client(Window id) : id(id), dialog(false)
{
    getWMName();
}

void Client::getWMName()
{
        char *name;
        Client *client;
        QString oldwname = wmname;
        QString oldiname = icname;
        Atom type;
        int format;
        unsigned long nitems=0;
        unsigned long extra=0;
        unsigned char *data=NULL;

        XGetWindowProperty(QX11Info::display(), id, WMApp::netatom[NetWMName], 0, 500, false, AnyPropertyType, &type, &format, &nitems, &extra, &data);

        if(data != NULL)
        {
            wmname = QString::fromUtf8((char *)data);
            XFree(data);
        }
        else if(XFetchName(QX11Info::display(), id, &name) && name != NULL)
        {
            wmname = name;
            XFree(name);
        }

        data = NULL;
        XGetWindowProperty(QX11Info::display(), id, WMApp::netatom[NetWMIconName], 0, 500, False, AnyPropertyType, &type, &format, &nitems, &extra, &data);

        if(data != NULL)
        {
            icname = QString::fromUtf8((char *)data);
            XFree(data);
        }
        else if(XGetIconName(QX11Info::display(), id, &name) && name != NULL)
        {
            icname = name;
            XFree(name);
        }
        else
            icname = wmname;
}
