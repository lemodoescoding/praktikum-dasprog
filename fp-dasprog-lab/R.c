#include <math.h>
#include <stdio.h>
#define ll long long
#define ld long double
#define MOD 1000000007

// F(n) = a*F(n - 1) + b * F(n - 2)
// r^n = a*r^(n - 1) + b * r^(n - 2)
// r^2 = a * r + b
// r^2 - a * r - b = 0
// find root of r, r_1, r_2
// General function -> F(n) = C1 * r_1^n + C2 * r_2^n
// find C1 and C2 based on
// F(0) = C1 + C2
// F(1) = C1 * r_1 + C1 * r_2

ll F(ll x, ll y, ll a, ll b, ll n) {
  long double r_1 = (a + sqrtl(a * a + 4 * b)) / 2;
  long double r_2 = (a - sqrtl(a * a + 4 * b)) / 2;

  long double C2 = (x * r_1 - y) / (r_1 - r_2);
  long double C1 = (y - r_2 * x) / (r_1 - r_2);

  long double Fn_1 = (C1 * powl(r_1, n));
  long double Fn_2 = (C2 * powl(r_2, n));

  long double Fn = (Fn_1 + Fn_2);
  printf("%Lf", Fn / MOD);

  return 0;
}

int main() {
  ll x, y, a, b, n;

  scanf("%lld %lld %lld %lld %lld", &x, &y, &a, &b, &n);

  printf("%lld", F(x, y, a, b, n));
}
