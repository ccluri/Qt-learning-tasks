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