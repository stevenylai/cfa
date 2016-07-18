/**
   Header for calculator
 */
#ifndef TVM_CALCULATOR_H
#define TVM_CALCULATOR_H

#include <map>

namespace cfa {
  namespace tvm {

    class Base {
      /**
         Parameter of a simple calculator:

         * pv: present value
         * fv: future value
         * i/y: interest rate
         * n: componding period

         Method:

         * cpt(type), compute the value of a given type

         */

    public:

      double pv;
      double fv;
      double iy;
      int n;

      Base();
      virtual ~Base();
      virtual double cpt(std::string const &type);

    protected:

      std::map<std::string, double (Base::*)()> cpt_tbl;
      virtual double cpt_pv();
      virtual double cpt_fv();
      virtual double cpt_iy();
      virtual double cpt_n();
      virtual double cpt_pmt();
    };

    class Payment : public Base {
      /**
         TVM calculator with constant payment information
       */

    public:

      bool begin_mode;
      double pmt;

      Payment();
      virtual ~Payment();

    protected:

      virtual double cpt_pmt();
    };


  } // namespace tvm
} // namespace cfa

#endif
