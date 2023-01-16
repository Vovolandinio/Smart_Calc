#include "graph.h"

#include "mainwindow.h"
#include "ui_graph.h"

Graph::Graph(QWidget* parent) : QDialog(parent), ui(new Ui::Graph) {
  ui->setupUi(this);
}

Graph::~Graph() { delete ui; }

void Graph::setLabel(const QString& x) { ui->expression->setText(x); }

void Graph::on_pushButton_build_graph_clicked() {
  ui->widget->clearGraphs();

  if (ui->expression->text().length() > 0) {
    double a = -10;
    if (ui->x_min->text().length() != 0) a = ui->x_min->text().toDouble();
    double b = 10;
    if (ui->x_max->text().length() != 0) b = ui->x_max->text().toDouble();
    double h = 1;
    if (ui->step->text().length() != 0) h = ui->step->text().toDouble();

    if (a > b || h <= 0) {
      a = 0;
      b = 0;
      h = 1;
    }

    if (a < -100000) {
      a = -100000;
    }
    if (b > 100000) {
      b = 100000;
    }

    int N = (b - a) / h + 2;

    if (N > 1000000) {
      N = 1000000;
      h = (b - a) / (N - 2);
    }

    QVector<double> x(N), y(N);

    int i = 0;
    for (double X = a; X <= b; X += h) {
      std::string str = ui->expression->text().toStdString();
      const char* p = str.c_str();
      char result[225];
      if (compute(p, result, X)) continue;
      y[i] = atof(result);
      x[i] = X;
      i++;
    }
    ui->widget->clearGraphs();
    ui->widget->addGraph();

    ui->widget->graph(0)->setData(x, y);
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsStepLeft);

    ui->widget->graph(0)->setScatterStyle(
        QCPScatterStyle(QCPScatterStyle::ssDot, Qt::blue, Qt::white));

    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");

    ui->widget->xAxis->setRange(a, b);

    double minY = y[0], maxY = y[0];
    for (int i = 1; i < N; i++) {
      if (y[i] <= minY) minY = y[i] - 1;
      if (y[i] >= maxY) maxY = y[i] + 1;
    }
    ui->widget->yAxis->setRange(minY, maxY);

    ui->widget->replot();
  }
}
