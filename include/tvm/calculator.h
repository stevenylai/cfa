/**
   Header for calculator
 */


class Base {
  /**
     Parameter of a calculator:

     * pv: present value
     * fv: future value
     * i/y: interest rate
     * n: componding period

     Method:

     * cpt(type), compute the value of a given type

   */

 public:

  enum {
    FV,
    PV,
    IY,
    N,
    _TOTAL,
  };

  float pv;
  float fv;
  float iy;
  int n;

  Base();
  float cpt(int type);

 private:

  float cpt_pv();
  float cpt_fv();
  float cpt_iy();
  float cpt_n();
  float (Base::*cpt_tbl[_TOTAL])();
};
