#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    /* Menus*/
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    QMenu *menuEdition = menuBar()->addMenu("&Edition");
    QMenu *menuAffichage = menuBar()->addMenu("&Affichage");
}

MainWindow::~MainWindow()
{

}

void MainWindow::createDockWindows()
{
    QDockWidget *dock = new QDockWidget(tr("Project Tree"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    QDirModel *modele = new QDirModel();
    QTreeView *vue = new QTreeView;
    vue->setModel(modele);
    vue->setRootIndex(modele->index(this->project->getDir().absolutePath()));
}

void MainWindow::createCentralArea()
{
    /*Main Widget*/
    QMdiArea *centralArea = new QMdiArea;

    EnnemyEditor *ennemyEdit = new EnnemyEditor(this);

    //QFrame* MainFrame = new QFrame;
    //MainFrame->setWindowTitle("Qt SFML");
    //MainFrame->resize(400, 400);
    //MainFrame->show();

    QPathCanvas *pathCreator = new QPathCanvas(this,QPoint(20,20),QSize(480,640));

    QMdiSubWindow *subWindowEnnemyEdit = centralArea->addSubWindow(ennemyEdit);
    QMdiSubWindow *subWindowPathCreator = centralArea->addSubWindow(pathCreator);

    setCentralWidget(centralArea);
}

void MainWindow::loadProject()
{

}
