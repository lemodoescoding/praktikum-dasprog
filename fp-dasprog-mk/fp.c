#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>

#define MAX_DATA 300

#define ll long long

typedef struct {
  float ips;
} IPS;

typedef struct {
  char nrp[11];
  char nama[50];
  char jurusan[50];
  int semester;
  float ipk;
  IPS ipsSemester[8];
} Mahasiswa;

void createDBFile();                                            // done
void writeToFile(Mahasiswa *, int, char *, int *, Mahasiswa *); // done
int readFromFile(Mahasiswa *, Mahasiswa *, int, int *, char *); // done
void beforeLeavesProgram(int, int, Mahasiswa *, Mahasiswa *, char *,
                         int *); // done

void copySingleDataToAnotherStruct(Mahasiswa *, Mahasiswa *); // done
ll convertNRP(char string[]);                                 // done
void swapData(Mahasiswa *, Mahasiswa *);                      // done
void updateIPS(Mahasiswa *, int);                             // done
void insertIPS(Mahasiswa *);                                  // done

void inputData(Mahasiswa *, int *, int *); // done
void addData(Mahasiswa *, int, int);       // done
void updateData(Mahasiswa *, int);         // done
int deleteData(Mahasiswa *, int);          // done
void modifyData(Mahasiswa *, int);         // done
void readAll(Mahasiswa *, int);            // done
void readOnRange(Mahasiswa *, int, int);   // done
int deleteAllData(Mahasiswa *, int);       // done

void printDetailData(Mahasiswa *, int);  // done
void sortData(Mahasiswa *, int);         // done
void sortByHighestIPK(Mahasiswa *, int); // done
void sortByNRP(Mahasiswa *, int);        // done
void searchData(Mahasiswa *, int);       // done

void getMahasiswaSpesificSemester(Mahasiswa *, Mahasiswa *, int, int); // done
void printStatisticDatas(Mahasiswa *, int);                            // done
void findAvgIPK(Mahasiswa *, int, bool);                               // done
void findLowestIPK(Mahasiswa *, int);                                  // done
void findHighestIPK(Mahasiswa *, int);                                 // done
void readSpecificData(Mahasiswa *);                                    // done
void clearScreen();                                                    // done
void showProgramMenu(Mahasiswa *, Mahasiswa *, int *, int *,
                     int *); // on-progress
void clearScreen() { system("cls||clear"); }

void getMahasiswaSpesificSemester(Mahasiswa *mhs, Mahasiswa *dataSementara,
                                  int smt, int jumlah) {

  int j = 0;
  for (int i = 0; i < jumlah; i++) {

    if (mhs[i].semester == smt) {
      copySingleDataToAnotherStruct(&mhs[i], &dataSementara[j]);
      j++;
    }
  }
}

void printStatisticDatas(Mahasiswa *mhs, int jumlah) {
  if (jumlah == 0) {
    printf("Data Mahasiswa Kosong!\n");
    return;
  }
  int jmlMhsPerSemester[8] = {0, 0, 0, 0, 0, 0, 0, 0};

  for (int i = 0; i < jumlah; i++) {
    jmlMhsPerSemester[(mhs[i].semester - 1)] += 1;
  }

  Mahasiswa *dataSementara;
  dataSementara = (Mahasiswa *)calloc(MAX_DATA, sizeof(Mahasiswa));

  for (int i = 0; i < 8; i++) {
    if (jmlMhsPerSemester[i] > 0) {
      getMahasiswaSpesificSemester(mhs, dataSementara, i + 1, jumlah);

      printf("\n---------------------------------------------------------------"
             "------"
             "------------------------------\n");

      printf("Statistik Data Mahasiswa pada semester %d: \n\n", i + 1);

      findLowestIPK(dataSementara, jmlMhsPerSemester[i]);
      findHighestIPK(dataSementara, jmlMhsPerSemester[i]);

      printf("\n\n");
      findAvgIPK(dataSementara, jmlMhsPerSemester[i], false);
    }

    if (jmlMhsPerSemester[i + 1] != 0) {

      char next;
      printf("Tampilkan Data selanjutnya? ");
      scanf(" %c", &next);

      if (next == 'n' || next == 'N') {
        break;
      } else if (next == 'y' || next == 'Y') {
        clearScreen();
        continue;
      } else {
        break;
      }
    }
  }

  free(dataSementara);
}
void findAvgIPK(Mahasiswa *mhs, int jumlah, bool includeAll) {
  if (jumlah == 0) {
    printf("Data Mahasiswa Kosong!\n");
    return;
  }

  float avgPerSmt[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  int studentPerSmt[8] = {0, 0, 0, 0, 0, 0, 0, 0};

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < jumlah; j++) {
      if (mhs[j].semester == i + 1) {
        avgPerSmt[i] += mhs[j].ipk;
        studentPerSmt[i]++;
      } else {
        continue;
      }
    }
  }

  for (int i = 0; i < 8; i++) {
    if (studentPerSmt[i] > 0 && includeAll == false) {
      printf("Rata-rata IPK Semester %d: %.2f\t Jumlah Mahasiswa: %d\n\n",
             i + 1, avgPerSmt[i] / studentPerSmt[i], studentPerSmt[i]);
    }

    if (includeAll == true) {
      printf("Rata-rata IPK Semester %d: %.2f\t Jumlah Mahasiswa: %d\n\n",
             i + 1, avgPerSmt[i] / studentPerSmt[i], studentPerSmt[i]);
    }
  }
}

