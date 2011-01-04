#include "gsphere.h"
#include "glwidget.h"
#include <QFileDialog>


gsphere::gsphere(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::gsphere)
{
    ui->setupUi(this);

    connect(ui->checkBox,SIGNAL(stateChanged(int)),ui->glWindow,SLOT(setERotation(int)));
    connect(ui->checkBox_2,SIGNAL(stateChanged(int)),ui->glWindow,SLOT(setSPlace(int)));
    connect(ui->checkBox_2,SIGNAL(toggled(bool)),ui->checkBox_3,SLOT(setEnabled(bool)));
    connect(ui->checkBox_2,SIGNAL(toggled(bool)),ui->checkBox_3,SLOT(setChecked(bool)));
    connect(ui->checkBox_3,SIGNAL(stateChanged(int)),ui->glWindow,SLOT(setSRotation(int)));

}

gsphere::~gsphere()
{
    //delete ui;
}
void gsphere::resizeEvent (QResizeEvent *) {

        //Get the current main window width and height
        int w = width();
        int h = height();

        //Rezise layout and glWindow
        //ui->gridLayout->setGeometry(QRect(w, 0, 200, h));
        //ui->glWindow->setGeometry(QRect(0,0,w,h));
}
