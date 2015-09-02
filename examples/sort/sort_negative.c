#include "../smack.h"

void sort2(int *out2, int *in2) {
  int a, b;
  a = in2[0];
  b = in2[1];
  if (a < b) {
    out2[0] = in2[0];
    out2[1] = in2[1];
  } else {
    out2[0] = in2[1];
    out2[1] = in2[0];
  }
  return;
}

void sort3(int *out3, int *in3) {
  sort2(out3,in3);
  in3[1] = out3[1];
  sort2(out3+1,in3+1);
  in3[0] = out3[0];
  in3[1] = out3[1];
  sort2(out3,in3);
}

int sort3_wrapper(int *out, int *in) {
  /* Boilerplate */
  public_in(region_of_var(out));
  public_in(region_of_var(in));

  /* Useful for testing out more of the assertion generation */
  public_out(region_of_ret());

  sort3(out,in);
  return 3;
}
