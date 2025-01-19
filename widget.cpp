#include "widget.h"
#include "./ui_widget.h"
#include <QtDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_guessButton_clicked()
{
    qDebug() << "Guess button click";
}


void Widget::on_startOverButton_clicked()
{
    qDebug() << "Start over Button click"   ;
}

