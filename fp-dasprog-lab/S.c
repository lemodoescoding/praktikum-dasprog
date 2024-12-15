#include <stdio.h>

int main() {
  int saldo = 300000;

  int N, K;
  scanf("%d %d", &N, &K);

  int diskon;
  switch (N) {
  case 1:
    diskon = 35;
    break;
  case 2:
    diskon = 45;
    break;
  case 3:
    diskon = 50;
    break;
  case 4:
    diskon = 55;
    break;
  case 5:
    diskon = 40;
    break;
  }

  int harga = K - (K * diskon / 100);

  int normalOngkir = 50000;

  int diskonOngkir;
  if (harga >= 250000) {
    diskonOngkir = 0;
  } else if (harga >= 150000) {
    diskonOngkir = normalOngkir * 0.5;
  } else if (harga >= 50000) {
    diskonOngkir = normalOngkir * 0.75;
  } else {
    diskonOngkir = normalOngkir;
  }

  int totalHarga = harga + diskonOngkir;
  int sisa = saldo - totalHarga;

  if (sisa > 0) {
    printf("WOHHHH uangku sisa %d\nMamaa Surip bisa kasi THR ke adek adek, "
           "tadi totalnya %d",
           sisa, totalHarga);

    return 0;
  } else if (sisa == 0) {
    printf(
        "Yeyyy totalnya pas %d\nMamaa, Surip udah gede ga jadi minta uang :)",
        totalHarga);
  } else if (sisa < 0) {
    printf("Mamaa minta uang, uangku kurang %d :((\nTotalnya tadi %d",
           totalHarga - saldo, totalHarga);
  }
}
