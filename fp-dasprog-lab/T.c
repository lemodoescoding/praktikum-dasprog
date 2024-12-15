#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_AREA 5

const int x_dir[] = {0, 0, 1, -1}; // L R U D
const int y_dir[] = {1, -1, 0, 0};

bool isWordExist(char *grid, char *word);
bool findMatch(char *grid, char *word, int i, int j, int x_dir, int y_dir,
               int w_Idx);

int strbin_toDec(const char *str) { return (int)strtol(str, NULL, 2); }

int main() {
  char word[6];

  scanf("%5s", word);

  char *grid = (char *)malloc(GRID_AREA * GRID_AREA * sizeof(char));

  for (int i = 0; i < GRID_AREA; i++) {
    for (int j = 0; j < GRID_AREA; j++) {
      char string[9];
      scanf("%8s", string);

      *(grid + i * GRID_AREA + j) = strbin_toDec(string);
    }
  }

  bool exist = isWordExist(grid, word);

  if (exist == 1) {
    printf("%s found", word);
  } else {
    printf("Failed to find the specified word: %s", word);
  }

  free(grid);
  return 0;
}

bool isWordExist(char *grid, char *word) {
  bool res = false;
  for (int i = 0; i < GRID_AREA; i++) {
    for (int j = 0; j < GRID_AREA; j++) {
      if (*(grid + i * GRID_AREA + j) == *(word)) {
        res = findMatch(grid, word, i, j, x_dir[0], y_dir[0], 0) ||
              findMatch(grid, word, i, j, x_dir[1], y_dir[1], 0) ||
              findMatch(grid, word, i, j, x_dir[2], y_dir[2], 0) ||
              findMatch(grid, word, i, j, x_dir[3], y_dir[3], 0);
      }
    }
  }

  return res;
}

bool findMatch(char *grid, char *word, int i, int j, int dx, int dy,
               int w_Idx) {
  int word_len = strlen(word);

  if (w_Idx == word_len)
    return true;
  if (i < 0 || i >= GRID_AREA || j < 0 || j >= GRID_AREA) {
    return false;
  }

  if (*(grid + i * GRID_AREA + j) == *(word + w_Idx)) {
    char temp = *(grid + i * GRID_AREA + j);

    *(grid + i * GRID_AREA + j) = '#';

    bool res = findMatch(grid, word, i + dx, j + dy, dx, dy, w_Idx + 1);

    *(grid + i * GRID_AREA + j) = temp;
    return res;
  }

  return false;
}
