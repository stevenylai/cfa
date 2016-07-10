/**
   Header for calculator
 */
#ifndef TVM_CALCULATOR_H
#define TVM_CALCULATOR_H

namespace cfa {
  namespace tvm {

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
      virtual ~Base();
      virtual float cpt(int type);

    private:

      float cpt_pv();
      float cpt_fv();
      float cpt_iy();
      float cpt_n();
      float (Base::*cpt_tbl[_TOTAL])();
    };

    class Payment : Base {
      /**
         TVM calculator with constant payment information
       */

    public:

      bool begin_mode;
      float pmt;

    };


  } // namespace tvm
} // namespace cfa

#endif
