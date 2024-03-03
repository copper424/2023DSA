#include <iostream>
#include <stdio.h>

int main() {
  int t, n, array[1001];
  for (int i = 0; i < 1001; i++) {
    array[i] = 0;
  }
  while (scanf("%d", &t) != EOF) {
    for (int i = 0; i < t; i++) {
      scanf("%d", &n);
      for (int j = 0; j < n; j++) {
        scanf("%d", &array[j]);
      }
      for (int k = 0; k < n-1; k++) {
        int min_pos = k, first_pos = k;
        for (int l = k + 1; l < n; l++) {
          if (array[min_pos] > array[l]) {
            min_pos = l;
          }
        }
        int temp = array[min_pos];
        array[min_pos] = array[first_pos];
        array[first_pos] = temp;
        int flag = 0;
        for (int m = 0; m < n; m++) {
          if (flag == 0) {
            flag = 1;
          } else {
            printf(" ");
          }
          printf("%d", array[m]);
        }
        printf("\n");
      }
    }
  }
  return 0;
}