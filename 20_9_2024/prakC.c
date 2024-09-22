#include <stdio.h>

int main() {
  long long angka;
  scanf("%lld", &angka);

  if (angka < 1000000000) {
    printf("“Gamauuu!!, mending makan potato chip!!");
    return 0;
  }
  long long bilanganA = angka / 10000000000000000;
  angka = angka - bilanganA * 10000000000000000;

  long long bilanganB = angka / 1000000000000000;
  angka = angka - bilanganB * 1000000000000000;

  long long bilanganC = angka / 100000000000000;
  angka = angka - bilanganC * 100000000000000;

  long long bilanganD = angka / 10000000000000;
  angka = angka - bilanganD * 10000000000000;

  long long bilanganE = angka / 1000000000000;
  angka = angka - bilanganE * 1000000000000;

  long long bilanganF = angka / 100000000000;
  angka = angka - bilanganF * 100000000000;

  long long bilanganG = angka / 10000000000;
  angka = angka - bilanganG * 10000000000;

  long long bilanganH = angka / 1000000000;
  angka = angka - bilanganH * 1000000000;

  long long bilanganI = angka / 100000000;
  angka = angka - bilanganI * 100000000;

  long long bilanganJ = angka / 10000000;
  angka = angka - bilanganJ * 10000000;

  long long bilanganK = angka / 1000000;
  angka = angka - bilanganK * 1000000;

  long long bilanganL = angka / 100000;
  angka = angka - bilanganL * 100000;

  long long bilanganM = angka / 10000;
  angka = angka - bilanganM * 10000;

  long long bilanganN = angka / 1000;
  angka = angka - bilanganN * 1000;

  long long bilanganO = angka / 100;
  angka = angka - bilanganO * 100;

  long long bilanganP = angka / 10;
  angka = angka - bilanganP * 10;

  long long bilanganQ = angka;

  if (bilanganA && bilanganB && bilanganC && bilanganD &&
      bilanganA == bilanganQ && bilanganB == bilanganP &&
      bilanganC == bilanganO && bilanganD == bilanganN &&
      bilanganE == bilanganM && bilanganF == bilanganL &&
      bilanganG == bilanganK && bilanganH == bilanganJ) {
    printf("Juicy!! akU sUka jUmlAh PalIndRome!!");
  } else if ((!bilanganA && bilanganB && bilanganC && bilanganD) &&
             bilanganB == bilanganQ && bilanganC == bilanganP &&
             bilanganD == bilanganO && bilanganE == bilanganN &&
             bilanganF == bilanganM && bilanganG == bilanganL &&
             bilanganH == bilanganK && bilanganI == bilanganJ) {
    printf("Juicy!! akU sUka jUmlAh PalIndRome!!");
  } else if ((!bilanganA && !bilanganB && bilanganC && bilanganD) &&
             bilanganC == bilanganQ && bilanganD == bilanganP &&
             bilanganE == bilanganO && bilanganF == bilanganN &&
             bilanganG == bilanganM && bilanganH == bilanganL &&
             bilanganI == bilanganK) {
    printf("Juicy!! akU sUka jUmlAh PalIndRome!!");
  }

  else if ((!bilanganA && !bilanganB && !bilanganC && bilanganD) &&
           bilanganD == bilanganQ && bilanganE == bilanganP &&
           bilanganF == bilanganO && bilanganG == bilanganN &&
           bilanganH == bilanganM && bilanganI == bilanganL &&
           bilanganJ == bilanganK) {
    printf("Juicy!! akU sUka jUmlAh PalIndRome!!");
  }

  else if ((!bilanganA && !bilanganB && !bilanganC && !bilanganD) &&
           bilanganE == bilanganQ && bilanganF == bilanganP &&
           bilanganG == bilanganO && bilanganH == bilanganN &&
           bilanganI == bilanganM && bilanganJ == bilanganL) {
    printf("Juicy!! akU sUka jUmlAh PalIndRome!!");
  } else {
    printf("Gamauuu!!, mending makan potato chip!!");
  }
}
