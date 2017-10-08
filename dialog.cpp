#include "dialog.h"
#include "ui_dialog.h"
#include <QTimer>

Dialog::Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog)
{
  ui->setupUi(this);
  {
    QTimer * const timer{new QTimer(this)};
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(OnTimer()));
    timer->setInterval(1000 / 60);
    timer->start();
  }
}

Dialog::~Dialog()
{
  delete ui;
}

void Dialog::OnTimer()
{
 // Move in x direction
  ui->label->setGeometry(
    ui->label->geometry().x() + ui->box_dx->value(),
    ui->label->geometry().y(),
    ui->label->geometry().width(),
    ui->label->geometry().height()
  );

  // If at far right, move left
  if (ui->label->geometry().x()+ui->label->geometry().width()> this->geometry().width()){
  if(ui->verticalScrollBar->sliderPosition()==ui->label->geometry().y())
    ui->box_dx->setValue(-1);
    else
    ui->box_dx->setValue(1);
  };
    if (ui->label->geometry().x() <0)
  {
    ui->box_dx->setValue(1);
  }
// Move in y direction
  ui->label->setGeometry(
    ui->label->geometry().x() ,
    ui->label->geometry().y()+ ui->box_dy->value(),
    ui->label->geometry().width(),
    ui->label->geometry().height()
  );

  // If at far right, move lefti
  if (ui->label->geometry().y()+ui->label->geometry().height() > this->geometry().height())
  {
    ui->box_dy->setValue(-1);
  };
    if (ui->label->geometry().y() <0)
  {
    ui->box_dy->setValue(1);
  };
}

/*
void Dialog::on_Left_clicked()
{
     // Move left
  ui->label->setGeometry(
    ui->label->geometry().x() - 10,
    ui->label->geometry().y(),
    ui->label->geometry().width(),
    ui->label->geometry().height()
  );

  // If at far right, move left
  if (ui->label->geometry().x()+ui->label->geometry().width() < 0)
  {
    ui->label->setGeometry(
      ui->label->geometry().x() + this->geometry().width(),
      ui->label->geometry().y(),
      ui->label->geometry().width(),
      ui->label->geometry().height()
    );

  }
}
*/



