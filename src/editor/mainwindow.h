#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QtWidgets>

#include "Widgets/ennemy_editor.h"
#include "Widgets/qpathcanvas.h"

#include"project.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createDockWindows();
    void createCentralArea();
    void createActions();
    void refreshProjectTree();


public slots:
    void loadProject();
    void addFile(int sender);

signals:
    void projectLoaded(bool);

private:
    std::vector<QMdiSubWindow*> window_list;

    QDir *projectRoot;

    QFileSystemModel *projectModel;
    QTreeView *projectView;

    Project *project;

};

#endif // MAINWINDOW_H
