#include "mainwindow.h"

#include <QDebug>
#include <QLabel>
#include <QMainWindow>

#include "./ui_mainwindow.h"
#include "credit.h"
#include "graph.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pushButton_one, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_two, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_three, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_four, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_five, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_six, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_seven, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_eight, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_nine, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_zero, SIGNAL(clicked()), this, SLOT(digits_numbers()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label = ui->result_show->text() + button->text();

  ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked() {
  QString str = ui->result_show->text();
  QString number;
  int k = 0;
  int len = str.length();
  number.resize(len + 1);

  if (str == "") {
    ui->result_show->setText("");
  } else {
    for (int i = len - 1; i >= 0; i--) {
      number[k++] = str[i];
      if (str[i] == ' ' || str[i] == '(') {
        number[k++] = '\0';
        break;
      }
    }

    if (!(number.contains('.')))
      ui->result_show->setText(ui->result_show->text() + ".");
    number.clear();
  }
}

void MainWindow::on_pushButton_del_all_clicked() {
  ui->result_show->setText("");
}

// Обработка нажатия цифр.
void MainWindow::on_pushButton_zero_clicked() {
  is_zero(ui->result_show->text());
}

void MainWindow::on_pushButton_one_clicked() {
  is_zero(ui->result_show->text());
}

void MainWindow::on_pushButton_two_clicked() {
  is_zero(ui->result_show->text());
}

void MainWindow::on_pushButton_three_clicked() {
  is_zero(ui->result_show->text());
}

void MainWindow::on_pushButton_four_clicked() {
  is_zero(ui->result_show->text());
}

void MainWindow::on_pushButton_five_clicked() {
  is_zero(ui->result_show->text());
}

void MainWindow::on_pushButton_six_clicked() {
  is_zero(ui->result_show->text());
}

void MainWindow::on_pushButton_seven_clicked() {
  is_zero(ui->result_show->text());
}

void MainWindow::on_pushButton_eight_clicked() {
  is_zero(ui->result_show->text());
}

void MainWindow::on_pushButton_nine_clicked() {
  is_zero(ui->result_show->text());
}

// Обработка нажатия цифр законченна.

void MainWindow::on_pushButton_del_clicked() {
  QString str = ui->result_show->text();
  int len = str.length();
  if (len) {
    if ((str[len - 1] == '(' || str[len - 1] == ' ')) {
      if (str[len - 1] == ' ' || str[len - 1] == '(') {
        str.chop(1);
        len = str.length();
      }
      if (len > 0 && str[len - 1] != ' ' && str[len - 1] != '(' &&
          str[len - 1] != '+' && str[len - 1] != '-') {
        str.chop(1);
      }
    } else {
      str.chop(1);
    }
    ui->result_show->setText(str);
    str.clear();
  }
}

void MainWindow::on_pushButton_pluce_clicked() {
  QString str = ui->result_show->text();
  int len = str.length();
  if (len > 0) {
    if (check_operator('+') || check_operator('*'))
      ;
    else {
      if (len == 0 || (len == 1 && str[len - 1] == '-') ||
          str[len - 1] == '(') {
        if (len > 0 && str[len - 1] == '(') {
          ui->result_show->setText(str + "+");
        } else {
          ui->result_show->setText("+");
        }
      } else {
        if (len > 0 && str[len - 1] == '-') {
          str.chop(1);
          ui->result_show->setText(str + "+");
        } else {
          if (len >= 2 && str[len - 2] == '-' && str[len - 1] == ' ') {
            str.chop(3);
          }
          ui->result_show->setText(str + " + ");
        }
      }
    }
  }
  str.clear();
}

void MainWindow::on_pushButton_minus_clicked() {
  QString str = ui->result_show->text();
  int len = str.length();
  if (len == 0) {
    ui->result_show->setText("-");
  }
  if (len > 0) {
    if (check_operator('-'))
      ;
    else {
      if (len == 0 || (len == 1 && str[len - 1] == '+') ||
          str[len - 1] == '(') {
        if (len > 0 && str[len - 1] == '(') {
          ui->result_show->setText(str + "-");
        } else {
          ui->result_show->setText("-");
        }
      } else {
        if (len > 0 && str[len - 1] == '+') {
          str.chop(1);
          ui->result_show->setText(str + "-");
        } else {
          if (len >= 2 && (str[len - 2] == '+' || str[len - 2] == '*' ||
                           str[len - 2] == '/')) {
            str.chop(3);
          }
          ui->result_show->setText(str + " - ");
        }
      }
    }
  }
  str.clear();
}

