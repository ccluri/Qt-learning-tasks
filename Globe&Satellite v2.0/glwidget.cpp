#include <QtGui>
#include <QtOpenGL>
#include "gsphere.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include "glwidget.h"


 GLWidget::GLWidget(QWidget *parent)
     : QGLWidget(parent)
 {
     object = 0;
     xRot = 0;//-360*2;
     yRot = 0;//(int) (-360*.5);
     zRot = 0;
     zTran =0;
     scale =20.0;

     background = QColor::fromRgb(0,0,0);
     time = QTime::currentTime();
     timer = new QTimer(this);
     timer->setSingleShot(true);
     connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
 }

 GLWidget::~GLWidget() {
     glDeleteTextures(1, &texture);
 }

 QSize GLWidget::minimumSizeHint() const
 {
     return QSize(50, 50);
 }

 QSize GLWidget::sizeHint() const
 {
     return QSize(400, 400);
 }

 void GLWidget::setXRotation(int angle)
 {
     normalizeAngle(&angle);
     if (angle != xRot) {
         xRot = angle;
         updateGL();
     }
 }

 void GLWidget::setYRotation(int angle)
 {
     normalizeAngle(&angle);
     if (angle != yRot) {
         yRot = angle;
         updateGL();
     }
 }

 void GLWidget::setZRotation(int angle)
 {
     normalizeAngle(&angle);
     if (angle != zRot) {
         zRot = angle;
         updateGL();
     }
 }

 void GLWidget::setZtrans(int value){
         zTran = value;
         updateGL();
 }

 void GLWidget::setScale(int scale1) {

         double min = .5;
         double max = 2;
         double p = (double)scale1 / 100;
         scale = min + p*(max-min);
         updateGL();
 }


 void GLWidget::setERotation(int smooth) {

         if(smooth == Qt::Checked)
                 setERot =1;


         if(smooth == Qt::Unchecked)
                 setERot =0;

         updateGL();

 }
 void GLWidget::setSPlace(int satellite) {

         if(satellite == Qt::Checked)
                 setSatt =1;


         if(satellite == Qt::Unchecked)
                 setSatt =0;

         updateGL();

 }
 void GLWidget::setSRotation(int satR) {

         if(satR == Qt::Checked)
                 setSRot =1;


         if(satR == Qt::Unchecked)
                 setSRot =0;

         updateGL();

 }
 void GLWidget::initializeGL()
 {
     qglClearColor(background);
     //object = makeObject(); //calls random triangles

     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);

     // Create light components
     GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
     GLfloat diffuseLight[] = { 1.0f, 1.0f, 1.0, 1.0f };
     GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
     GLfloat position[] = { 150.0f, 0.0f, 300.0f, 1.0f };

     // Assign created components to GL_LIGHT0
     glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
     glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
     glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
     glLightfv(GL_LIGHT0, GL_POSITION, position);


     glShadeModel(GL_SMOOTH);
     //glEnable(GL_CULL_FACE);
     glClearDepth(1.0f); // Depth buffer setup
     glEnable(GL_DEPTH_TEST); // Enable depth testing
     glDepthFunc(GL_LEQUAL); // Set type of depth test

     q = gluNewQuadric();							// Create A New Quadratic
             gluQuadricNormals(q, GL_SMOOTH);					// Generate Smooth Normals For The Quad
             gluQuadricTexture(q, GL_TRUE);						// Enable Texture Coords For The Quad

             glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);			// Set Up Sphere Mapping
             glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really nice perspective calculations

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    texture = bindTexture(QPixmap(":/img/wmap.bmp"));
    glEnable(GL_TEXTURE_2D);
 }

 void GLWidget::paintGL()
 {

     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glLoadIdentity();
     //glTranslated( 0, 0 , zTran);
   // glScaled(scale,scale,scale);
     glRotated(xRot / 16.0, 1.0, 0.0, 0.0);
     glRotated(yRot / 16.0, 0.0, 1.0, 0.0);
     glRotated(zRot / 16.0, 0.0, 0.0, 1.0);
     glRotatef(-90, 1.0f, 0.0f, 0.0f);
     glRotatef(zrot, 0.0f, 0.0f, 1.0f);
     if (setERot==1)
     {

         { zrot += 0.2f; // Z-axis rotation

         // Framerate control
         int delay = time.msecsTo(QTime::currentTime());
         if (delay == 0)
             delay = 1;
         time = QTime::currentTime();
         timer->start(qMax(0, 20 - delay));


        }
     }
     glColor3f(1.0f, 1.0f, 1.0f);
     glScalef(-1,-1,-1);
     gluSphere(q, 80.0f, 32, 16);
     //glBindTexture(GL_TEXTURE_2D, texture);
     if (setSatt==1)
     {
         drawSatt();
     }



 }
     void GLWidget::drawSatt() {

         glRotatef(45.0f,0.0f,1.0f,0.0f);
         glRotatef(3*(zsrot), 0.0f, 0.0f, 1.0f);
         if (setSRot==1)
         {

         { zsrot += 1.0f; // Z-axis rotation

         // Framerate control
         int delay = time.msecsTo(QTime::currentTime());
         if (delay == 0)
             delay = 1;
         time = QTime::currentTime();
         timer->start(qMax(0, 20 - delay));
         }
         }
         glTranslatef(82.0f, 0.0f, 0.0f);
         glColor3f(1.0f, 0.0f, 0.0f);						// Set Color To Red
         glBegin(GL_QUADS); // Begin drawing the quad

             glVertex3f(0.0f,  3.03f, 3.03f); // Top Left
             glVertex3f( 0.0f,  3.03f, -3.03); // Top Right
             glVertex3f( 0.0f, -3.03f, -3.03f); // Bottom Right
             glVertex3f(0.0f, -3.03f, 3.03f); // Bottom Left
         glEnd(); // End drawing the quad

                                             // Disable Blending
     }
 void GLWidget::resizeGL(int width, int height)
 {
     int side = qMin(width, height);
     glViewport((width - side) / 2, (height - side) / 2, side, side);

     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     //glOrtho(-0.5, +0.5, +0.5, -0.5, 4.0, 15.0);
     glOrtho(-200, 200, -200, 200, -200, 200.0);
     glMatrixMode(GL_MODELVIEW);
 }
 void GLWidget::mousePressEvent(QMouseEvent *event)
 {
     lastPos = event->pos();
 }

 void GLWidget::mouseMoveEvent(QMouseEvent *event)
 {
     int dx = event->x() - lastPos.x();
     int dy = event->y() - lastPos.y();

     if (event->buttons() & Qt::LeftButton) {
         setXRotation(xRot + 8 * dy);
         setYRotation(yRot + 8 * dx);
     } else if (event->buttons() & Qt::RightButton) {
         setXRotation(xRot + 8 * dy);
         setZRotation(zRot + 8 * dx);
     }
     lastPos = event->pos();
 }



 void GLWidget::generate() {  // button click
     // glCallList(object);

 }

 void GLWidget::normalizeAngle(int *angle)
 {
     while (*angle < 0)
         *angle += 360 * 16;
     while (*angle > 360 * 16)
         *angle -= 360 * 16;
 }
 void GLWidget::keyPressEvent(QKeyEvent *event) {
     switch (event->key()) {
     case Qt::Key_Escape:
         close(); // Quit on Escape
         break;
     case Qt::Key_F1:
         setWindowState(windowState() ^ Qt::WindowFullScreen); // Toggle fullscreen on F1
         break;
     default:
         QGLWidget::keyPressEvent(event); // Let base class handle the other keys
     }
 }

 void GLWidget::changeEvent(QEvent *event) {
     switch (event->type()) {
     case QEvent::WindowStateChange:
         // Hide cursor if the window is fullscreen, otherwise show it
         if (windowState() == Qt::WindowFullScreen)
             setCursor(Qt::BlankCursor);
         else
             unsetCursor();
         break;
     default:
         break;
     }
 }