void searchData(Mahasiswa *mhs, int jumlah) {
  if (jumlah == 0) {
    printf("Jumlah Data Mahasiswa kosong!\n");
    return;
  }

  bool stop = false;
  do {
    int ch;
    printf("Ketik -1 untuk membatalkan\n");
    printf("Ingin mencari berdasarkan apa?\n1. Nama\n2. NRP\n3. Jurusan\n4. "
           "IPK\nPilih: ");
    scanf(" %d", &ch);

    if (ch == -1)
      return;
    if (ch != 1 && ch != 2 && ch != 3 && ch != 4) {
      printf("Pilihan Invalid\n");
      return;
    }

    int len = 0;

    char string[51];
    float ipkSearch;
    int ipkPilihan;

    if (ch != 4) {
      do {
        printf("Input Search: (minimal 2 karakter) ");
        scanf(" %[^\n]", string);

        len = strlen(string);
      } while (len < 2);
    } else {
      printf("Masukkan IPK : ");
      scanf(" %f", &ipkSearch);

      do {
        printf(
            "Pencarian IPK berdasarkan apa? (Diatas, Dibawah, Tepat) (1/2/3) ");
        scanf(" %d", &ipkPilihan);
        if (ipkPilihan != 1 && ipkPilihan != 2 && ipkPilihan != 3) {
          printf("Input tidak valid");
          continue;
        }

        break;
      } while (1);
    }

    Mahasiswa *dataSementara;
    dataSementara = (Mahasiswa *)calloc(100, sizeof(Mahasiswa));

    int found = 0;

    if (ch == 1 || ch == 2 || ch == 3) {
      int j = 0;
      for (int i = 0; i < jumlah; i++) {
        if (strstr(mhs[i].nama, string) != NULL && ch == 1) {
          dataSementara[j++] = mhs[i];
          found++;
          continue;
        }
        if (strstr(mhs[i].nrp, string) != NULL && ch == 2) {
          dataSementara[j++] = mhs[i];
          found++;
          continue;
        }
        if (strstr(mhs[i].jurusan, string) != NULL && ch == 3) {
          dataSementara[j++] = mhs[i];
          found++;
          continue;
        }
      }
    } else {
      int j = 0;
      for (int i = 0; i < jumlah; i++) {
        if ((mhs[i].ipk > ipkSearch) && ipkPilihan == 1) {
          dataSementara[j++] = mhs[i];
          found++;
          continue;
        }

        if (mhs[i].ipk < ipkSearch && ipkPilihan == 2) {
          dataSementara[j++] = mhs[i];
          found++;
          continue;
        }

        if (mhs[i].ipk == ipkSearch && ipkPilihan == 3) {
          dataSementara[j++] = mhs[i];
          found++;
          continue;
        }
      }
    }

    if (found > 0) {
      readAll(dataSementara, found);
    } else {
      printf("Tidak ada data yang cocok\n");
    }

    free(dataSementara);

    char chEnd = 'y';
    fflush(stdin);
    printf("\nIngin Mencari Data lagi? (y/n): ");
    scanf(" %[^\n]", &chEnd);

    if ((chEnd == 'n' || chEnd == 'N')) {
      stop = true;
    }

  } while (stop == false);

  return;
}

void findLowestIPK(Mahasiswa *mhs, int jumlah) {
  if (jumlah == 0) {
    printf("Data Mahasiswa Kosong!\n");
    return;
  }

  float lowestIPK = 4.1;
  int lowestIndex = 0;

  for (int i = 0; i < jumlah; i++) {
    if (mhs[i].ipk < lowestIPK) {
      lowestIPK = mhs[i].ipk;
      lowestIndex = i;
    }
  }

  printf("\nMahasiswa dengan IPK terendah:\n");
  readOnRange(mhs, lowestIndex, lowestIndex + 1);
}

void findHighestIPK(Mahasiswa *mhs, int jumlah) {
  if (jumlah == 0) {
    printf("Jumlah Data Mahasiswa Kosong!\n");
    return;
  }

  int highestIndex = 0;
  float highestIPK = 0;
  for (int i = 0; i < jumlah; i++) {
    if (mhs[i].ipk > highestIPK) {
      highestIPK = mhs[i].ipk;
      highestIndex = i;
    }
  }

  printf("\nMahasiswa dengan IPK tertinggi:\n");
  readOnRange(mhs, highestIndex, highestIndex + 1);
}

