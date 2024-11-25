#include <stdio.h>

struct Trainee {
  char NamaTrainer[20], NamaPokemon[20];
  int HP, Attack, Defense, Speed;
};

int main(void) {
  int c;
  scanf("%d", &c);

  struct Trainee trainees[c];

  for (int i = 0; i < c; i++) {
    scanf("%s %s %d %d %d %d", trainees[i].NamaTrainer, trainees[i].NamaPokemon,
          &trainees[i].HP, &trainees[i].Attack, &trainees[i].Defense,
          &trainees[i].Speed);
  }

  int index, i_max = 0;
  for (int i = 0; i < c; i++) {
    int accu = trainees[i].HP + trainees[i].Speed + trainees[i].Defense +
               trainees[i].Attack;

    if (accu > i_max) {
      i_max = accu;
      index = i;
    }
  }

  printf("%s wins! %s said ez", trainees[index].NamaPokemon,
         trainees[index].NamaTrainer);

  return 0;
}
