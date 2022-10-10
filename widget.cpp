#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <string>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff) {
    money += diff;
    ui->lcdNumber->display(money);
}

void Widget::checkMoney() {
    if (money >= 100) {
        ui->pbCoffee->setEnabled(true);
    }
    else {
        ui->pbCoffee->setEnabled(false);
    }
    if (money >= 150) {
        ui->pbTea->setEnabled(true);
    }
    else {
        ui->pbTea->setEnabled(false);
    }
    if (money >= 200) {
        ui->pbMilk->setEnabled(true);
    }
    else {
        ui->pbMilk->setEnabled(false);
    }
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
    checkMoney();
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
    checkMoney();
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
    checkMoney();
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
    checkMoney();
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
    checkMoney();
}


void Widget::on_pbReset_clicked()
{
    QMessageBox msg;
    int cur_money = money;
    int cnt_500, cnt_100, cnt_50;
    cnt_500 = cur_money / 500;
    cur_money %= 500;
    cnt_100 = cur_money / 100;
    cur_money %= 100;
    cnt_50 = cur_money / 50;

    std::string message = "500=" + std::to_string(cnt_500) + " 100=" + std::to_string(cnt_100) + " 50=" + std::to_string(cnt_50);
    msg.information(this, "Reset", QString::fromStdString(message));
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
    checkMoney();
}

