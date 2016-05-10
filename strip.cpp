#include "strip.h"
#include "ui_strip.h"

Strip::Strip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Strip)
{
    ui->setupUi(this);
}

Strip::~Strip()
{
    delete ui;
}
