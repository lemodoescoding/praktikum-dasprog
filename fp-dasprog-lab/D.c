#include <stdio.h>
#include <string.h>

int main() {
  char nama[100];
  int N;

  scanf("%s %d", nama, &N);

  int jumlah = 0;

  if (strcmp(nama, "Ellie") == 0) {
    for (int i = 2; i <= N; i += 2) {
      if (i % 2 == 0 && i <= N) {
        jumlah += i;
      }
    }

    printf("%d", jumlah);
  } else if (strcmp(nama, "Oddie") == 0) {
    for (int i = 1; i <= N; i += 2) {
      if (i % 2 == 1 && i <= N) {
        jumlah += i;
      }
    }

    printf("%d", jumlah);
  } else {
    printf("Who is that?");
  }
}
