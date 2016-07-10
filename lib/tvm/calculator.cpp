/**
   Provides the basic module for TVM related calculation.
 */
#include "tvm/calculator.h"

Base::Base() : pv(0), fv(0), iy(0), n(0),
               cpt_tbl {&Base::cpt_fv, &Base::cpt_pv,
    &Base::cpt_iy, &Base::cpt_n} {
}

float Base::cpt(int type) {
  if (type >= Base::FV && type <= Base::N) {
    return (this->*cpt_tbl[type])();
  }
  return -1; // TODO: throw exception
}

static float calc_rate(float iy, int n) {
  float result = 1;
  for (int i = 0; i < n; i++) {
    result *= (1 + iy);
  }
  return result;
}

float Base::cpt_pv() {
  return this->fv / calc_rate(this->iy, this->n);
}

float Base::cpt_fv() {
  return this->pv * calc_rate(this->iy, this->n);
}

float Base::cpt_iy() {
  return 0;
}

float Base::cpt_n() {
  return 1;
}
