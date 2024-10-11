#include <math.h>
#include <stdio.h>

int main() {
  int T;
  scanf("%d", &T);

  int N[T];
  for (int i = 0; i < T; i++) {
    scanf("%d", &N[i]);
  }

  int modus = 0, maxCount = 0;
  for (int i = 0; i < T; i++) {
    int currentCount = 0;

    for (int j = 0; j < T; j++) {
      if (N[i] == N[j]) {
        currentCount++;
      }
    }

    if (currentCount > maxCount) {
      maxCount = currentCount;
      modus = N[i];
    }

    if (currentCount == maxCount && N[i] > modus) {
      modus = N[i];
    }
  }

  int prima = 1;
  for (int i = 2; i <= sqrt(modus); i++) {
    if (modus % i == 0) {
      prima = 0;
      break;
    }
  }

  if (prima == 1 && modus >= 2) {
    printf("Modus: %d\nWah, modusnya prima nihh.", modus);
  } else {
    printf("Modus: %d\nYah, modusnya gak prima.", modus);
  }
}
