#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
  class Dialog;
}

class Dialog : public QDialog
{
  Q_OBJECT

public:
  explicit Dialog(QWidget *parent = 0);
  ~Dialog();

private slots:

  /// Called by the timer 60 times per second
  void OnTimer();



private:
  Ui::Dialog *ui;
};

#endif // DIALOG_H
