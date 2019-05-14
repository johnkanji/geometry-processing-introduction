#include "edges.h"
#include <set>
#include <utility>
#include <algorithm>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  std::set<std::pair<double,double>> es;
  for (int i = 0; i < F.rows(); i++) {
    std::pair<double,double> e1;
    e1.first = std::min(F.row(i)(0), F.row(i)(1));
    e1.second = std::max(F.row(i)(0), F.row(i)(1));
    es.insert(e1);

    std::pair<double,double> e2;
    e2.first = std::min(F.row(i)(1), F.row(i)(2));
    e2.second = std::max(F.row(i)(1), F.row(i)(2));
    es.insert(e2);

    std::pair<double,double> e3;
    e3.first = std::min(F.row(i)(2), F.row(i)(0));
    e3.second = std::max(F.row(i)(2), F.row(i)(0));
    es.insert(e3);
  }
  E.resize(es.size(), 2);
  int i = 0;
  for (auto e : es) {
    E.row(i++) << e.first, e.second;
  }
  return E;
}
