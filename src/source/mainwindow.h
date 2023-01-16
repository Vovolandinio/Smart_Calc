#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

#include "qcustomplot.h"
extern "C" {
#include "calculator.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;

 private slots:
  void digits_numbers();
  void on_pushButton_dot_clicked();
  void on_pushButton_del_all_clicked();
  void on_pushButton_zero_clicked();
  void on_pushButton_one_clicked();
  void on_pushButton_two_clicked();
  void on_pushButton_three_clicked();
  void on_pushButton_four_clicked();
  void on_pushButton_five_clicked();
  void on_pushButton_six_clicked();
  void on_pushButton_seven_clicked();
  void on_pushButton_eight_clicked();
  void on_pushButton_nine_clicked();
  void on_pushButton_del_clicked();
  void on_pushButton_pluce_clicked();
  void on_pushButton_minus_clicked();
  void on_pushButton_mult_clicked();
  void on_pushButton_div_clicked();
  void on_pushButton_cos_clicked();
  bool check_operator(char sign);
  void is_zero(QString str);
  void print_math_oper(QString str);
  void on_pushButton_sin_clicked();
  void on_pushButton_tan_clicked();
  void on_pushButton_acos_clicked();
  void on_pushButton_asin_clicked();
  void on_pushButton_atan_clicked();
  void on_pushButton_sqrt_clicked();
  void on_pushButton_ln_clicked();
  void on_pushButton_log_clicked();
  void on_pushButton_mod_clicked();
  void on_pushButton_pow_clicked();
  void on_pushButton_left_bracket_clicked();
  void on_pushButton_right_bracket_clicked();
  void on_pushButton_equal_clicked();
  void on_pushButton_credit_clicked();
  void on_pushButton_graph_clicked();
  void on_pushButton_x_clicked();
  void on_pushButton_unar_clicked();
};
#endif  // MAINWINDOW_H
