#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    /* Menus*/
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    QMenu *menuEdition = menuBar()->addMenu("&Edition");
    QMenu *menuAffichage = menuBar()->addMenu("&Affichage");


    /*Main Widget*/
    QMdiArea *centralArea = new QMdiArea;

    EnnemyEditor *ennemyEdit = new EnnemyEditor(this);

    QFrame* MainFrame = new QFrame;
    MainFrame->setWindowTitle("Qt SFML");
    //MainFrame->resize(400, 400);
    //MainFrame->show();

    QPathCreator *pathCreator = new QPathCreator(MainFrame,QPoint(20,20),QSize(360,360));

    QMdiSubWindow *subWindowEnnemyEdit = centralArea->addSubWindow(ennemyEdit);
    QMdiSubWindow *subWindowPathCreator = centralArea->addSubWindow(pathCreator);

    setCentralWidget(centralArea);
}

MainWindow::~MainWindow()
{

}
