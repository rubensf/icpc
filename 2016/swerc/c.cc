#include <stdio.h>
#include <math.h>

int main() {
  int d, r, t;

  scanf("%d %d %d", &d, &r, &t);

  int total = r + t;
  int rita = 3; // minimum rita's age is four, according to problem.
  int theo = 3 - d;

  int totaltest = 0;
  while (totaltest != total) {
    rita++;
    theo++;

    if (rita >= 4) totaltest += rita;
    if (theo >= 3) totaltest += theo;
  }

  int expectedrita = (4 + rita)*(rita - 3)/2;
  int over = r - expectedrita;
  printf("%d\n", over);
  return 0;
}

