#include <stdio.h>
#include <string.h>

void swap(char *pa, char *pb);

int getPrecedence(char key) {
  switch (key) {
  case 'q':
    return 1;
  case 'w':
    return 2;
  case 'e':
    return 3;
  case 'r':
    return 4;
  case 't':
    return 5;
  case 'y':
    return 6;
  case 'u':
    return 7;
  case 'i':
    return 8;
  case 'o':
    return 9;
  case 'p':
    return 10;
  case 'a':
    return 11;
  case 's':
    return 12;
  case 'd':
    return 13;
  case 'f':
    return 14;
  case 'g':
    return 15;
  case 'h':
    return 16;
  case 'j':
    return 17;
  case 'k':
    return 18;
  case 'l':
    return 19;
  case 'z':
    return 20;
  case 'x':
    return 21;
  case 'c':
    return 22;
  case 'v':
    return 23;
  case 'b':
    return 24;
  case 'n':
    return 25;
  case 'm':
    return 26;
  }
}

void swap(char *pa, char *pb) {
  char temp = *pa;
  *pa = *pb;
  *pb = temp;
}

int main() {
  char s[100001];
  scanf("%s", s);

  for (int i = strlen(s) - 1; i > 0; i--) {
    if (getPrecedence(s[i]) > getPrecedence(s[i - 1])) {
      int x;
      for (int j = i; j < strlen(s); j++) {
        if (getPrecedence(s[j]) <= getPrecedence(s[i - 1]))
          break;

        x = j;
      }

      swap(&s[i - 1], &s[x]);

      for (int j = i; j < (i + strlen(s)) / 2; j++) {
        swap(&s[j], &s[strlen(s) + i - j - 1]);
      }

      break;
    }
  }

  printf("%s", s);
}
