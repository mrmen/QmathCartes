#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStringList carteNames;
    QStringList carteFiles;
    QString prefix;
    QStringListModel *carteModel;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;



private slots:
    void populateTable();
    void openCarte(const QModelIndex & currentIndex);
    void zoomArr();
    void zoomAv();

};

#endif // MAINWINDOW_H
