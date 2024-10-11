#include <stdio.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);

  char cmd[n][3][1000]; // ANAGRAM | FLIP, strA, strB

  for (int i = 0; i < n; i++) {
    scanf("%s", cmd[i][0]);
    scanf("%s", cmd[i][1]);
    scanf("%s", cmd[i][2]);
  }

  for (int i = 0; i < n; i++) {
    if (strcmp(cmd[i][0], "ANAGRAM") == 0) {
      // CHECKS FOR ANAGRAM
      int charCountsStrA[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      int charCountsStrB[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

      int anagramPossible = 1;

      if (strlen(cmd[i][1]) != strlen(cmd[i][2]))
        anagramPossible = 0;

      for (int j = 0; cmd[i][1][j] && cmd[i][2][j] && anagramPossible == 1;
           j++) {
        charCountsStrA[(cmd[i][1][j] - 97)]++;
        charCountsStrB[(cmd[i][2][j] - 97)]++;
      }

      for (int k = 0; k < 26; k++) {
        if (charCountsStrA[k] != charCountsStrB[k]) {
          anagramPossible = 0;
          break;
        }
      }

      if (anagramPossible == 1) {
        printf("Hhm %s can be arranged into %s", cmd[i][1], cmd[i][2]);
      } else {
        printf("This cannot lah bro");
      }

    } else {
      // CHECKS FOR FLIP
      int lenOfA = strlen(cmd[i][1]), lenOfB = strlen(cmd[i][2]);
      int flippable = 1;

      if (lenOfA != lenOfB) {
        flippable = 0;
      }

      char listOfChar[lenOfA];
      for (int j = 0; j < lenOfA && flippable == 1; j++) {
        listOfChar[j] = cmd[i][1][j];
      }

      for (int k = lenOfB - 1; k >= 0 && flippable == 1; k--) {
        if (cmd[i][2][lenOfA - 1 - k] != listOfChar[k]) {
          flippable = 0;
          break;
        }
      }

      if (flippable == 1) {
        printf("Flip %s to get %s", cmd[i][1], cmd[i][2]);
      } else {
        printf("This cannot lah bro");
      }
    }

    if (i + 1 < n) {
      printf("\n");
    }
  }
}
