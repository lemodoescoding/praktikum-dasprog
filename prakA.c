#include <math.h>
#include <stdio.h>

int main() {
  int number;
  double hasil;
  scanf("%d", &number);

  hasil = pow(number, 2) * pow(number + 1, 2) / 4;

  printf("%.0lf", hasil);
}
