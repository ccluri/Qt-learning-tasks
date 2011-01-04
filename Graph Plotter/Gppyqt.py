# used to parse files more easily
from __future__ import with_statement
# Numpy module
import numpy as np
from numpy import *
# for command-line arguments
import sys
from matplotlib.backends.backend_qt4agg import NavigationToolbar2QTAgg as NavigationToolbar
# Qt4 bindings for core Qt functionalities (non-GUI)
from PyQt4 import QtCore
from PyQt4.QtCore import QEvent, Qt
# Python Qt4 bindings for GUI objects
from PyQt4 import QtGui
# import the MainWindow widget from the converted .ui files
from Gplotter import Ui_GpMainWindow
class DesignerMainWindow(QtGui.QMainWindow, Ui_GpMainWindow):
    """Customization for Qt Designer created window"""
    def __init__(self, parent = None):
        # initialization of the superclass
        super(DesignerMainWindow, self).__init__(parent)
        # setup the GUI --> function generated by pyuic4
        self.setupUi(self)
	#Place Navigation Tool in the plot
	#http://nullege.com/codes/show/src%40o%40b%40obspy-HEAD%40apps%40_templates%40pyqt_matplotlib_with_toolbar.py/17/
	#matplotlib.backends.backend_qt4agg.NavigationToolbar2QTAgg/python
	qToolBar = QtGui.QToolBar()
        self.toolbar = NavigationToolbar(self.Mpl, qToolBar)
	qToolBar.addWidget(self.toolbar)
        qToolBar.setMovable(False)
        qToolBar.setFloatable(False)
        self.addToolBar(Qt.BottomToolBarArea, qToolBar)
	# connect the signals with the slots
        QtCore.QObject.connect(self.GppushButton, QtCore.SIGNAL("clicked()"), self.update_graph)
	QtCore.QObject.connect(self.GpradioButton2, QtCore.SIGNAL("clicked()"), self.clickradio2)
	QtCore.QObject.connect(self.GpradioButton, QtCore.SIGNAL("clicked()"), self.clickradio1)
       
    
    def update_graph(self):
       
	u = "x=arange("+self.GplineEdit.text()+")"
	v = "y="+self.GplineEdit_2.text()	
	#execute function
	exec(str(u))
	exec(str(v))
	# clear the Axes
        self.Mpl.axes.clear()
	self.Mpl.axes.plot(x,y)    
	#grid    
	self.Mpl.axes.get_xaxis().grid(True)
	self.Mpl.axes.get_yaxis().grid(True)
	#redraw
        self.Mpl.draw()

    def clickradio2(self):
	self.GplineEdit_3.setEnabled(True)
	
    def clickradio1(self):
	self.GplineEdit_3.setEnabled(False)
	
# create the GUI application
app = QtGui.QApplication(sys.argv)
# instantiate the main window
dmw = DesignerMainWindow()
# show it
dmw.show()
# start the Qt main loop execution, exiting from this script
#http://code.google.com/p/subplot/source/browse/branches/mzViewer/PyMZViewer/mpl_custom_widget.py
#http://eli.thegreenplace.net/files/prog_code/qt_mpl_bars.py.txt
#http://lionel.textmalaysia.com/a-simple-tutorial-on-gui-programming-using-qt-designer-with-pyqt4.html
#http://www.mail-archive.com/matplotlib-users@lists.sourceforge.net/msg13241.html
# with the same return code of Qt application
sys.exit(app.exec_())