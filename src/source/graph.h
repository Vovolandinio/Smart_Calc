#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>

namespace Ui {
class Graph;
}

class Graph : public QDialog {
  Q_OBJECT

 public:
  explicit Graph(QWidget *parent = nullptr);
  ~Graph();
  void setLabel(const QString &x);

 private slots:
  void on_pushButton_build_graph_clicked();

 private:
  Ui::Graph *ui;
};

#endif  // GRAPH_H
