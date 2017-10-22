#include <bits/stdc++.h>

using namespace std;

int main() {
  char word[105];

  while (scanf (" %s", word) != EOF) {
    int l = strlen(word);
    bool solved = false;
    for (int k = 1; k < l; k++) {
      if (l % k == 0) {
        char rotating[105];

        for (int kk = 0; kk < k; kk++)
          rotating[kk] = word[kk];
        rotating[k] = '\0';

        bool working = true;
        for (int i = 0; i*k < l; i++) {
          //printf("current rot at i %d is %s\n", i, rotating);
          if (strncmp(rotating, word + i*k, k) != 0) {
            //printf("problem for k %d at i %d\n", k, i);
            working = false;
            break;
          }

          char last = rotating[k-1];
          for (int j = 0; j < k; j++) {
            char newL = rotating[j];
            rotating[j] = last;
            last = newL;
          }
        }

        if (working) {
          printf("%d\n", k);
          solved = true;
          break;
        }
      }
    }

    if (!solved)
      printf("%d\n", l);
  }
  return 0;
}