void copySingleDataToAnotherStruct(Mahasiswa *source, Mahasiswa *dest) {
  strcpy(dest->nama, source->nama);
  strcpy(dest->jurusan, source->jurusan);
  strcpy(dest->nrp, source->nrp);
  dest->semester = source->semester;
  dest->ipk = source->ipk;
  dest->ipsSemester[0].ips = source->ipsSemester[0].ips;
  dest->ipsSemester[1].ips = source->ipsSemester[1].ips;
  dest->ipsSemester[2].ips = source->ipsSemester[2].ips;
  dest->ipsSemester[3].ips = source->ipsSemester[3].ips;
  dest->ipsSemester[4].ips = source->ipsSemester[4].ips;
  dest->ipsSemester[5].ips = source->ipsSemester[5].ips;
  dest->ipsSemester[6].ips = source->ipsSemester[6].ips;
  dest->ipsSemester[7].ips = source->ipsSemester[7].ips;
}

void sortByNama(Mahasiswa *mhs, int jumlah) {
  if (jumlah == 0) {
    printf("Data Mahasiswa Kosong!\n");
    return;
  }

  int sortBy;
  printf("Ketik -1 untuk membatalkan\n");
  printf("Sort berdasarkan ASC/DESC? (1/2) ");
  scanf(" %d", &sortBy);

  if (sortBy == -1)
    return;
  if (sortBy != 1 && sortBy != 2) {
    printf("Pilihan Invalid\n");
    return;
  }

  Mahasiswa *dataSementara;
  dataSementara = (Mahasiswa *)calloc(jumlah, sizeof(Mahasiswa));

  for (int i = 0; i < jumlah; i++) {
    copySingleDataToAnotherStruct(&mhs[i], &dataSementara[i]);
  }

  int i, didSwap = 1;
  while (didSwap) {
    didSwap = 0;
    for (i = 0; i < jumlah - 1; i++) {
      if (strcmp(dataSementara[i].nama, dataSementara[i + 1].nama) > 0 &&
          sortBy == 1) {
        swapData(&dataSementara[i], &dataSementara[i + 1]);
        didSwap = 1;
      } else if (strcmp(dataSementara[i].nama, dataSementara[i + 1].nama) < 0 &&
                 sortBy == 2) {
        swapData(&dataSementara[i], &dataSementara[i + 1]);
        didSwap = 1;
      }
    }
  }

  readAll(dataSementara, jumlah);

  char ch;
  printf("\nIngin menyimpan data secara permanen di program? (y/n) ");
  scanf(" %c", &ch);

  if ((ch == 'Y' || ch == 'y')) {
    for (int i = 0; i < jumlah; i++) {
      copySingleDataToAnotherStruct(&dataSementara[i], &mhs[i]);
    }

    printf("Data tersimpan!\n");
  } else {
    printf("Tidak menyimpan data secara permanen\n");
  }

  free(dataSementara);

  return;
}

void sortByNRP(Mahasiswa *mhs, int jumlah) {
  if (jumlah == 0) {
    printf("Jumlah Data Mahasiswa kosong!\n");
    return;
  }

  int sortBy;
  printf("Ketik -1 untuk membatalkan\n");
  printf("Sort berdasarkan ASC/DESC? (1/2) ");
  scanf(" %d", &sortBy);

  if (sortBy == -1)
    return;
  if (sortBy != 1 && sortBy != 2) {
    printf("Pilihan Invalid\n");
    return;
  }

  Mahasiswa *dataSementara;
  dataSementara = (Mahasiswa *)calloc(jumlah, sizeof(Mahasiswa));

  for (int i = 0; i < jumlah; i++) {
    copySingleDataToAnotherStruct(&mhs[i], &dataSementara[i]);
  }

  for (int i = 0; i < jumlah; i++) {
    for (int j = i + 1; j < jumlah; j++) {
      if ((ll)convertNRP(dataSementara[i].nrp) <
              (ll)convertNRP(dataSementara[j].nrp) &&
          sortBy == 1) {
        swapData(&dataSementara[i], &dataSementara[j]);
        continue;
      }

      else if ((ll)convertNRP(dataSementara[i].nrp) >
                   (ll)convertNRP(dataSementara[j].nrp) &&
               sortBy == 2) {
        swapData(&dataSementara[i], &dataSementara[j]);
        continue;
      }
    }
  }

  readAll(dataSementara, jumlah);

  char ch;
  printf("\nIngin menyimpan data secara permanen di program? (y/n) ");
  scanf(" %c", &ch);

  if ((ch == 'Y' || ch == 'y')) {
    for (int i = 0; i < jumlah; i++) {
      copySingleDataToAnotherStruct(&dataSementara[i], &mhs[i]);
    }

    printf("Data tersimpan!\n");
  } else {
    printf("Tidak menyimpan data secara permanen\n");
  }

  free(dataSementara);

  return;
}

