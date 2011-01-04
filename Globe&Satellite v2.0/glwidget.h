
#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTime>

class QTimer;
class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void setScale(int scale1);
    void setZtrans(int value);
    void generate();
    void setERotation(int smooth);
    void setSPlace(int satellite); //setSatt
    void setSRotation(int satR); //setSRot

protected:
    void initializeGL();
    void paintGL();
    void keyPressEvent(QKeyEvent *event);
    void resizeGL(int width, int height);
    void changeEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:

    void normalizeAngle(int *angle);
    int setERot;
    int setSatt;
    int setSRot;
    GLuint object;
    int xRot;
    int yRot;
    int zRot;
    int zTran;
    double scale;
    void drawSatt();
    QPoint lastPos;
    QColor foreground;
    QColor background;
    QTimer *timer;
    QTime time;
    GLfloat xrot, yrot, zrot,zsrot;
    GLuint texture;
    GLUquadricObj *q;
};

#endif /*GLWIDGET_H*/
