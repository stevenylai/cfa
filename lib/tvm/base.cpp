/**
   Provides the basic module for TVM related calculation:

   fv = (1 + iy) ^ n * pv
 */
#include <cmath>
#include "tvm/calculator.h"
using namespace cfa::tvm;

Base::Base() : pv(0), fv(0), iy(0), n(0),
               cpt_tbl {
                 {"fv", &Base::cpt_fv},
                 {"pv", &Base::cpt_pv},
                 {"iy", &Base::cpt_iy},
                 {"n", &Base::cpt_n},
                 {"pmt", &Base::cpt_pmt},
               } {
}

Base::~Base() {}

double Base::cpt(std::string const &type) {
  return (this->*cpt_tbl[type])();
}

static double calc_rate(double iy, int n) {
  double result = 1;
  for (int i = 0; i < n; i++) {
    result *= (1 + iy / 100.0);
  }
  return result;
}

double Base::cpt_pv() {
  return this->fv / calc_rate(this->iy, this->n);
}

double Base::cpt_fv() {
  return this->pv * calc_rate(this->iy, this->n);
}

double Base::cpt_iy() {
  double delta = this->fv / this->pv;
  return (std::pow(delta, 1.0 / this->n) - 1) * 100.0;
}

double Base::cpt_n() {
  double delta = this->fv / this->pv;
  return std::log10(delta) / std::log10(1 + this->iy / 100.0);
}

double Base::cpt_pmt() {
  return 0.0; // No payment
}
