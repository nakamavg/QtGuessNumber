#include "widget.h"
#include "./ui_widget.h"
#include <cstdlib>
#include <ctime>

#include <QtDebug>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    attempts = 0;
    std::srand(std::time(nullptr));
    secret_number= rand() % 10 + 1;
    qDebug() <<&"secret number generater is " << QString::number(secret_number);
    ui->startOverButton->setDisabled(true);
    ui->messageLabel->setText(" ");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_guessButton_clicked()
{
    // Restaurar el estilo original en cada intento antes de verificar
    ui->messageLabel->setStyleSheet("");

    guess_number = ui->numberSpinBox->value();
    attempts++; // Incrementar el contador de intentos

    if (guess_number == secret_number)
    {
        ui->messageLabel->setStyleSheet("QLabel { background-color : green; color : white; }");
        ui->messageLabel->setText(
            "🎉 Congratulations! The number is: " + QString::number(guess_number) +
            ". You guessed it in " + QString::number(attempts) + " attempts!");
        ui->guessButton->setDisabled(true);
        ui->startOverButton->setDisabled(false);
    }
    else
    {
        if (guess_number > secret_number)
            ui->messageLabel->setText("Number is lower than that");
        else
            ui->messageLabel->setText("Number is higher than that");

        // Cambiar a rojo solo si es un intento fallido
        ui->messageLabel->setStyleSheet("QLabel { background-color : red; color : white; }");
    }
}

void Widget::on_startOverButton_clicked()
{
    qDebug() << "Start over Button clicked";
    ui->guessButton->setDisabled(false);
    ui->startOverButton->setDisabled(true);
    ui->numberSpinBox->setValue(1);

    // Generar un nuevo número secreto y resetear intentos
    secret_number = rand() % 10 + 1;
    attempts = 0;

    // Limpiar el mensaje y restaurar el estilo original
    ui->messageLabel->setText(" ");
    ui->messageLabel->setStyleSheet(""); // Restaurar el estilo original
}
