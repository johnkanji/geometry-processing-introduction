#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E = edges(F);
  int Chi = F.maxCoeff() - E.rows() + F.rows();
  return Chi;
}
