import sys, os, random
from PyQt4 import QtGui, QtCore

from numpy import arange, sin, pi
from matplotlib.backends.backend_qt4agg import FigureCanvasQTAgg as FigureCanvas

from matplotlib.backends.backend_qt4agg import NavigationToolbar2QTAgg as NavigationToolbar
from matplotlib.figure import Figure
#http://www.mail-archive.com/matplotlib-users@lists.sourceforge.net/msg13241.html

progname = os.path.basename(sys.argv[0])
progversion = "0.1"

class MyMplCanvas(FigureCanvas):
    """Ultimately, this is a QWidget (as well as a FigureCanvasAgg, etc.)."""
    def __init__(self, parent=None, width=5, height=4, dpi=100):
        fig = Figure(figsize=(width, height), dpi=dpi)

        self.axes = fig.add_subplot(111)
        self.axes.set_navigate(True)
        # We want the axes cleared every time plot() is called
        self.axes.hold(False)

        self.compute_initial_figure()

        #
        FigureCanvas.__init__(self, fig)
        self.setParent(parent)

        FigureCanvas.setSizePolicy(self,
                                   QtGui.QSizePolicy.Expanding,
                                   QtGui.QSizePolicy.Expanding)
        FigureCanvas.updateGeometry(self)

    def compute_initial_figure(self):
        pass

class MyStaticMplCanvas(MyMplCanvas):
    """Simple canvas with a sine plot."""

    def __init__(self,*args,**kwargs):
        MyMplCanvas.__init__(self,*args,**kwargs)
        self.mpl_connect('pick_event',self.onpick)
	x=arange(-2*pi,2*pi,0.001)
	y=sin(x)	
	self.axes.plot(x,y)


    #def compute_initial_figure(self):
        #G=nx.star_graph(20)
        #pos=nx.graphviz_layout(G)
        #nodes = nx.draw_networkx_nodes(G,pos,ax=self.axes)
        #print nodes
        #nodes.set_picker(True)
        #edges = nx.draw_networkx_edges(G,pos,ax=self.axes)
        #self._labels = range(len(G.nodes()))
        #labels=dict(zip(self._labels,self._labels))
        #nx.draw_networkx_labels(G, pos, ax=self.axes,labels=labels)




    def onpick(self,event):
        ind=event.ind[0]
        print self._labels[ind]
        return True

class ApplicationWindow(QtGui.QMainWindow):
    def __init__(self):
        QtGui.QMainWindow.__init__(self)
        self.setAttribute(QtCore.Qt.WA_DeleteOnClose)
        self.setWindowTitle("application main window")

        self.file_menu = QtGui.QMenu('&File', self)
        self.file_menu.addAction('&Quit', self.fileQuit,
                                 QtCore.Qt.CTRL + QtCore.Qt.Key_Q)
        self.menuBar().addMenu(self.file_menu)

        self.help_menu = QtGui.QMenu('&Help', self)
        self.menuBar().addSeparator()
        self.menuBar().addMenu(self.help_menu)

        self.help_menu.addAction('&About', self.about)

        self.main_widget = QtGui.QWidget(self)

        l = QtGui.QVBoxLayout(self.main_widget)
        sc = MyStaticMplCanvas(self.main_widget, width=5, height=3, dpi=100)

        l.addWidget(sc)

        bar = NavigationToolbar(sc,self)
        l.addWidget(bar)
        self.main_widget.setFocus()
        self.setCentralWidget(self.main_widget)



    def fileQuit(self):
        self.close()

    def closeEvent(self, ce):
        self.fileQuit()

    def about(self):
        QtGui.QMessageBox.about(self, "About %s" % progname,
u"""%(prog)s version %(version)s
Copyright \N{COPYRIGHT SIGN} 2005 Florent Rougon, 2006 Darren Dale

This program is a simple example of a Qt4 application embedding matplotlib
canvases.

It may be used and modified with no restriction; raw copies as well as
modified versions may be distributed without limitation."""
% {"prog": progname, "version": progversion})

qApp = QtGui.QApplication(sys.argv)

aw = ApplicationWindow()
aw.setWindowTitle("%s" % progname)
aw.show()
sys.exit(qApp.exec_())