void MainWindow::on_pushButton_mult_clicked() {
  QString str = ui->result_show->text();
  int len = str.length();
  if (len > 0) {
    if (check_operator('*'))
      ;
    else {
      if (str[len - 1] == ' ' &&
          (str[len - 2] == '/' || str[len - 2] == '+' || str[len - 2] == '-')) {
        str.chop(3);
      }
      ui->result_show->setText(str + " * ");
    }
  }
  str.clear();
}

void MainWindow::on_pushButton_div_clicked() {
  QString str = ui->result_show->text();
  int len = str.length();
  if (len > 0) {
    if (check_operator('/'))
      ;
    else {
      if (str[len - 1] == ' ' &&
          (str[len - 2] == '*' || str[len - 2] == '+' || str[len - 2] == '-')) {
        str.chop(3);
      }
      ui->result_show->setText(str + " / ");
    }
  }
  str.clear();
}

void MainWindow::on_pushButton_x_clicked() {
  QString str = ui->result_show->text();
  int len = str.length();
  if ((len > 0 && str[len - 1] != 'x') || len == 0) {
    ui->result_show->setText(str + "x");
  }
}
// Печать математических операторов.

void MainWindow::on_pushButton_cos_clicked() { print_math_oper("cos("); }

void MainWindow::on_pushButton_sin_clicked() { print_math_oper("sin("); }

void MainWindow::on_pushButton_tan_clicked() { print_math_oper("tan("); }

void MainWindow::on_pushButton_acos_clicked() { print_math_oper("acos("); }

void MainWindow::on_pushButton_asin_clicked() { print_math_oper("asin("); }

void MainWindow::on_pushButton_atan_clicked() { print_math_oper("atan("); }

void MainWindow::on_pushButton_sqrt_clicked() { print_math_oper("sqrt("); }

void MainWindow::on_pushButton_ln_clicked() { print_math_oper("ln("); }

void MainWindow::on_pushButton_log_clicked() { print_math_oper("log("); }

void MainWindow::on_pushButton_mod_clicked() { print_math_oper(" mod "); }

void MainWindow::on_pushButton_pow_clicked() { print_math_oper("^("); }

void MainWindow::on_pushButton_left_bracket_clicked() { print_math_oper("("); }

void MainWindow::on_pushButton_right_bracket_clicked() { print_math_oper(")"); }

// Вспомогательные функции.

// Проверка оператора.
bool MainWindow::check_operator(char sign) {
  QString str = ui->result_show->text();
  int len = str.length();
  return (str[len - 1] == ' ' && str[len - 2] == sign);
}

// Проверка на нажатый ноль.
void MainWindow::is_zero(QString str) {
  if (str == "0") {
    ui->result_show->setText("");
  }
}

void MainWindow::print_math_oper(QString oper) {
  ui->result_show->setText(ui->result_show->text() + oper);
}

void MainWindow::on_pushButton_unar_clicked() {
  QString str = ui->result_show->text();
  int len = str.length();
  if (len > 0) {
    if (str[len - 2] == '-') {
      str.chop(3);
      ui->result_show->setText(str + " + ");
    } else if (str[len - 2] == '+') {
      str.chop(3);
      ui->result_show->setText(str + " - ");
    }
  }
}

void MainWindow::on_pushButton_equal_clicked() {
  int len = ui->result_show->text().length();
  if (len > 0) {
    if (len >= 255) {
      ui->result_show->setText("Expression is too large");
    } else {
      std::string str = ui->result_show->text().toStdString();
      const char *p = str.c_str();
      char result[255];
      if (strchr(p, 'x')) {
        ui->result_show->setText("Incorrect expression");
      } else {
        compute(p, result, 0);
        ui->result_show->setText(result);
      }
    }
  }
}

void MainWindow::on_pushButton_credit_clicked() {
  Credit window;
  window.setModal(true);
  window.setWindowTitle("Credit calculator");
  window.exec();
}

void MainWindow::on_pushButton_graph_clicked() {
  Graph window;
  window.setLabel(ui->result_show->text());
  window.setModal(true);
  window.setWindowTitle("Graph");
  window.exec();
}
