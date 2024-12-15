#include <stdio.h>

#define ll long long

ll gcd(ll a, ll b) {
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

int main() {
  ll N, K;
  scanf("%lld %lld", &N, &K);

  ll g = gcd(N, K);

  ll c = N / g;

  if (c >= N) {
    c = c - 1;
  }

  ll S = (c * (2 + (c - 1) * g)) / 2;

  printf("%lld", S);
}
