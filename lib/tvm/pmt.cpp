/*
  TVM calculator with payment
 */
#include "tvm/calculator.h"
using namespace cfa::tvm;

Payment::Payment() : begin_mode(false), pmt(0.0), Base() {
}

Payment::~Payment() {}

double Payment::cpt_pmt() {
  return 0.0;
}
