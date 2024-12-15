#include <stdio.h>

long long josephus(long long Q, long long K) {
  if (Q == 1)
    return 1;
  return ((josephus(Q - 1, K) + K - 1) % Q) + 1;
}

int main() {
  long long Q, K;
  scanf("%lld %lld", &Q, &K);

  printf("yapp, sapi ke %lld sepertinya memang yang terbaik.", josephus(Q, K));
}
