/**
   Test function of tvm calculator
 */
#include <cmath>
#include <cassert>
#include <iostream>
#include "tvm/calculator.h"
using namespace cfa::tvm;

int main() {
  Base calc;
  calc.n = 10, calc.iy = 8, calc.pv = 300;
  double fv = calc.cpt("fv");
  std::cout << fv << std::endl;
  assert(std::abs(fv - 647.68) < 0.01);
  calc.fv = fv;
  assert(std::abs(calc.cpt("iy") - 8) < 0.01);
  return 0;
}
