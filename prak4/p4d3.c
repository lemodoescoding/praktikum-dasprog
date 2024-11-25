#include <stdio.h>
#include <string.h>

struct Player {
  char namaPemain[20];
  char assistPemain[20];
  int goal;
  int assist;
  int keypass;
  int dribble;
};

int main() {
  int c;
  scanf("%d", &c);

  struct Player pemain[c];

  for (int i = 0; i < c; i++) {
    scanf("%s", pemain[i].namaPemain);
    pemain[i].goal = 0;
  }

  for (int i = 0; i < c; i++) {
    char pemainGol[20], pemainAssist[20];
    int poin = 0;

    scanf("%s %s %d", pemainAssist, pemainGol, &poin);

    for (int j = 0; j < c; j++) {
      if (strcmp(pemain[j].namaPemain, pemainAssist) == 0) {
        strcpy(pemain[j].assistPemain, pemainGol);
        pemain[j].assist = poin;
      }

      if (strcmp(pemain[j].namaPemain, pemainGol) == 0) {
        pemain[j].goal += poin;
      }
    }
  }

  for (int i = 0; i < c; i++) {
    scanf("%s %d %d", pemain[i].namaPemain, &pemain[i].keypass,
          &pemain[i].dribble);
  }

  int d;
  scanf("%d", &d);

  char cmd[d][20];
  for (int i = 0; i < d; i++) {
    scanf("%s", cmd[i]);
  }

  for (int i = 0; i < d; i++) {
    int flag = 0;

    if (!flag) {
      if (strcmp(cmd[i], "TABLE") == 0) {
        for (int k = 0; k < c; k++) {
          printf("%s | Goals: %d | Assists: %d | Assist To: %s \n",
                 pemain[k].namaPemain, pemain[k].goal, pemain[k].assist,
                 pemain[k].assistPemain);
        }
      } else if (strcmp(cmd[i], "MOTM") == 0) {
        char motm[20];

        int skor = -1;
        for (int k = 0; k < c; k++) {
          int skorPemain = 3 * pemain[k].goal + 2 * pemain[k].assist +
                           1 * pemain[k].keypass + 0.2 * pemain[k].dribble;

          if (skorPemain > skor) {
            skor = skorPemain;
            strcpy(motm, pemain[k].namaPemain);
          }
        }

        printf("Man of the Match: %s\n", motm);
      }
    }
  }
}
