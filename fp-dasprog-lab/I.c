#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isValid(int i, int j, int x, int y);
bool isOdd(int num);
void DFS(int i, int j, int *grid, int *S, int x, int y, int pathIndex,
         int *path, int *p_count);

int r_dir[] = {-1, 1, 0, 0};
int c_dir[] = {0, 0, -1, 1};

int main() {
  int x, y;
  scanf("%d %d", &y, &x);

  int *grid = (int *)malloc(x * y * sizeof(int));
  int *S = (int *)malloc(x * y * sizeof(int));
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      scanf("%d", grid + i * x + j);
      *(S + i * x + j) = 0;
    }
  }

  int *path = (int *)malloc(x * y * sizeof(int));
  int p_count = 0;

  DFS(0, 0, grid, S, x, y, 0, path, &p_count);

  if (p_count == 0) {
    printf("Kucing oren tidak bisa pulang ke rumah :(");
  } else {
    printf("Terdapat %d jalan untuk kucing oren pulang", p_count);
  }

  free(grid);
  free(S);
  free(path);
  return 0;
}

bool isValid(int i, int j, int x, int y) {
  return (i >= 0 && i < y && j >= 0 && j < x);
}

bool isOdd(int num) { return (num % 2 != 0); }

void DFS(int i, int j, int *grid, int *S, int x, int y, int pathIndex,
         int *path, int *p_count) {
  *(S + i * x + j) = 1; // mark as visited

  *(path + pathIndex) = *(grid + i * x + j);

  if (*(grid + i * x + j) == 1) {
    *p_count = *p_count + 1;

  } else {
    for (int k = 0; k < 4; k++) {
      int nextRow = i + r_dir[k];
      int nextCol = j + c_dir[k];
      if (isValid(nextRow, nextCol, x, y) &&
          (*(S + nextRow * x + nextCol)) == 0 &&
          isOdd(*(grid + nextRow * x + nextCol))) {
        DFS(nextRow, nextCol, grid, S, x, y, pathIndex + 1, path, p_count);
      }
    }
  }

  *(S + i * x + j) = 0; // mark as visited
}
