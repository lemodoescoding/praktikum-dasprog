#include <stdio.h>

int main() {
  int jumlahSiswa;
  scanf("%d", &jumlahSiswa);

  int buah[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  int buahIndeks = 0;
  for (int i = 0; i < jumlahSiswa; i++) {
    scanf("%d", &buahIndeks);
    buah[buahIndeks - 1]++;
  }

  int indeksTerbesar = 0, terbesar = 0;
  int jumlahModulus = 0;

  for (int i = 0; i < 10; i++) {
    if (buah[i] >= terbesar) {
      terbesar = buah[i];
      indeksTerbesar = i;
    }

    if (i == 9) {
      jumlahModulus = 1;
    }
  }

  for (int i = 0; i < 10; i++) {
    if (buah[i] == terbesar && i != indeksTerbesar) {
      jumlahModulus++;
    }
  }

  if (jumlahModulus > 1) {
    printf("-1");
  } else {

    int remmants = jumlahSiswa - terbesar;

    printf("%d\n%d", indeksTerbesar + 1, remmants);
  }
}
