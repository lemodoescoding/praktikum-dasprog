#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Point {
  int x, y;
};

int main(void) {
  int c;
  scanf("%d", &c);

  struct Point points[c];
  for (int i = 0; i < c; i++) {
    scanf("%d %d", &points[i].x, &points[i].y);
  }

  float solution = 0;

  for (int i = 0; i < c - 1; i++) {
    int x_now = points[i].x, y_now = points[i].y;

    for (int j = i + 1; j < c; j++) {

      float solve = 0;
      int x_two = points[j].x, y_two = points[j].y;

      solve = (float)abs((x_two - x_now)) + abs((y_two - y_now));
      if (i == 0 && j == 1) {
        solution = solve;
      }

      if (solve < solution) {
        solution = solve;
      }
      solve = (float)sqrt(pow((x_two - x_now), 2) + pow((y_two - y_now), 2));

      if (solve < solution) {
        solution = solve;
      }
    }
  }

  printf("%.2f", solution);
}
