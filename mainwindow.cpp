#include "mainwindow.h"
#include "strip.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    centralWidget()->setAttribute(Qt::WA_TransparentForMouseEvents);
    setMouseTracking(true);
}

//TODO: fix cllicking on strip.
//TODO: Strip reposition method in Strip
void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    Strip* s = new Strip(ui->centralWidget);
    s->move(ui->stageBarFrame->x()
            + ui->leftBar1->x()
            + ui->leftBar1->width()/2,
            ui->stageBarFrame->y()
            + ui->leftBar1->y()
            + stripVec.size() * (s->height() + 5));
    stripVec.push_back(s);
    s->setHidden(false);
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    //QMainWindow::resizeEvent(event);
    QFrame* stageBarFrame = ui->stageBarFrame;
    qDebug() << stageBarFrame->x() << " " << stageBarFrame->y();
    stageBarFrame->setGeometry(stageBarFrame->x(),
                               stageBarFrame->y(),
                               stageBarFrame->width(),
                               height()- 18);
}

MainWindow::~MainWindow()
{
    while (!stripVec.empty()) {
        delete stripVec[stripVec.size()-1];
        stripVec.pop_back();
    }
    delete ui;
}
