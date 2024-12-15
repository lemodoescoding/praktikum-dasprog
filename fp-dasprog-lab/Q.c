#include <math.h>
#include <stdio.h>

#define ld long double

typedef struct {
  int x, y, z;
} Coords;

int main() {
  Coords coords[3];
  for (int i = 0; i < 3; i++) {
    scanf("%d %d %d", &coords[i].x, &coords[i].y, &coords[i].z);
  }

  ld rA, rB, rD;
  scanf("%Lf %Lf %Lf", &rA, &rB, &rD);

  ld d_AB = sqrtl(powl((coords[1].x - coords[0].x), 2) +
                  powl(coords[1].y - coords[0].y, 2) +
                  powl(coords[1].z - coords[0].z, 2));
  ld d_BC = sqrtl(powl((coords[2].x - coords[1].x), 2) +
                  powl(coords[2].y - coords[1].y, 2) +
                  powl(coords[2].z - coords[1].z, 2));

  ld d_AC = sqrtl(powl((coords[2].x - coords[0].x), 2) +
                  powl(coords[2].y - coords[0].y, 2) +
                  powl(coords[2].z - coords[0].z, 2));

  ld max_rA = rA * rD;
  ld max_rB = (rA + rB) * rD;

  ld trip_AC = max_rA - d_AC;
  ld trip_partial = max_rB - d_AB - d_BC;

  if (trip_AC >= 0) {
    printf("NAH ID WIN, NO NEED TO STOP");
  }

  else if (trip_partial >= 0) {
    printf("HHM BETTER TAKE ROCKET, STILL CAN WIN");
  }

  else {
    printf("GIVE UP ALREADY, MINING BETTER");
  }

  // 86.6025
}
