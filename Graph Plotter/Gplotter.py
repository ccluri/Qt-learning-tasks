# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Gplotter.ui'
#
# Created: Sun Dec 26 04:15:06 2010
#      by: PyQt4 UI code generator 4.7.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

class Ui_GpMainWindow(object):
    def setupUi(self, GpMainWindow):
        GpMainWindow.setObjectName("GpMainWindow")
        GpMainWindow.resize(567, 497)
        self.Gpcentralwidget = QtGui.QWidget(GpMainWindow)
        self.Gpcentralwidget.setObjectName("Gpcentralwidget")
        self.verticalLayout = QtGui.QVBoxLayout(self.Gpcentralwidget)
        self.verticalLayout.setObjectName("verticalLayout")
        self.GpgridLayout = QtGui.QGridLayout()
        self.GpgridLayout.setObjectName("GpgridLayout")
        self.GppushButton = QtGui.QPushButton(self.Gpcentralwidget)
        self.GppushButton.setObjectName("GppushButton")
        self.GpgridLayout.addWidget(self.GppushButton, 1, 2, 1, 1)
        self.GpradioButton2 = QtGui.QRadioButton(self.Gpcentralwidget)
        self.GpradioButton2.setEnabled(False)
        self.GpradioButton2.setObjectName("GpradioButton2")
        self.GpgridLayout.addWidget(self.GpradioButton2, 1, 1, 1, 1)
        self.GpradioButton = QtGui.QRadioButton(self.Gpcentralwidget)
        self.GpradioButton.setChecked(True)
        self.GpradioButton.setObjectName("GpradioButton")
        self.GpgridLayout.addWidget(self.GpradioButton, 1, 0, 1, 1)
        self.GplineEdit = QtGui.QLineEdit(self.Gpcentralwidget)
        self.GplineEdit.setObjectName("GplineEdit")
        self.GpgridLayout.addWidget(self.GplineEdit, 0, 0, 1, 1)
        self.GplineEdit_2 = QtGui.QLineEdit(self.Gpcentralwidget)
        self.GplineEdit_2.setObjectName("GplineEdit_2")
        self.GpgridLayout.addWidget(self.GplineEdit_2, 0, 1, 1, 1)
        self.GplineEdit_3 = QtGui.QLineEdit(self.Gpcentralwidget)
        self.GplineEdit_3.setEnabled(False)
        self.GplineEdit_3.setObjectName("GplineEdit_3")
        self.GpgridLayout.addWidget(self.GplineEdit_3, 0, 2, 1, 1)
        self.verticalLayout.addLayout(self.GpgridLayout)
        self.Mpl = MplWidget(self.Gpcentralwidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.Mpl.sizePolicy().hasHeightForWidth())
        self.Mpl.setSizePolicy(sizePolicy)
        self.Mpl.setObjectName("Mpl")
        self.verticalLayout.addWidget(self.Mpl)
        GpMainWindow.setCentralWidget(self.Gpcentralwidget)

        self.retranslateUi(GpMainWindow)
        QtCore.QMetaObject.connectSlotsByName(GpMainWindow)

    def retranslateUi(self, GpMainWindow):
        GpMainWindow.setWindowTitle(QtGui.QApplication.translate("GpMainWindow", "Graph Plotter", None, QtGui.QApplication.UnicodeUTF8))
        self.GppushButton.setText(QtGui.QApplication.translate("GpMainWindow", "Draw", None, QtGui.QApplication.UnicodeUTF8))
        self.GpradioButton2.setText(QtGui.QApplication.translate("GpMainWindow", "Plot 3D", None, QtGui.QApplication.UnicodeUTF8))
        self.GpradioButton.setText(QtGui.QApplication.translate("GpMainWindow", "Plot 2D", None, QtGui.QApplication.UnicodeUTF8))

from mplwidget import MplWidget
