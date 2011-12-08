#include "ruby.h"

int nnls_(a, mda, m, n, b, x, rnorm, w, zz, index, mode);

VALUE nnls_module = Qnil;

void Init_nnls();

static VALUE nnls_method(VALUE self, VALUE A, VALUE b, VALUE Aw, VALUE Ah);

/* The initialization method for this module */
void Init_nnls() {
  nnls_module = rb_define_module("NNLS");
  rb_define_singleton_method(nnls_module, "_nnls", nnls_method, 4);
}

static VALUE nnls_method(VALUE self, VALUE A, VALUE B, VALUE Aw, VALUE Ah) {
  long A_len = RARRAY_LEN(A);
  long B_len = RARRAY_LEN(B);
  long m = NUM2INT(Aw);
  long n = NUM2INT(Ah);

  double *A_copy = 0;
  double *B_copy = 0;

  double *X = 0;
  double Rnorm = 0;
  double *W = 0;
  double *ZZ = 0;
  int *index = 0;

  int i = 0;
  int mode = 0;
  int mda = 0;

  VALUE ret;
  VALUE ret_x;

  A_copy = malloc(sizeof(double) * m * n);
  B_copy = malloc(sizeof(double) * m);
  X = malloc(sizeof(double) * n);

  W = malloc(sizeof(double) * n);
  ZZ = malloc(sizeof(double) * m);
  index = malloc(sizeof(int) * n);

  mda = m;

  for (i = 0; i < m * n; i++) {
    A_copy[i] = NUM2DBL(rb_ary_entry(A, i));
  }

  for (i = 0; i < m; i++) {
    B_copy[i] = NUM2DBL(rb_ary_entry(B, i));
  }

  nnls_(A_copy, &mda, &m, &n, B_copy, X, &Rnorm, W, ZZ, index, &mode);

  /*
    Now we have solution in array X,
    let's copy it to ruby object
   */
  ret_x = rb_ary_new2(n);
  for (i = 0; i < n; i++) {
    rb_ary_push(ret_x, DBL2NUM(X[i]));
  }

  ret = rb_ary_new2(3);
  rb_ary_push(ret, ret_x);
  rb_ary_push(ret, DBL2NUM(Rnorm));
  rb_ary_push(ret, INT2FIX(mode));

  free(A_copy);
  free(B_copy);
  free(W);
  free(ZZ);
  free(X);

  return ret;
}
