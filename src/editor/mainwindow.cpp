#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createActions();
    createDockWindows();
    createCentralArea();
}

MainWindow::~MainWindow()
{

}

void MainWindow::createDockWindows()
{
    QDockWidget *dock = new QDockWidget(tr("Project Tree"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    projectModel = new QFileSystemModel ;
    projectModel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot | QDir::Files);

    projectView = new QTreeView;
    projectView->setModel(projectModel);

    dock->setWidget(projectView);

    addDockWidget(Qt::LeftDockWidgetArea, dock);
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

void MainWindow::createActions()
{
    QSignalMapper *loadFileMapper = new QSignalMapper( this );

    /*File*/
    QMenu *menuFichier = menuBar()->addMenu("&File");

    QAction *actionLoadProject = new QAction("&Open Project", this);
    menuFichier->addAction(actionLoadProject);

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

    QAction *actionQuit = new QAction("&Quit", this);
    menuFichier->addAction(actionQuit);

    QMenu *menuEdition = menuBar()->addMenu("&Edit");

    QMenu *menuAffichage = menuBar()->addMenu("&View");

    /*Connects*/
    connect(actionQuit,SIGNAL(triggered(bool)),qApp,SLOT(quit()));
    connect(actionLoadProject,SIGNAL(triggered(bool)),this,SLOT(loadProject()));
    connect(loadFileMapper,SIGNAL(mapped(int)),this,SLOT(addFile(int)));
    connect(this,SIGNAL(projectLoaded(bool)),menuLoadFile,SLOT(setEnabled(bool)));
}

void MainWindow::refreshProjectTree()
{
    projectModel->setRootPath(project->getDir().absolutePath());
    projectView->setRootIndex(projectModel->index(project->getDir().absolutePath()));
}

void MainWindow::loadProject()
{
    QString path = QFileDialog::getOpenFileName(this,"Open Project File",QString(),"ShmuProject File (*.shp)");
    project = new Project(path.toStdString(),this);
    refreshProjectTree();
    emit projectLoaded(true);
}

void MainWindow::addFile(int sender)
{
    QString path = QFileDialog::getOpenFileName(this,"Open " + QString(FileTypeString[sender].c_str()) + " File",QString(),"JSON File (*.json)");
    project->addFile(path.toStdString(),sender);
    refreshProjectTree();
}