void sortByHighestIPK(Mahasiswa *mhs, int jumlah) {
  if (jumlah == 0) {
    printf("Jumlah Data Mahasiswa kosong!\n");
    return;
  }

  Mahasiswa *dataSementara;
  dataSementara = (Mahasiswa *)calloc(jumlah, sizeof(Mahasiswa));

  for (int i = 0; i < jumlah; i++) {
    copySingleDataToAnotherStruct(&mhs[i], &dataSementara[i]);
  }

  for (int i = 0; i < jumlah; i++) {
    for (int j = i + 1; j < jumlah; j++) {
      if (dataSementara[i].ipk < dataSementara[j].ipk) {
        swapData(&dataSementara[i], &dataSementara[j]);
        continue;
      }
    }
  }

  readAll(dataSementara, jumlah);

  char ch;
  printf("\nIngin menyimpan data secara permanen? (y/n) ");
  scanf(" %c", &ch);

  if (ch != 'n' || ch != 'N') {
    for (int i = 0; i < jumlah; i++) {
      copySingleDataToAnotherStruct(&dataSementara[i], &mhs[i]);
    }
  }

  free(dataSementara);

  return;
}

void sortData(Mahasiswa *mhs, int jumlah) {
  int pil;
  printf("Urutkan berdasarkan apa?\n1. NRP\n2. IPK\n3. Nama\n\n");
  printf("Pilih: ");
  scanf(" %d", &pil);

  if (pil != 1 && pil != 2 && pil != 3) {
    printf("Input Invalid!\n");
    return;
  }

  if (pil == 1) {
    sortByNRP(mhs, jumlah);
    return;
  } else if (pil == 2) {
    sortByHighestIPK(mhs, jumlah);
  } else if (pil == 3) {
    sortByNama(mhs, jumlah);
  }
}

void printDetailData(Mahasiswa *mhs, int jumlah) {
  if (jumlah == 0) {
    printf("Data Mahasiswa Kosong\n");
    return;
  }

  char nrp[11];
  printf("Input NRP: ");
  scanf(" %s", nrp);

  for (int i = 0; i < jumlah; i++) {
    if (strcmp(mhs[i].nrp, nrp) == 0) {
      printf("Data ditemukan!\n\n");

      readSpecificData(&mhs[i]);
      return;
    }
  }

  printf("Data dengan NRP tidak ada di Database!\n");
  return;
}

int deleteAllData(Mahasiswa *mhs, int jumlah) {
  if (jumlah == 0) {
    printf("Data Mahasiswa Kosong\n");
    return jumlah;
  }

  bool stop = false;

  char yakin;

  do {
    printf("Yakin menghapus semua data? (y/n) ");
    scanf(" %c", &yakin);

    if (yakin == 'n' || yakin == 'N') {
      stop = true;
    } else {
      stop = true;
    }
  } while (stop == false);

  if (yakin == 'n' || yakin == 'N') {
    printf("Proses dibatalkan\n");
    return jumlah;
  }

  free(mhs);

  printf("Data berhasil terhapus\n");
  return 0;
}

void insertIPS(Mahasiswa *mhs) {
  float ipk = 0;
  for (int j = 0; j < 8; j++) {
    if (j + 1 <= mhs->semester) {
      printf("Masukkan data IPS Semester %d: ", j + 1);
      scanf(" %f", &mhs->ipsSemester[j].ips);

    } else {
      mhs->ipsSemester[j].ips = 0.0;
    }

    ipk += mhs->ipsSemester[j].ips;
  }

  ipk = ipk / mhs->semester;
  mhs->ipk = ipk;
}

void updateIPS(Mahasiswa *mhs, int smt) {
  printf("Inputkan data IPS Semester yang perlu diupdate: (input all untuk "
         "update semua))\n(");
  float ipk = 0;
  for (int i = 0; i < smt; i++) {
    printf("%d", i + 1);
    if (i + 1 < smt)
      printf(" ,");
  }
  printf(") ");

  char smtPil[50];
  scanf(" %[^\n]s", smtPil);
  smtPil[strlen(smtPil)] = '\0';

  if (strcmp(smtPil, "all") == 0) {
    for (int j = 0; j < 8; j++) {
      if (j + 1 <= smt) {
        printf("Input IPS Semester %d: ", j + 1);
        scanf(" %f", &mhs->ipsSemester[j].ips);
      } else {
        mhs->ipsSemester[j].ips = 0.0;
      }

      ipk += mhs->ipsSemester[j].ips;
    }

    ipk = ipk / mhs->semester;
    mhs->ipk = ipk;

    printf("Data berhasil diubah!\n");
    return;
  }

  for (int i = smt - 1; i < 8; i++) {
    mhs->ipsSemester[i].ips = 0.0;
  }

  char *token = strtok(smtPil, ",");
  while (token != NULL) {
    int pil = *token - '0';

    if (pil < 1 || pil > 8) {
      printf("Input tidak valid\n");
    } else {
      printf("Input IPS Semester %d ", pil);
      scanf(" %f", &mhs->ipsSemester[pil - 1].ips);
    }

    token = strtok(NULL, ",");
  }

  return;
}

