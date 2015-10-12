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

    QMenu *menuLoadFile = menuFichier->addMenu("Add File");
    std::vector<QAction*> actions;
    for(int i=0;i<F_LIST_END;i++)
    {
        actions.push_back(new QAction(FileTypeString[i].c_str(),this));
        menuLoadFile->addAction(actions.at(i));
        loadFileMapper->setMapping(actions.at(i),i);
        connect( actions.at(i), SIGNAL(triggered()), loadFileMapper, SLOT(map()) );
    }
    menuLoadFile->setEnabled(false);
void MainWindow::loadProject()
{

void MainWindow::addFile(int sender)
{
    QString path = QFileDialog::getOpenFileName(this,"Open " + QString(FileTypeString[sender].c_str()) + " File",QString(),"JSON File (*.json)");
    project->addFile(path.toStdString(),sender);
    refreshProjectTree();
}
