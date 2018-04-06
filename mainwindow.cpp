#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

double firstNum;
bool UserIsTypingSecondNumber = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_press()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_press()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_press()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_press()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_press()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_press()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_press()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_press()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_press()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_press()));
    connect(ui->pushButton_h,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pushButton_p,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->divide,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->multiply,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->add,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->subtract,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    ui->add->setCheckable(true);
    ui->subtract->setCheckable(true);
    ui->divide->setCheckable(true);
    ui->multiply->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_press()
{
   QPushButton *button=(QPushButton*)sender();

   double labelnumber;
   QString newlabel;

   if((ui->add->isChecked()||ui->subtract->isChecked()||ui->divide->isChecked()||ui->multiply->isChecked()) && (!UserIsTypingSecondNumber))
   {
       labelnumber = button->text().toDouble();
       UserIsTypingSecondNumber=true;
       newlabel=QString::number(labelnumber, 'g', 15);
   }
   else
   {
       labelnumber = (ui->label->text()+button->text()).toDouble();
   }
   newlabel=QString::number(labelnumber, 'g', 15);
   ui->label->setText(newlabel);
}

void MainWindow::on_pushButton_20_released()
{
    ui->label->setText(ui->label->text()+".");
}

void MainWindow::unary_operation_pressed()
{
    double labelnumber;
    QString newlabel;
    QPushButton *button=(QPushButton*) sender();
    if(button->text()=="+/-")
    {
     labelnumber=ui->label->text().toDouble();
     labelnumber=labelnumber *-1;
     newlabel=QString::number(labelnumber, 'g',15);
     ui->label->setText(newlabel);
    }

    if(button->text()=="%")
    {
     labelnumber=ui->label->text().toDouble();
     labelnumber=labelnumber *0.01;
     newlabel=QString::number(labelnumber, 'g',15);
     ui->label->setText(newlabel);
    }
}

void MainWindow::on_pushButton_released()
{
  ui->add->setChecked(false);
  ui->subtract->setChecked(false);
  ui->multiply->setChecked(false);
  ui->divide->setChecked(false);

  UserIsTypingSecondNumber=false;
  ui->label->setText("0");
}

void MainWindow::on_pushButton_r_released()
{
 double labelnumber, secondNum;
 QString newlabel;

 secondNum = ui->label->text().toDouble();
 if(ui->add->isChecked())
 {
     labelnumber= firstNum + secondNum;
     newlabel=QString::number(labelnumber, 'g', 15);
     ui->label->setText(newlabel);
     ui->add->setChecked(false);
 }
 else if(ui->subtract->isChecked())
 {
     labelnumber= firstNum - secondNum;
     newlabel=QString::number(labelnumber, 'g', 15);
     ui->label->setText(newlabel);
     ui->subtract->setChecked(false);
 }
 else if(ui->divide->isChecked())
 {
     labelnumber= firstNum / secondNum;
     newlabel=QString::number(labelnumber, 'g', 15);
     ui->label->setText(newlabel);
     ui->divide->setChecked(false);
 }
 else if(ui->multiply->isChecked())
 {
     labelnumber= firstNum * secondNum;
     newlabel=QString::number(labelnumber, 'g', 15);
     ui->label->setText(newlabel);
     ui->multiply->setChecked(false);
 }
 UserIsTypingSecondNumber=false;
}

void MainWindow::binary_operation_pressed()
{
    QPushButton *button=(QPushButton*)sender();

    firstNum=ui->label->text().toDouble();

    button->setChecked(true);
}

void MainWindow::on_pushButton_10_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, " ", "Do you honestly want to get out?",
                          QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        QApplication::quit();
    }
    else
    {
        QMessageBox::Close;
    }
}
