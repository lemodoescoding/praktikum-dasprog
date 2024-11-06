#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isStrong = true;

// MULAI NGODING DARI SINI
// YOUR CODE STARTS HERE
int CheckNumber(char password[]) {
  int len = strlen(password);

  int containsNum = 0;
  for (int i = 0; i < len; i++) {
    if (password[i] >= 48 && password[i] <= 57) {
      containsNum = 1;
      return 1;
    }
  }

  if (containsNum == 0) {
    isStrong = false;
    return 0;
  } else {
    return 1;
  }
}

int CheckUppercase(char password[]) {
  int len = strlen(password);

  int containsCapital = 0;
  for (int i = 0; i < len; i++) {
    if (password[i] >= 65 && password[i] <= 90) {
      containsCapital = 1;
    }
  }

  if (containsCapital == 0) {
    isStrong = false;
    return 0;
  } else {
    return 1;
  }
}

int CheckKey(char password[], int key) {
  int len = strlen(password);

  int sumOfNum = 0;
  for (int i = 0; i < len; i++) {
    if (password[i] >= 48 && password[i] <= 57) {
      sumOfNum += password[i] - 48;
    }
  }

  if (sumOfNum != key) {
    isStrong = false;
    return 0;
  } else {
    return 1;
  }
}

// NGODING SAMPE SINI, mengedit kode di bawah adalah tindakan ilegal
// YOUR CODE ENDS HERE, editing codes below is illegal

int main() {
  char password[128];
  int key;
  scanf("%s %d", password, &key);
  if (!CheckNumber(password))
    printf("Password needs number\n");
  if (!CheckUppercase(password))
    printf("Password requires at least one uppercase letter\n");
  if (!CheckKey(password, key))
    printf("Digits in password not equal to key\n");
  if (isStrong)
    printf("Password is strong, just like you\n");
  else
    printf("Weak password, fix your mistakes\n");
}
