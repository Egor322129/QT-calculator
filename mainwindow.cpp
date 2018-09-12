#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

double num_first;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_plus_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_percentage, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    QString new_result;
    double all_numbers;
    if (button->text() != "0")
    {
        all_numbers = (ui->result->text() + button->text()).toDouble();
        new_result = QString::number(all_numbers, 'g', 15);
    } else
    {
        new_result = ui->result->text() + button->text();
    }

    ui->result->setText(new_result);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result->text().contains('.')))
        ui->result->setText(ui->result->text() +'.');

}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();

    QString new_result;
    double all_numbers;
    if (button->text() == "+/-"){
        all_numbers = ui->result->text().toDouble();
        all_numbers =  all_numbers * -1;
        new_result = QString::number(all_numbers, 'g', 15);
        ui->result->setText(new_result);
    }

    if (button->text() == "%"){
        all_numbers = ui->result->text().toDouble();
        all_numbers =  all_numbers * 0.01;
        new_result = QString::number(all_numbers, 'g', 15);
        ui->result->setText(new_result);
    }
}

void MainWindow::math_operations()
{
     QPushButton *button = (QPushButton *)sender();
     num_first = ui->result->text().toDouble();
     ui->result->setText("");
     button->setChecked(true);

}

void MainWindow::on_pushButton_ac_clicked()
{
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_plus->setChecked(false);

    ui->result->setText("0");
}

void MainWindow::on_pushButton_equals_clicked()
{
    double num_second, label_number;
    QString new_label;

    num_second = ui->result->text().toDouble();

    if (ui->pushButton_divide->isChecked())
    {
        if (num_second == 0)
        {
            ui->result->setText("0");
            ui->pushButton_divide->setChecked(false);
        } else
        {
            label_number = num_first / num_second;
            new_label = QString::number(label_number, 'g', 15);
            ui->result->setText(new_label);
            ui->pushButton_divide->setChecked(false);
        }
    }
    if (ui->pushButton_multiply->isChecked())
    {
        label_number = num_first * num_second;
        new_label = QString::number(label_number, 'g', 15);
        ui->result->setText(new_label);
        ui->pushButton_multiply->setChecked(false);
    }
    if (ui->pushButton_minus->isChecked())
    {
        label_number = num_first - num_second;
        new_label = QString::number(label_number, 'g', 15);
        ui->result->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    }
    if (ui->pushButton_plus->isChecked())
    {
        label_number = num_first + num_second;
        new_label = QString::number(label_number, 'g', 15);
        ui->result->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    }
}