void modifyData(Mahasiswa *mhs, int iAwal) {
  bool stop;
  do {
    printf("Data apa saja yang ingin diubah?\n");
    printf("1. NRP\n2. Nama\n3. Jurusan\n4. Semester (Update IPS per smt)\n");
    printf("Pilih: (pisahkan dengan , jika banyak, atau all jika semua) ");

    char string[10];
    scanf(" %s", string);

    if (strcmp(string, "all") == 0) {
      addData(mhs, iAwal, iAwal + 1);
      return;
    }

    char *token = strtok(string, " ,");
    while (token != NULL) {
      int pil = *token - '0';

      fflush(stdin);

      if (pil == 1) {
        printf("Input NRP baru: ");
        scanf(" %[^\n]", mhs[iAwal].nrp);
      } else if (pil == 2) {
        printf("Input Nama baru: ");
        scanf(" %[^\n]", mhs[iAwal].nama);
      } else if (pil == 3) {
        printf("Input Jurusan baru: ");
        scanf(" %[^\n]", mhs[iAwal].jurusan);
      } else if (pil == 4) {
        printf("Input Semester baru: ");
        scanf(" %d", &mhs[iAwal].semester);

        updateIPS(&mhs[iAwal], mhs[iAwal].semester);
      } else {
        printf("Input tidak valid");
      }

      token = strtok(NULL, " ,");
    }

    readSpecificData(&mhs[iAwal]);

    char yakin;
    printf("Sudah yakin? (y/n) ");
    scanf(" %c", &yakin);

    if (yakin != 'n' || yakin != 'N') {
      stop = false;
    } else {
      stop = true;
    }

  } while (stop == true);
}

void updateData(Mahasiswa *mhs, int jumlah) {
  if (jumlah == 0) {
    printf("Data Mahasiswa Kosong\n");
    return;
  }

  char nrp[50];
  printf("Ketik -1 untuk membatalkan\n");
  printf("Masukkan data dengan NRP yang ingin diupdate: ");
  scanf(" %s", nrp);

  if (strcmp(nrp, "-1") == 0)
    return;

  for (int i = 0; i < jumlah; i++) {
    if (strcmp(mhs[i].nrp, nrp) == 0) {
      printf("Data ditemukan!\n\n");
      modifyData(mhs, i);
      /* addData(mhs, i, i + 1); */

      printf("Data berhasil diubah\n");
      return;
    }
  }

  printf("Data dengan NRP tidak ditemukan\n");
  return;
}

void readSpecificData(Mahasiswa *mhs) {
  printf(
      "\n---------------------------------------------------------------------"
      "------------------------------\n");
  printf("NRP\t\tNama\t\t\t\tJurusan\t\t\tIPK\tSemester\n");
  printf("--------------------------------------------------------------------"
         "-------------------------------\n");
  printf("%10s\t%-25s\t%-20s\t%.2f\t%d\n", mhs->nrp, mhs->nama, mhs->jurusan,
         mhs->ipk, mhs->semester);
  printf(
      "\n---------------------------------------------------------------------"
      "------------------------------\n");
  printf("Data IPS per Semester (Urut 1 - 8)\n\n");
  printf("\t1\t2\t3\t4\t5\t6\t7\t8\n\t");
  for (int i = 0; i < 8; i++) {
    printf("%-2.2f", mhs->ipsSemester[i].ips);

    if (i + 1 < 8)
      printf("\t");
    else
      printf("\n");
  }

  printf(
      "\n---------------------------------------------------------------------"
      "------------------------------\n");
}

void readOnRange(Mahasiswa *mhs, int iStart, int iEnd) {
  if (iStart == iEnd) {
    printf("Range tidak valid");
    return;
  }

  printf(
      "\n---------------------------------------------------------------------"
      "------------------------------\n");
  printf("No\tNRP\t\tNama\t\t\t\tJurusan\t\t\tIPK\tSemester\n");
  printf("--------------------------------------------------------------------"
         "-------------------------------\n");

  int j = 0;
  for (int i = iStart; i < iEnd; i++) {
    printf("%d\t%10s\t%-25s\t%-20s\t%.2f\t%d\n", ++j, mhs[i].nrp, mhs[i].nama,
           mhs[i].jurusan, mhs[i].ipk, mhs[i].semester);
  }
}

