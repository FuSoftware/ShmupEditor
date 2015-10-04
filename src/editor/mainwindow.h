#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QtWidgets>

#include "Widgets/ennemy_editor.h"
#include "Widgets/qpathcreator.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    std::vector<QMdiSubWindow*> window_list;
};

#endif // MAINWINDOW_H
