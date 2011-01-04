#ifndef GSPHERE_H
#define GSPHERE_H

#include <QMainWindow>
#include <QtGui>
#include "ui_gsphere.h"

//namespace Ui {
//    class gsphere;
//}

class gsphere : public QMainWindow
{
    Q_OBJECT

public:
    explicit gsphere(QWidget *parent = 0);
    ~gsphere();

private:
    Ui::gsphere *ui;
protected:
        void resizeEvent ( QResizeEvent * event );
};

#endif // GSPHERE_H