void readAll(Mahasiswa *mhs, int jumlah) {
  int limit;
  if (jumlah == 0) {
    printf("Data Mahasiswa Kosong\n");
    return;
  }

  if (jumlah > 5) {
    do {
      printf("Input jumlah data yang akan dilimit ketika di tampilkan (minimal "
             "5): ");
      scanf(" %d", &limit);
    } while (limit < 5);
  } else {
    limit = jumlah;
  }

  printf(
      "\n---------------------------------------------------------------------"
      "------------------------------\n");
  printf("No\tNRP\t\tNama\t\t\t\tJurusan\t\t\tIPK\tSemester\n");
  printf("--------------------------------------------------------------------"
         "-------------------------------\n");
  int j = 0;
  do {
    for (int i = limit * j; i < limit * (j + 1); i++) {
      if (i < jumlah) {
        printf("%d\t%10s\t%-25s\t%-20s\t%.2f\t%d\n", i + 1, mhs[i].nrp,
               mhs[i].nama, mhs[i].jurusan, mhs[i].ipk, mhs[i].semester);
      }
    }
    if (limit * (j + 1) < jumlah) {
      char ch;
      printf("\nLanjutkan tampilkan %d data selanjutnya? (y/n)", limit);
      scanf(" %c", &ch);

      if (ch == 'n' || ch == 'N') {
        return;
      }

      printf("\n");

      j++;
    } else {
      return;
    }
  } while (1);
}

int deleteData(Mahasiswa *mhs, int jumlah) {
  if (jumlah == 0) {
    printf("Data Mahasiswa Kosong\n");
    return 0;
  }

  char nrp[50];
  printf("Ketik -1 untuk membatalkan\n");
  printf("Masukkan data dengan NRP yang ingin dihapus: ");
  scanf(" %s", nrp);

  if (strcmp(nrp, "-1") == 0)
    return jumlah;

  for (int i = 0; i < jumlah; i++) {
    if (strcmp(mhs[i].nrp, nrp) == 0) {
      char ch;
      printf("Berhasil ditemukan, Yakin ingin menghapus data? (y/n) ");
      scanf(" %c", &ch);

      if (ch == 'n') {
        return jumlah;
      }

      for (int j = i; j < jumlah; j++) {
        mhs[j] = mhs[j + 1];
      }

      printf("Data berhasil dihapus\n");
      return jumlah - 1;
    }
  }

  printf("Data dengan NRP tersebut tidak ada.\n");
  return jumlah;
}

void inputData(Mahasiswa *mhs, int *jml, int *jmlSementara) {
  printf("Data maksimal per file adalah %d data\n", MAX_DATA);
  printf("Jumlah Data sekarang: %d dari %d\n\n", *jml, MAX_DATA);

  bool ulangi = false;

  do {
    printf("Ketik 0 untuk membatalkan\n");
    printf("Jumlah data yang akan diinput? ");
    scanf(" %d", jmlSementara);

    if (*jmlSementara == 0) {
      return;
    }

    if (*jml + *jmlSementara > 100) {
      printf("Data melebihi kapasitas (100)\n");
      ulangi = true;
    } else {

      ulangi = false;
    }

  } while (ulangi == true);

  addData(mhs, *jml, *jml + *jmlSementara);
  *jml += *jmlSementara;

  printf("Data berhasil ditambahkan\n");

  *jmlSementara = 0;
}

void addData(Mahasiswa *mhs, int iAwal, int iEnd) {
  for (int i = iAwal; i < iEnd; i++) {
    printf("Masukkan NRP: ");
    scanf(" %s", mhs[i].nrp);
    printf("Masukkan Nama: ");
    scanf(" %[^\n]", mhs[i].nama);
    printf("Masukkan Jurusan: ");
    scanf(" %[^\n]", mhs[i].jurusan);
    printf("Masukkan Semester: ");
    scanf(" %d", &mhs[i].semester);
    printf("Masukkan IPS: ");
    insertIPS(&mhs[i]);
  }
}

void beforeLeavesProgram(int jumlahAwal, int jumlahAkhir, Mahasiswa *mhs,
                         Mahasiswa *dataLama, char *filename, int *jmlAwal) {
  if (strcmp(filename, "") == 0) {
    return;
  }

  if (jumlahAwal == jumlahAkhir) {

    bool check = true;
    for (int i = 0; i < jumlahAkhir; i++) {
      check = strcmp(mhs[i].nama, dataLama[i].nama) == 0 &&
              strcmp(mhs[i].jurusan, dataLama[i].jurusan) == 0 &&
              strcmp(mhs[i].nrp, dataLama[i].nrp) == 0 &&
              mhs[i].semester == dataLama[i].semester &&
              mhs[i].ipk == dataLama[i].ipk &&
              dataLama[i].ipsSemester[0].ips == mhs[i].ipsSemester[0].ips &&
              dataLama[i].ipsSemester[1].ips == mhs[i].ipsSemester[1].ips &&
              dataLama[i].ipsSemester[2].ips == mhs[i].ipsSemester[2].ips &&
              dataLama[i].ipsSemester[3].ips == mhs[i].ipsSemester[3].ips &&
              dataLama[i].ipsSemester[4].ips == mhs[i].ipsSemester[4].ips &&
              dataLama[i].ipsSemester[5].ips == mhs[i].ipsSemester[5].ips &&
              dataLama[i].ipsSemester[6].ips == mhs[i].ipsSemester[6].ips &&
              dataLama[i].ipsSemester[7].ips == mhs[i].ipsSemester[7].ips;

      if (check == false) {
        break;
      }
    }

    if (check == true)
      return;
  }

  char ch;
  printf("Program mendeteksi adanya perubahan data, namun belum di save, save "
         "ke file? (y/n) ");
  scanf(" %c", &ch);

  if (ch != 'n' && ch != 'N') {
    writeToFile(mhs, jumlahAkhir, filename, jmlAwal, dataLama);
    return;
  }

  return;
}

