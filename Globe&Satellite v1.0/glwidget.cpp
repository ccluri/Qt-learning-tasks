
#include "glwidget.h"
#include <QKeyEvent>
#include <QTimer>

//http://nehe.gamedev.net/data/lessons/lesson.asp?lesson=26
//http://wesley.vidiqatch.org/03-08-2009/nehe-opengl-lessons-in-qt-chapter-1-and-2/
//http://www.opengl.org/discussion_boards/ubbthreads.php?ubb=showflat&Number=262416


// Constructor
GLWidget::GLWidget() {
    setWindowTitle("Earth & Satellite v1.0");
    time = QTime::currentTime();
    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
}

// Destructor
GLWidget::~GLWidget() {
    glDeleteTextures(1, &texture);
}

// Initialize OpenGL
void GLWidget::initializeGL() {
    glShadeModel(GL_SMOOTH); // Enable smooth shading
    qglClearColor(Qt::black); // Set the clear color to a black background

    q = gluNewQuadric();							// Create A New Quadratic
            gluQuadricNormals(q, GL_SMOOTH);					// Generate Smooth Normals For The Quad
            gluQuadricTexture(q, GL_TRUE);						// Enable Texture Coords For The Quad

            glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);			// Set Up Sphere Mapping
            glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);			// Set Up Sphere Mapping



    glClearDepth(1.0f); // Depth buffer setup
    glEnable(GL_DEPTH_TEST); // Enable depth testing
    glDepthFunc(GL_LEQUAL); // Set type of depth test

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really nice perspective calculations

    // Set up texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    texture = bindTexture(QPixmap(":/img/NeHe.bmp"));
    glEnable(GL_TEXTURE_2D);
}

// This is called when the OpenGL window is resized
void GLWidget::resizeGL(int width, int height) {
    // Prevent divide by zero (in the gluPerspective call)
    if (height == 0)
        height = 1;

    glViewport(0, 0, width, height); // Reset current viewport

    glMatrixMode(GL_PROJECTION); // Select projection matrix
    glLoadIdentity(); // Reset projection matrix

    gluPerspective(45.0f, static_cast<GLfloat>(width)/height, 0.1f, 100.0f); // Calculate aspect ratio

    glMatrixMode(GL_MODELVIEW); // Select modelview matrix
    glLoadIdentity(); // Reset modelview matrix
}
void GLWidget::drawSatt() {
    glTranslatef(1.0f, 0.0f, 0.0f);
    glColor3f(1.5f, 0.0f, 0.0f);						// Set Color To White
    glBegin(GL_QUADS); // Begin drawing the quad
        glVertex3f(0.0f,  0.03f, 0.03f); // Top Left
        glVertex3f( 0.0f,  0.03f, -0.03); // Top Right
        glVertex3f( 0.0f, -0.03f, -0.03f); // Bottom Right
        glVertex3f(0.0f, -0.03f, 0.03f); // Bottom Left
    glEnd(); // End drawing the quad



                                        // Disable Blending
}

// Draw a cube using OpenGL
void GLWidget::drawCube() {

    glColor3f(1.0f, 1.0f, 1.0f);						// Set Color To White
    glBindTexture(GL_TEXTURE_2D, texture);				// Select Texture 2 (1)
glScalef(-1,-1,-1);
    gluSphere(q, 1.0f, 32, 16);

}

// OpenGL painting code goes here
void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear screen and depth buffer

    // Draw cube
    glLoadIdentity(); // Reset current modelview matrix
    glTranslatef(0.0f, 0.0f, -5.0f); // Move 5 units into the screen
    glRotatef(-90.0f,1.0f,0.0f,0.0f);
    //glRotatef(-23.0f,0.0f,1.0f,0.0f);
    //glRotatef(xrot, 1.0f, 0.0f, 0.0f); // Rotate on X-axis
    //glRotatef(yrot, 0.0f, 1.0f, 0.0f); // Rotate on Y-axis

    glRotatef(zrot, 0.0f, 0.0f, 1.0f); // Rotate on Z-axis
    drawCube();
    glRotatef(23.0f,0.0f,1.0f,0.0f);
    glRotatef(3*(zrot), 0.0f, 0.0f, 1.0f);
    drawSatt();
    //xrot += 0.9f; // X-axis rotation
    //yrot += 0.6f; // Y-axis rotation
    zrot += 0.2f; // Z-axis rotation

    // Framerate control
    int delay = time.msecsTo(QTime::currentTime());
    if (delay == 0)
        delay = 1;
    time = QTime::currentTime();
    timer->start(qMax(0, 20 - delay));
}

// Key handler
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
