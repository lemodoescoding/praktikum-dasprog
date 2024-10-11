#include <math.h>
#include <stdio.h>

int main() {
  long long N, M, F;
  scanf("%lld %lld %lld", &N, &M, &F);

  long long NAsli = N;
  long long FAsli = F;
  int binN[64] = {0};
  int binF[64] = {0};

  for (int i = 0; F > 0; i++) {
    binF[i] = F % 2;
    F /= 2;
  }

  for (int i = 0; N > 0; i++) {
    binN[i] = N % 2;
    N /= 2;
  }

  int indeksMaks = 63;
  int cek = 0;

  long long K = 0;
  while (binF[indeksMaks] == 0)
    indeksMaks--;

  for (int i = indeksMaks; i >= 0; i--) {
    if (cek == 1 && binN[i] == 0) {
      K += pow(2, i);
      continue;
    }

    if (binF[i] == 1 && binN[i] == 1) {
      cek = 1;
    } else if (binF[i] == 1 && binN[i] == 0) {
      K += pow(2, i);
    }
  }

  if ((NAsli ^ K) - 1 >= M) {
    printf("HAHAHA, I CAN SAVE THE WORLD");
  } else {
    printf("OH NOOO, I FAILED");
  }
}
