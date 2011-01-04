import sys
from PyQt4 import QtCore, QtGui
from simpleadderpy import Ui_MainWindow

class StartQT4(QtGui.QMainWindow):
    def __init__(self, parent=None):
        QtGui.QWidget.__init__(self, parent)
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
	QtCore.QObject.connect(self.ui.pushButton, QtCore.SIGNAL("clicked()"), self.but_clked )
	
    def but_clked(self):
	self.ui.lineEdit_3.setText(str(int(self.ui.lineEdit.text())+int(self.ui.lineEdit_2.text())))

if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    myapp = StartQT4()
    myapp.show()
    sys.exit(app.exec_())

