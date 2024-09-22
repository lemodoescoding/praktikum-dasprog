#include <stdio.h>

int main() {
  long long angka;
  scanf("%lld", &angka);

  int bilanganA = angka / 10000000000000000;

  int bilanganB = (angka % 10000000000000000) / 1000000000000000;

  int bilanganC = (angka % 1000000000000000) / 100000000000000;

  int bilanganD = (angka % 100000000000000) / 10000000000000;

  int bilanganE = (angka % 10000000000000) / 1000000000000;

  int bilanganF = (angka % 1000000000000) / 100000000000;

  int bilanganG = (angka % 100000000000) / 10000000000;

  int bilanganH = (angka % 10000000000) / 1000000000;

  int bilanganI = (angka % 1000000000) / 100000000;

  int bilanganJ = (angka % 100000000) / 10000000;

  int bilanganK = (angka % 10000000) / 1000000;

  int bilanganL = (angka % 1000000) / 100000;

  int bilanganM = (angka % 100000) / 10000;

  int bilanganN = (angka % 10000) / 1000;

  int bilanganO = (angka % 1000) / 100;

  int bilanganP = (angka % 100) / 10;

  int bilanganQ = angka % 10;

  // 100 000 000 000 000 000
  //  10 000 000 000 000 000
  //  10 000 000 000 000 000
  if (angka >= 10000000000000000 && angka < 100000000000000000 && // angka 17
      bilanganA == bilanganQ && bilanganB == bilanganP &&
      bilanganC == bilanganO && bilanganD == bilanganN &&
      bilanganE == bilanganM && bilanganF == bilanganL &&
      bilanganG == bilanganK && bilanganH == bilanganJ) {
    printf("Juicy!! akU sUka jUmlAh PalIndRome!!");
  } else if (angka >= 1000000000000000 && angka < 10000000000000000 &&
             bilanganB == bilanganQ && bilanganC == bilanganP &&
             bilanganD == bilanganO && bilanganE == bilanganN &&
             bilanganF == bilanganM && bilanganG == bilanganL &&
             bilanganH == bilanganK && bilanganI == bilanganJ) {
    // angka 16
    printf("Juicy!! akU sUka jUmlAh PalIndRome!!");
  } else if (angka >= 100000000000000 && angka < 1000000000000000 &&
             bilanganC == bilanganQ && bilanganD == bilanganP &&
             bilanganE == bilanganO && bilanganF == bilanganN &&
             bilanganG == bilanganM && bilanganH == bilanganL &&
             bilanganI == bilanganK) {
    // angka 15
    printf("Juicy!! akU sUka jUmlAh PalIndRome!!");
  } else if (angka >= 10000000000000 && angka < 100000000000000 && // angka 14
             bilanganD == bilanganQ && bilanganE == bilanganP &&
             bilanganF == bilanganO && bilanganG == bilanganN &&
             bilanganH == bilanganM && bilanganI == bilanganL &&
             bilanganJ == bilanganK) {
    printf("Juicy!! akU sUka jUmlAh PalIndRome!!");
  } else if (angka >= 1000000000000 && angka < 10000000000000 && // angka 13
             bilanganE == bilanganQ && bilanganF == bilanganP &&
             bilanganG == bilanganO && bilanganH == bilanganN &&
             bilanganI == bilanganM && bilanganJ == bilanganL) {
    printf("Juicy!! akU sUka jUmlAh PalIndRome!!");
  } else if (angka >= 100000000000 && angka < 1000000000000 && // angka 12
             bilanganF == bilanganQ && bilanganG == bilanganP &&
             bilanganH == bilanganO && bilanganI == bilanganN &&
             bilanganJ == bilanganM && bilanganK == bilanganL) {

    printf("Juicy!! akU sUka jUmlAh PalIndRome!!");
  } else if (angka >= 10000000000 && angka < 100000000000 && // angka 11
             bilanganG == bilanganQ && bilanganH == bilanganP &&
             bilanganI == bilanganO && bilanganJ == bilanganN &&
             bilanganK == bilanganM) {

    printf("Juicy!! akU sUka jUmlAh PalIndRome!!");
  } else if (angka >= 1000000000 && angka < 10000000000 &&
             bilanganH == bilanganQ && bilanganI == bilanganP &&
             bilanganJ == bilanganO && bilanganK == bilanganN &&
             bilanganL == bilanganM) {

    printf("Juicy!! akU sUka jUmlAh PalIndRome!!");
  } else {
    printf("Gamauuu!!, mending makan potato chip!!");
  }

  return 0;
}
