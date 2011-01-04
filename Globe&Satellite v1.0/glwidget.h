
#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTime>

class QTimer;

class GLWidget : public QGLWidget {
    Q_OBJECT

public:
    GLWidget();
    ~GLWidget();

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void keyPressEvent(QKeyEvent *event);
    void changeEvent(QEvent *event);

private:
    void drawCube();
    void drawSatt();
    QTimer *timer;
    QTime time;
    GLfloat xrot, yrot, zrot;
    GLuint texture;
    GLUquadricObj *q;
};

#endif // GLWIDGET_H
