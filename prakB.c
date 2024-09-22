#include <stdio.h>

int main() {
  // perbandingan biaya dengan duraasi vid adalah >= 15000
  double durasi, biaya; // detik, rupiah
  scanf("%lf %lf", &durasi, &biaya);

  durasi = durasi / 60;
  double banding = biaya / durasi;

  if ((durasi > (10) || biaya >= 1000000000)) {
    if (durasi > (10) && biaya >= 1000000000) {
      printf("GAK MASUK AKAL\n");
    } else {
      printf("GUWENDENG\n");
    }
  }

  if (banding >= 15000) {
    printf("PAHAM!");
  } else {
    printf("Tapi tunggu dulu ;D");
  }
}
