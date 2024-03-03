#include <iostream>
#include <stdio.h>

int main() {
  int s[10001], n[10001];
  int t = 0;
  while (scanf("%d",&t) != EOF) {
    for (int i = 0; i < t; i++) {
      int num = 0, time = 0;
      scanf ("%d", &num);
      scanf ("%d", &s[0]);
      for (int i = 0; i < num-1; i++) {
        scanf ("%d", &n[i]);
      }
      int s_num = 1;
      for (int i = 0; i < num-1; i++) {
        if (s[s_num - 1] < n[i]) {
          s[s_num++] = n[i];
        } else {
          int j = s_num;
          while (j >= 1 && s[j - 1] > n[i]) {
            s[j] = s[j - 1]; 
            j--;
          }
          s[j] = n[i];
          s_num++;
          time += 5;
        }
      }
      printf("%d\n",time);
    }
  }
  return 0;
}