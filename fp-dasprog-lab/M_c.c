#include <stdio.h>

#define ll long long

int main() {
  ll Q, K;
  scanf("%lld %lld", &Q, &K);

  ll nums[Q];
  for (ll i = 0; i < Q; i++) {
    nums[i] = 1; // indicating alive
  }

  ll cnt = 0, cut = 0,
     // Cut = 0 gives the sword to 1st person.
      num = 1;

  // Loop continues till n-1 person dies.
  while (cnt < (Q - 1)) {

    // Checks next (kth) alive persons.
    while (num <= K) {
      cut++;

      // Checks and resolves overflow
      // of Index.
      cut = cut % Q;
      if (nums[cut] == 1) {
        // Updates the number of persons
        // alive.
        num++;
      }
    }

    // Refreshes value to 1 for next use.
    num = 1;

    // Kills the person at position of 'cut'
    nums[cut] = 0;

    // Updates the no. of killed persons.
    cnt++;
    cut++;

    // Checks and resolves overflow of Index.
    cut = cut % Q;

    // Checks the next alive person the
    // sword is to be given.
    while (nums[cut] == 0) {
      cut++;

      // Checks and resolves overflow
      // of Index.
      cut = cut % Q;
    }
  }

  // Output is the position of the last
  // man alive(Index + 1);
  printf("%lld", cut + 1);
}
