#include <stdio.h>

int f(int x) {
  if (x % 2 == 0) {
    return x / 2;
  }

  return 2 * x;
}

int g(int x) {
  if (x % 2 == 0) {
    return x + 2;
  }

  return x - 2;
}

int pola(int x, int n) {
  if (n == 0) {
    return 0;
  }

  if (n % 2 == 0) {
    return g(x + pola(x, n - 1));
  } else {
    return f(x + pola(x, n - 1));
  }
}

int main() {
  int x, n;
  scanf("%d %d", &x, &n);

  int result = pola(x, n);

  printf("%d", result);
}
