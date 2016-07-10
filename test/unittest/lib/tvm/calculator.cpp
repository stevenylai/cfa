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
  calc.n = 10, calc.iy = 8, calc.pv = -300;
  float fv = calc.cpt(Base::FV);
  std::cout << fv << std::endl;
  assert(std::abs(fv - 647.68) < 0.01);
  return 0;
}
