/**
   Provides the basic module for TVM related calculation.
 */
#include "tvm/calculator.h"
using namespace cfa::tvm;

Base::Base() : pv(0), fv(0), iy(0), n(0),
               cpt_tbl {&Base::cpt_fv, &Base::cpt_pv,
    &Base::cpt_iy, &Base::cpt_n} {
}

Base::~Base() {}

float Base::cpt(int type) {
  if (type >= Base::FV && type <= Base::N) {
    return (this->*cpt_tbl[type])();
  }
  return -1; // TODO: throw exception
}

static float calc_rate(float iy, int n) {
  float result = 1;
  for (int i = 0; i < n; i++) {
    result *= (1 + iy / 100.0);
  }
  return result;
}

float Base::cpt_pv() {
  return this->fv / calc_rate(this->iy, this->n) * -1;
}

float Base::cpt_fv() {
  return this->pv * calc_rate(this->iy, this->n) * -1;
}

float Base::cpt_iy() {
  return 0;
}

float Base::cpt_n() {
  return 1;
}
