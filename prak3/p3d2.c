#include <stdio.h>

long long maks(long long p) {
  if (p == 1)
    return 1;

  return p + maks(p - 1);
}

long long rekursi(long long x) {
  if (x == 1) {
    return 1;
  }

  return 2 * rekursi(x - 1) + maks(x);
}

int main() {
  long long c;
  scanf("%lld", &c);

  long long b = rekursi(c);

  printf("%lld", b);
}
