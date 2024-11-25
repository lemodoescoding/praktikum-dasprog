#include <stdio.h>

#define ll long long

ll solve(int n, ll a, ll b, ll c) {
  if (n == 0)
    return 0;
  if (n == 1)
    return a;
  if (n == 2)
    return b;
  if (n == 3)
    return c;

  return solve(n - 1, b, c, a + b + c);
}

void printing(int n) {
  if (n < 0) {
    return;
  } else {
    printf("%lld ", solve(n, 1, 2, 3));
    printing(n - 2);
  }
}

int main() {
  int c;
  scanf("%d", &c);

  printing(c);
}
