#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    config_file = new ConfigFile(FILE_CONFIG);

    createActions();
    createDockWindows();
    createCentralArea();
}

MainWindow::~MainWindow()
{
    config_file->save();

    int ans = QMessageBox::question(this, "Save Project", "Do you want to save your project before exiting ?", QMessageBox::Yes | QMessageBox::No);

    if (ans == QMessageBox::Yes)
    {
        project->save();
    }
}

void MainWindow::createDockWindows()
{
    QDockWidget *dock = new QDockWidget(tr("Project Tree"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    projectModel = new QFileSystemModel ;
    projectModel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot | QDir::Files);

    projectView = new QTreeView;
    projectView->setModel(projectModel);

    connect(projectView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(loadTreeFile(QModelIndex)));

    dock->setWidget(projectView);

    addDockWidget(Qt::LeftDockWidgetArea, dock);
}

void MainWindow::createCentralArea()
{
    /*Main Widget*/
    centralArea = new QMdiArea;

    //EnnemyEditor *ennemyEdit = new EnnemyEditor(QString(FILE_ENNEMY_TEST),this);
    //QMdiSubWindow *subWindowEnnemyEdit = centralArea->addSubWindow(ennemyEdit);

    //QPathCanvas *pathCreator = new QPathCanvas(this,QPoint(20,20),QSize(480,640));
    //QMdiSubWindow *subWindowPathCreator = centralArea->addSubWindow(pathCreator);

    setCentralWidget(centralArea);
}

void MainWindow::createActions()
{
    QSignalMapper *loadFileMapper = new QSignalMapper( this );
    QSignalMapper *loadProjectMapper = new QSignalMapper( this );

    /*File*/
    QMenu *menuFichier = menuBar()->addMenu("&File");

    QAction *actionLoadProject = new QAction("&Open Project", this);
    menuFichier->addAction(actionLoadProject);

    QMenu *menuLoadProject = menuFichier->addMenu("Recent Projects");
    std::vector<QAction*> actionProject;
    for(int i=0;i<config_file->getProjectCount();i++)
    {
        actionProject.push_back(new QAction(config_file->getProjectName(i).c_str(),this));
        menuLoadProject->addAction(actionProject.at(i));
        loadProjectMapper->setMapping(actionProject.at(i),i);
        connect( actionProject.at(i), SIGNAL(triggered()), loadProjectMapper, SLOT(map()) );
    }

    QAction *actionSaveProject = new QAction("&Save Project", this);
    menuFichier->addAction(actionSaveProject);

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
    connect(loadProjectMapper,SIGNAL(mapped(int)),this,SLOT(loadProject(int)));
    connect(this,SIGNAL(projectLoaded(bool)),menuLoadFile,SLOT(setEnabled(bool)));
    connect(actionSaveProject,SIGNAL(triggered(bool)),this,SLOT(saveProject()));
}

void MainWindow::refreshProjectTree()
{
    projectModel->setRootPath(project->getDir().absolutePath());
    projectView->setRootIndex(projectModel->index(project->getDir().absolutePath()));
}

void MainWindow::loadProject()
{
    QString path = QFileDialog::getOpenFileName(this,"Open Project File",QString(),"ShmuProject File (*.shp)");
    loadProject(path.toStdString());
}

void MainWindow::loadProject(std::string path, bool addToRecent)
{
    QFileInfo fileInfo(QFile(path.c_str()));
    if(addToRecent){config_file->addProject(fileInfo.fileName().toStdString(),path);}

    project = new Project(path,this);
    refreshProjectTree();
    emit projectLoaded(true);
}

void MainWindow::saveProject()
{
    project->save();
}

void MainWindow::addFile(int sender)
{
    QString path;

    switch(sender)
    {
    case F_SPRITE:
        path = QFileDialog::getOpenFileName(this,"Open " + QString(FileTypeString[sender].c_str()) + " File",QString(),"Pictures (*.png *.jpg *.jpeg)");
        break;
    case F_MUSIC:
        path = QFileDialog::getOpenFileName(this,"Open " + QString(FileTypeString[sender].c_str()) + " File",QString(),"Music (*.mp3 *.ogg)");
        break;
    default:
        path = QFileDialog::getOpenFileName(this,"Open " + QString(FileTypeString[sender].c_str()) + " File",QString(),"JSON File (*.json)");
        break;
    }
    project->addFile(path.toStdString(),sender);
    refreshProjectTree();
}

void MainWindow::loadProject(int sender)
{
    loadProject(config_file->getProjectPath(sender),false);
}

void MainWindow::loadTreeFile(QModelIndex index)
{
    QString file = this->projectModel->filePath(index);
    qDebug() << "Tree Index Loading " << file;
    loadTreeFile(file);

}

void MainWindow::loadTreeFile(QString file)
{
    /*
    #define EX_PROJECT "shp"
    #define EX_ENNEMY "ennemy"
    #define EX_BULLET "bullet"
    #define EX_PATH "path"
    #define EX_PATTERN "pattern"
    #define EX_LEVEL "level"
    #define EX_JSON "json"
    */

    QFileInfo fileInfo(file);

    if(fileInfo.completeSuffix().compare(QString(EX_ENNEMY)) == 0)
    {
        /*Ennemy*/
        qDebug() << "Loading new ennemy" << fileInfo.absoluteFilePath() ;
        EnnemyEditor *ennemyEdit = new EnnemyEditor(fileInfo.absoluteFilePath(),this);
        QMdiSubWindow *subWindowEnnemyEdit = centralArea->addSubWindow(ennemyEdit);
        subWindowEnnemyEdit->show();
    }
    else if(fileInfo.completeSuffix().compare(EX_BULLET))
    {
        /*Path*/
    }
    else if(fileInfo.completeSuffix().compare(EX_PATH))
    {
        /*Bullet*/
    }
    else if(fileInfo.completeSuffix().compare(EX_PATTERN))
    {
        /*Pattern*/
    }
    else if(fileInfo.completeSuffix().compare(EX_LEVEL))
    {
        /*Level*/
    }
    else if(fileInfo.completeSuffix().compare(EX_JSON))
    {
        /*JSON*/

    }


}
