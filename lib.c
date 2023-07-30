#define STRICT_R_HEADERS
#define R_NO_REMAP
#define R_NO_REMAP_RMATH

#include <R.h>
#include <Rinternals.h>

SEXP silly()
{
  return Rf_ScalarInteger(42);
}

SEXP create_s4_object()
{
  SEXP s4_obj;
  PROTECT(s4_obj = R_do_new_object(R_do_MAKE_CLASS("Person")));

  SEXP name, age;
  PROTECT(name = Rf_allocVector(STRSXP, 1));
  PROTECT(age = Rf_allocVector(REALSXP, 1));

  SET_STRING_ELT(name, 0, Rf_mkChar("John Doe"));
  REAL(age)
  [0] = 30.0;

  R_do_slot_assign(s4_obj, Rf_mkString("name"), name);
  R_do_slot_assign(s4_obj, Rf_mkString("age"), age);

  UNPROTECT(3);
  return s4_obj;
}
