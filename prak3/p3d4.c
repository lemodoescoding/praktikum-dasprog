#include <stdio.h>

long long sol(long long n) {
  if (n == 1)
    return 2;
  return 3 * sol(n - 1);
}

int main() {
  long long c;
  scanf("%lld", &c);

  long long result = sol(c);

  printf("Ada %lld model, bebaskan aku!", result);
}
