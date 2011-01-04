 Earth & Satellite v1.0

– To display in a window, the earth on a sphere as a texture, and place a satellite (a small square) which rotates around the spinning earth at a different angle.

– Features: QGLWidget, shapes and colors, texture mapping, Rotate-Translate figures, key 
press events, resizing and frame rate control in openGL. 

Accomplished in Qt & openGL, using QGLWidget. 

Dependencies: OpenGl, Qt

To run it: Open sphere1.pro as a Qt creator project or

 If you do not want to use the QtCreator etc, you can use the qmake script to help generate a make file and build the executable. Here's how to do it.

1) install qt4-qmake -- A Qt4 qmake Makefile generator tool.
2) navigate to the directory, where the source code is present.
3) run qmake. This step generates a make file.
4) run make. This step builds the required executable

By: Chaitanya CH
based on

http://nehe.gamedev.net/data/lessons/lesson.asp?lesson=26
http://wesley.vidiqatch.org/03-08-2009/nehe-opengl-lessons-in-qt-chapter-1-and-2/
http://www.opengl.org/discussion_boards/ubbthreads.php?ubb=showflat&Number=262416