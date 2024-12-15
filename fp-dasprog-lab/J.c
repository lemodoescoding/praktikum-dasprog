#include <stdio.h>

typedef struct {
  int x, y, data;
} Elem;

void swap(Elem *pa, Elem *pb) {
  Elem temp = *pa;
  *pa = *pb;
  *pb = temp;
}

int partition(Elem *arr, int lo, int hi) {
  int pivot = (arr + hi)->data;

  int i = lo - 1;

  for (int j = lo; j <= hi - 1; j++) {
    if ((arr + j)->data < pivot) {
      i++;
      swap(arr + i, arr + j);
    }
  }

  swap(arr + i + 1, arr + hi);

  return i + 1;
}

void quicksort(Elem *arr, int lo, int hi) {
  if (lo < hi) {
    int pi = partition(arr, lo, hi);

    quicksort(arr, lo, pi - 1);
    quicksort(arr, pi + 1, hi);
  }
}

int binarySearch(Elem *arr, int L, int R, int key, int *x, int *y) {
  if (R >= L) {
    int M = L + (R - L) / 2;

    if ((arr + M)->data == key) {
      *x = (arr + M)->x;
      *y = (arr + M)->y;

      return 1;
    }

    if ((arr + M)->data > key) {
      return binarySearch(arr, L, M - 1, key, x, y);
    }

    return binarySearch(arr, M + 1, R, key, x, y);
  }

  return -1;
}

int main() {
  int x, y;
  scanf("%d %d", &x, &y);

  Elem elems[x * y];

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      scanf("%d", &elems[i * x + j].data);
      (elems + i * x + j)->x = j + 1;
      (elems + i * x + j)->y = i + 1;
    }
  }

  quicksort(elems, 0, x * y - 1);

  int key;
  scanf("%d", &key);

  int foundX, foundY;
  int found = binarySearch(elems, 0, x * y - 1, key, &foundX, &foundY);

  if (found == -1) {
    printf("Element %d not found.", key);
    return 0;
  }

  printf("Element %d found at position: (%d, %d).", key, foundY, foundX);
}
