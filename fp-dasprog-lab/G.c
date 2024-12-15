#include <math.h>
#include <stdio.h>

#define ll long long

ll modulo = 1000000007;

ll f(ll a, ll b, ll n) {
  if (n == 0) {
    return 1;
  }

  if (n == 1) {
    return 2;
  }
  if (n == 2) {
    return (a + b);
  }

  if (n == 3) {
    return 5;
  }

  ll f_current;
  ll f_minus_4 = 1, f_minus_3 = 2, f_minus_2 = a + b, f_minus_1 = 5;

  for (int i = 4; i < n + 1; i++) {
    if (i % 2 == 0) {
      f_current = (a * f_minus_2 + b) % modulo;
    } else {
      f_current =
          (4 * f_minus_2 - 4 * f_minus_4 + ((ll)pow(i - 1, 2) / 4)) % modulo;
    }

    f_minus_4 = f_minus_3;
    f_minus_3 = f_minus_2;
    f_minus_2 = f_minus_1;
    f_minus_1 = f_current;
  }

  return f_current;
}

int main() {
  int c;
  scanf("%d", &c);

  ll fnargs[c][3];
  for (int i = 0; i < c; i++) {
    scanf("%lld %lld %lld", &fnargs[i][0], &fnargs[i][1], &fnargs[i][2]);
  }

  for (int i = 0; i < c; i++) {

    printf("%lld", f(fnargs[i][0], fnargs[i][1], fnargs[i][2]));

    if (i + 1 < c)
      printf("\n");
  }
  return 0;
}
