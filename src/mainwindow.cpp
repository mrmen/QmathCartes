#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QStringListModel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    carteNames << "Fonctions généralités" << "Nombres relatifs" << "Résolution d'équations" << "Théorème de Pythagore" << "Théorème de Thalès" << "Trigonométrie";
    carteFiles << "fonctions.png" << "relatifs.png" << "equations.png" << "pythagore.png" << "thales.png"<< "trigonometrie.png";
    prefix = ":/images/";
    carteModel = new QStringListModel(this);
    populateTable();
    connect(ui->listView, SIGNAL(clicked(QModelIndex)), SLOT(openCarte(QModelIndex)));
    connect(ui->zoomM,SIGNAL(clicked(bool)), SLOT(zoomArr()));
    connect(ui->zoomP,SIGNAL(clicked(bool)), SLOT(zoomAv()));
}

void MainWindow::populateTable()
{
    carteModel->setStringList(carteNames);
    ui->listView->setModel(carteModel);
}


void MainWindow::zoomArr(){
    ui->graphicsView->scale(0.95,0.95);
}

void MainWindow::zoomAv(){
    ui->graphicsView->scale(1.05,1.05);
}

void MainWindow::openCarte(const QModelIndex & currentIndex){

    imageObject = new QImage(prefix + carteFiles[currentIndex.row()]);

    image = QPixmap::fromImage(*imageObject);

    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(ui->graphicsView->sceneRect(), Qt::KeepAspectRatio);
}

MainWindow::~MainWindow()
{
 delete ui;
}
