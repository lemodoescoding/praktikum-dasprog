#include <stdio.h>

long long fpb(long long a, long long b) {
  if (b == 0) {
    return a;
  } else {
    return fpb(b, a % b);
  }
}

int main() {
  long long d, h;
  scanf("%lld %lld", &d, &h);

  long long result = fpb(d, h);

  printf("%lld", result);
}
