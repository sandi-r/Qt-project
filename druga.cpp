#include "druga.h"
#include "ui_druga.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <string>
#include "prva.h"

druga::druga(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::druga)
{
    ui->setupUi(this);
}

druga::~druga()
{
    delete ui;

}