void writeToFile(Mahasiswa *mhs, int jumlah, char *filename, int *jmlAwal,
                 Mahasiswa *dataLama) {
  char namaFileSementara[255];

  if (strcmp(filename, "") == 0 && jumlah == 0) {
    printf("Tidak ada data yang akan disave!\nBelum ada Database yang "
           "terpilih!\n");
    return;
  }

  if (strcmp(filename, "") == 0 && jumlah > 0) {
    printf("Belum ada database atau file yang dipilih\n");
    printf("Ketik nama file untuk di save: (ketik -1 untuk batal) ");
    scanf(" %[^\n]s", namaFileSementara);

    if (strcmp(namaFileSementara, "-1") == 0) {
      return;
    } else {
      strcpy(filename, namaFileSementara);
    }
  }

  FILE *pf;
  pf = fopen(filename, "w");

  if (pf == NULL) {
    printf("File tidak dapat dibuat maupun dibuka\n");
    return;
  }

  if (jumlah == 0 && *jmlAwal == jumlah) {
    printf("Data kosong\n");
    return;
  }

  if (jumlah == 0 && *jmlAwal > jumlah) {
    fclose(pf);
    return;
  }

  for (int i = 0; i < jumlah; i++) {
    fprintf(pf, "%s;%s;%s;%d;%f;%f;%f;%f;%f;%f;%f;%f;%f\n", mhs[i].nrp,
            mhs[i].nama, mhs[i].jurusan, mhs[i].semester, mhs[i].ipk,
            mhs[i].ipsSemester[0].ips, mhs[i].ipsSemester[1].ips,
            mhs[i].ipsSemester[2].ips, mhs[i].ipsSemester[3].ips,
            mhs[i].ipsSemester[4].ips, mhs[i].ipsSemester[5].ips,
            mhs[i].ipsSemester[6].ips, mhs[i].ipsSemester[7].ips);

    copySingleDataToAnotherStruct(&mhs[i], &dataLama[i]);
  }

  printf("Data telah tersimpan di file\n");

  *jmlAwal = jumlah;

  fclose(pf);
}

int readFromFile(Mahasiswa *mhs, Mahasiswa *dataLama, int jumlah, int *jmlAwal,
                 char *filename) {
  char filenameSementara[255];
  printf("Inputkan nama file: ");
  scanf(" %s", filenameSementara);

  FILE *pf;
  pf = fopen(filenameSementara, "r");

  if (pf == NULL) {
    printf("Gagal membuka file\n");
    return 0;
  }

  strcpy(filename, filenameSementara);

  if (strcmp(mhs[0].nrp, "") != 0) {
    printf("Ini akan menimpa data yang ada, (y/n): ");
    char ch;
    scanf(" %c", &ch);

    if (ch == 'n') {
      printf("Tidak jadi membuka file.\n");
      return jumlah - 1;
    }
  }

  fseek(pf, 0, SEEK_END);
  int sz =
      ftell(pf); // to know file size // other option is to use stat function
  rewind(pf);

  int i = 0;
  while (!feof(pf) && sz != 0) {
    fscanf(pf, " %[^;];%[^;];%[^;];%d;%f;%f;%f;%f;%f;%f;%f;%f;%f\n", mhs[i].nrp,
           mhs[i].nama, mhs[i].jurusan, &mhs[i].semester, &mhs[i].ipk,
           &mhs[i].ipsSemester[0].ips, &mhs[i].ipsSemester[1].ips,
           &mhs[i].ipsSemester[2].ips, &mhs[i].ipsSemester[3].ips,
           &mhs[i].ipsSemester[4].ips, &mhs[i].ipsSemester[5].ips,
           &mhs[i].ipsSemester[6].ips, &mhs[i].ipsSemester[7].ips);

    copySingleDataToAnotherStruct(&mhs[i], &dataLama[i]);

    i++;
  }
  fclose(pf);
  printf("Data berhasil dibaca dari file\n");

  *jmlAwal = i;
  return i - 1;
}

