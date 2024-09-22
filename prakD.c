#include <stdio.h>

int main() {
  int A, B, C, D, E, F, G;
  scanf("%d %d %d %d %d %d %d", &A, &B, &C, &D, &E, &F, &G);

  if (A == B || A == C || A == D || A == E || A == F || B == C || B == D ||
      B == E || B == F || B == G || C == D || C == E || C == F || C == G ||
      D == E || D == F || D == G || E == F || E == G || F == G) {
    printf("SELEKSI NYA PASTI GA BENER, PREDIKSI NEUVILLETTE ADALAH MUTLAQ.");
    return 0;
  }

  int temporaryNumber;

  if (A > B) {
    temporaryNumber = B;
    B = A;
    A = temporaryNumber;
  }
  if (A > C) {
    temporaryNumber = C;
    C = A;
    A = temporaryNumber;
  }
  if (A > D) {
    temporaryNumber = D;
    D = A;
    A = temporaryNumber;
  }
  if (A > E) {
    temporaryNumber = E;
    E = A;
    A = temporaryNumber;
  }
  if (A > F) {
    temporaryNumber = F;
    F = A;
    A = temporaryNumber;
  }
  if (A > G) {
    temporaryNumber = G;
    G = A;
    A = temporaryNumber;
  }
  // A sudah terurut sebagai bilangan terkecil

  if (B > C) {
    temporaryNumber = C;
    C = B;
    B = temporaryNumber;
  }
  if (B > D) {
    temporaryNumber = D;
    D = B;
    B = temporaryNumber;
  }
  if (B > E) {
    temporaryNumber = E;
    E = B;
    B = temporaryNumber;
  }
  if (B > F) {
    temporaryNumber = F;
    F = B;
    B = temporaryNumber;
  }
  if (B > G) {
    temporaryNumber = G;
    G = B;
    B = temporaryNumber;
  }
  // B sudah terurut terkecil ke-2

  if (C > D) {
    temporaryNumber = D;
    D = C;
    C = temporaryNumber;
  }
  if (C > E) {
    temporaryNumber = E;
    E = C;
    C = temporaryNumber;
  }
  if (C > F) {
    temporaryNumber = F;
    F = C;
    C = temporaryNumber;
  }
  if (C > G) {
    temporaryNumber = G;
    G = C;
    C = temporaryNumber;
  }
  // C sudah terurut terkecil ke-3

  if (D > E) {
    temporaryNumber = E;
    E = D;
    D = temporaryNumber;
  }
  if (D > F) {
    temporaryNumber = F;
    F = D;
    D = temporaryNumber;
  }
  if (D > G) {
    temporaryNumber = G;
    G = D;
    D = temporaryNumber;
  }
  // D terurut, intine begitu

  if (E > F) {
    temporaryNumber = F;
    F = E;
    E = temporaryNumber;
  }
  if (E > G) {
    temporaryNumber = G;
    G = E;
    E = temporaryNumber;
  }
  // E terurut

  if (F > G) {
    temporaryNumber = G;
    G = F;
    F = temporaryNumber;
  }
  // F dan G otomatis menjadi ke-2 dan ke-1 terbesar

  printf("Peringkat 1 memiliki kekuatan sebesar %d, AJAK DIA BERPETUALANG.\n",
         G);
  printf("Peringkat 2 memiliki kekuatan sebesar %d, AJAK DIA BERPETUALANG.\n",
         F);
  printf("Peringkat 3 memiliki kekuatan sebesar %d, AJAK DIA BERPETUALANG.\n",
         E);
  printf("Peringkat 4 memiliki kekuatan sebesar %d, YAH KEKUATANMU KURENG.\n",
         D);
  printf("Peringkat 5 memiliki kekuatan sebesar %d, YAH KEKUATANMU KURENG.\n",
         C);
  printf("Peringkat 6 memiliki kekuatan sebesar %d, YAH KEKUATANMU KURENG.\n",
         B);
  printf("Peringkat 7 memiliki kekuatan sebesar %d, YAH KEKUATANMU KURENG.\n",
         A);
}
