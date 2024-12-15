#include <stdio.h>
#include <string.h>

int main() {
  int T;
  char S[101];

  scanf("%d%s", &T, S);

  int n = strlen(S);
  S[n] = '\0';
  int p = (n + T - 1) / T;

  char kata[p][T];

  int point = 0;
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < T; j++) {
      if (point < n) {
        kata[i][j] = point;
        point++;
      } else {
        kata[i][j] = -1;
      }
    }
  }

  int k = 0;
  for (int i = 0; i < T; i++) {
    for (int j = 0; j < p; j++) {
      if (kata[j][i] != -1) {
        kata[j][i] = k++;
      }
    }
  }

  char sC[n];
  int l = 0;

  for (int i = 0; i < p; i++) {
    for (int j = 0; j < T; j++) {
      if (kata[i][j] == -1) {
        continue;
      }

      int index = kata[i][j];

      if (S[index] == '_') {
        sC[l++] = ' ';
      } else {
        sC[l++] = S[index];
      }
    }
  }

  sC[l] = '\0';

  printf("%s", sC);
}
