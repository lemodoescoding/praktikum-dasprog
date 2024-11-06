#include <stdio.h>

int fib(int x, int y, int z) {
  if (y > x) {
    return 0;
  }

  fib(x, z, y + z);
  printf("%d ", y);
}

int result(int x, int y, int z) {
  if (y > x) {
    return 0;
  }

  return y + result(x, z, y + z);
}

int main() {
  int c;
  scanf("%d", &c);

  fib(c, 0, 1);

  int b = result(c, 0, 1);
  printf("\n%d", b);
}
