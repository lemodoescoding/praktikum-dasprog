#include <stdio.h>

int main() {
  double x1, y1, x2, y2;
  scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

  double res1, res2;

  if (x2 == x1) {
    printf("-_-");
    return 0;
  }

  res1 = (y2 - y1) / (x2 - x1);

  res2 = y1 - res1 * x1;

  printf("%.2lf %.2lf", res1, res2);
}
