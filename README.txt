Simple Adder - cpp

– Performs  simple addition of two integer numbers, inputs and the output displayed via a UI.

– Features: Line Editors, Push Button

Accomplished using Qt. The design layout was accomplished in Qt Designer.

Dependencies: Qt

To run it: Open as a Qt creator project or

 If you do not want to use the QtCreator etc, you can use the qmake script to help generate a make file and build the executable. Here's how to do it.

1) install qt4-qmake -- A Qt4 qmake Makefile generator tool.
2) navigate to the directory, where the source code is present.
3) run qmake. This step generates a make file.
4) run make. This step builds the required executable

By: Chaitanya CH

Simple Adder - py

– Performs  simple addition of two integer numbers, inputs and the output displayed via a UI.

– Features: Line Editors, Push Button

Accomplished using PyQt. The design layout was accomplished in Qt Designer.

Dependencies: Python, numpy, pyqt

To run it: 
python simpleadder.py

By: Chaitanya CH

Graph Plotter

– Given the range,step of x, and f(x) as inputs, will plot f(x), in a graph with 2 axes, denote the 
x,y scales and grid lines in an interactive GUI. The xRange and f(x) accept all numpy 
recognizable formats. For example pi/2, sin(x), log(x**2) etc.

– Features:  Custom Qt widget, numpy, Matplotlib, Navigation toolbar (of matplotlib)

– The Navigation toolbar was included in the UI, to enable zooming, panning, saving a graph 
as '.png'. Also the previous view, next view and first view buttons of the same are functional.

Accomplished in PyQt using matplotlib. The design layout of this was carried in Qt Designer. 
Matplotlib was added as a custom widget. 

Input Syntax: 
Line1 xStart,xStop,xStep
Line2 f(x)

Sample Input:
Line1: -2*pi,2*py,0.001
Line2: sin(x)

Press "Draw" button to refresh plot


Dependencies: Python, numpy, matplotlib,pyqt.

To run it: 
python Gppyqt.py

Next: Further features to this could include enabling of 3D plotting by implementing a custom widget fo
mplot3d.

By: Chaitanya CH
based on:

http://nullege.com/codes/show/src%40o%40b%40obspy-HEAD%40apps%40_templates%40pyqt_matplotlib_with_toolbar.py/17/matplotlib.backends.backend_qt4agg.NavigationToolbar2QTAgg/python
http://code.google.com/p/subplot/source/browse/branches/mzViewer/PyMZViewer/mpl_custom_widget.py
http://eli.thegreenplace.net/files/prog_code/qt_mpl_bars.py.txt
http://lionel.textmalaysia.com/a-simple-tutorial-on-gui-programming-using-qt-designer-with-pyqt4.html
http://www.mail-archive.com/matplotlib-users@lists.sourceforge.net/msg13241.html
 
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