void createDBFile() {
  char filename[255];

  FILE *pf;

  printf("Batalkan ketik -1\n");
  printf("Input nama file/db baru: ");
  scanf(" %s", filename);
  pf = fopen(filename, "r");

  if (strcmp(filename, "-1") == 0)
    return;

  if (pf != NULL) {
    char ch;
    printf("File sudah ada, lanjutkan? (y/n) ");

    scanf(" %c", &ch);

    if ((ch == 'n' || ch == 'N') &&
        (ch != 'y' || ch != 'Y' || ch != 'n' || ch != 'N')) {
      printf("Proses dibatalkan!\n");
      return;
    }

    printf("Proses ini akan menghapus semua isi file!\n");

    if (pf == NULL) {
      fclose(pf);
    }

    pf = fopen(filename, "w");
    printf("File / Database %s berhasil dibuat\n", filename);

    fclose(pf);

    return;
  }

  pf = fopen(filename, "w");
  printf("File / Database %s berhasil dibuat\n", filename);
  fclose(pf);
  return;
}

void swapData(Mahasiswa *pa, Mahasiswa *pb) {
  Mahasiswa temp = *pa;
  *pa = *pb;
  *pb = temp;
}

ll convertNRP(char string[]) {
  ll nrp = 0;

  int j = 0;
  for (ll i = strlen(string) - 1; i >= 0; i--) {
    nrp += (string[i] - '0') * powl(10, j);
    j++;
  }

  return nrp;
}

int main() {
  char filename[255] = "";
  Mahasiswa *mhs;
  mhs = (Mahasiswa *)calloc(MAX_DATA, sizeof(Mahasiswa));

  Mahasiswa *dataLama;
  dataLama = (Mahasiswa *)calloc(MAX_DATA, sizeof(Mahasiswa));
  int ch;

  int jmlAwal = 0;
  int jml = 0;
  int jmlSementara = 0;

  do {
    clearScreen();
    printf("\nDatabase saat ini: %s", filename);

    printf("\n+-------------------------------------------+\n");
    printf("| Program Menu:                             |\n");
    printf("+-------------------------------------------+\n");
    printf("| 1.  Tambah Data Mahasiswa                 |\n");
    printf("| 2.  Tampilkan Semua Data Mahasiswa        |\n");
    printf("| 3.  Tampilkan Detail Data Satu Mahasiswa  |\n");
    printf("| 4.  Update Data Mahasiswa                 |\n");
    printf("| 5.  Hapus Data Mahasiswa                  |\n");
    printf("| 6.  Hapus Semua Data Mahasiswa            |\n");
    printf("| 7.  Urutkan Data                          |\n");
    printf("| 8.  Search Data Mahasiswa                 |\n");
    printf("| 9.  Cari IPK Tertinggi                    |\n");
    printf("| 10. Cari Rata-rata IPK                    |\n");
    printf("| 11. Tampilkan Statistik                   |\n");
    printf("| 12. Buat Database / File                  |\n");
    printf("| 13. Simpan Ke File                        |\n");
    printf("| 14. Baca dari File                        |\n");
    printf("| 15. Ganti Database / File                 |\n");
    printf("| 0. Keluar                                 |\n");
    printf("+-------------------------------------------+\n");
    printf("Pilih: ");
    scanf(" %d", &ch);

    printf("\n");

    switch (ch) {
    case 1:
      inputData(mhs, &jml, &jmlSementara);
      break;
    case 2:
      readAll(mhs, jml);
      break;
    case 3:
      printDetailData(mhs, jml);
      break;
    case 4:
      updateData(mhs, jml);
      break;
    case 5:
      jml = deleteData(mhs, jml);
      break;
    case 6:
      jml = deleteAllData(mhs, jml);
      mhs = (Mahasiswa *)calloc(100, sizeof(Mahasiswa));
      break;
    case 7:
      sortData(mhs, jml);
      break;
    case 8:
      searchData(mhs, jml);
      break;
    case 9:
      findHighestIPK(mhs, jml);
      break;
    case 10:
      findAvgIPK(mhs, jml, false);
      break;
    case 11:
      printStatisticDatas(mhs, jml);
      break;
    case 12:
      createDBFile();
      break;
    case 13:
      writeToFile(mhs, jml, filename, &jmlAwal, dataLama);
      break;
    case 14:
    case 15:
      jml = readFromFile(mhs, dataLama, jml, &jmlAwal, filename) + 1;
      jmlAwal = jml;
      break;
    case 0:
      beforeLeavesProgram(jmlAwal, jml, mhs, dataLama, filename, &jmlAwal);
      printf("Keluar dari program\n");
      break;
    default:
      printf("Input tidak valid\n");
      break;
    }

    printf("\n\nPress 'ENTER' to continue to continue.\n");
    getchar();
    while (getchar() != '\n')
      ;
  } while (ch != 0);

  if (mhs != NULL)
    free(mhs);
  free(dataLama);
}
