#include <QtGui/QApplication>
#include "gsphere.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gsphere w;
    w.show();
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));

    return a.exec();
}
