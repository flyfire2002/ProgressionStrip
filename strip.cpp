#include "strip.h"
#include "ui_strip.h"

Strip::Strip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Strip)
{
    ui->setupUi(this);
}

Strip::~Strip()
{
    delete ui;
}
