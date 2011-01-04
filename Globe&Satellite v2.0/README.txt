 Earth & Satellite v2.0

– To call an QT-openGL widget within an interactive GUI. With checkbox features enabling 
pausing the rotation of individual objects (earth and satellite).

– Features: Custom widget QGLWidget, mouse press-move events, zooming and scaling, light 
components in openGL.

– Pressing mouse in the GL area of the window, and draging it would enable the rotation of 
the figure along the corresponding X-Y or X-Z axes. Giving the user a 3D navigation.(Click
in the GL window, and drag)

Accomplished in Qt & openGL, using QGLWidget. The design layout was achieved in Qt Designer.

Dependencies: OpenGl, Qt

To run it: Open gsphere.pro as a Qt creator project or

 If you do not want to use the QtCreator etc, you can use the qmake script to help generate a make file and build the executable. Here's how to do it.

1) install qt4-qmake -- A Qt4 qmake Makefile generator tool.
2) navigate to the directory, where the source code is present.
3) run qmake. This step generates a make file.
4) run make. This step builds the required executable

By: Chaitanya CH
based on

http://www.ohmpie.com/mountains
http://pages.cpsc.ucalgary.ca/~brosz/TA/453/designer/index2.html