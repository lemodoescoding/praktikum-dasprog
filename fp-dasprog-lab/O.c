#include <stdio.h>
#include <string.h>

#define furina 3
#define hutao 2
#define lyney 1

typedef struct {
  char lastCommand[10];
  char commandByS[10];
  int commandBy;
} Minion;

int main() {
  Minion minion;
  strcpy(minion.lastCommand, "");
  strcpy(minion.commandByS, "");

  int c;
  scanf("%d", &c);

  for (int i = 0; i < c; i++) {
    char orderByS[10];
    char command[10];
    int orderBy;
    scanf("%s %s", orderByS, command);

    if (strcmp(orderByS, "furina") == 0) {
      orderBy = furina;
    }
    if (strcmp(orderByS, "hutao") == 0) {
      orderBy = hutao;
    }
    if (strcmp(orderByS, "lyney") == 0) {
      orderBy = lyney;
    }

    if (i == 0 && strcmp(command, "istirahat") == 0) {
      printf("Oceanid Minion marah karena belum diperintah apa-apa, tetapi "
             "sudah disuruh istirahat!\n");
      break;
    }

    if (minion.commandBy > orderBy) {
      printf("Oceanid Minion tidak nurut karena wewenang %s lebih rendah dari "
             "%s.\n",
             orderByS, minion.commandByS);

      continue;
    }

    if (strcmp(command, minion.lastCommand) == 0 &&
        orderBy > minion.commandBy) {
      printf("Oceanid Minion sudah diperintah %s oleh %s.\n",
             minion.lastCommand, minion.commandByS);

      continue;
    }

    if (orderBy >= minion.commandBy) {
      strcpy(minion.lastCommand, command);
      strcpy(minion.commandByS, orderByS);

      minion.commandBy = orderBy;
      printf("Oceanid Minion %s sesuai keinginan %s.\n", minion.lastCommand,
             minion.commandByS);
      continue;
    }
  }
}
