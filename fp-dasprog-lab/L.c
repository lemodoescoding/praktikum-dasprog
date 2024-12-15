#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

int main() {
  // t = 2 * r
  // V = PI r r t
  // V = PI r r 2r
  // V = 2 PI r r r
  // r r r =  V / 2 PI
  // r = cbrt(V / 2 PI)
  //
  // L = 2 PI r (r + 2r)
  // L = 2 PI r (3r)
  long double V, r, L;

  scanf("%Lf", &V);

  r = cbrtl(V / (2 * PI));

  L = 6 * PI * r * r;

  printf("Luas permukaan: %.2Lf", L);
}
