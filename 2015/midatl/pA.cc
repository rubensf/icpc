#include <stdio.h>

#define MAXN 1000000

int main() {
  int a, b, c, d;

  while (true) {
    scanf (" %d %d %d %d", &a, &b, &c, &d);
    if (a == -1 && b == -1 && c == -1 && d == -1)
      break;

    // First check if arithmetic progression.
    if (a == -1 && (c - b == d - c && (c - b) * 2 == d - b) && b - (c - b) >= 1 && b - (c - b) <= MAXN) {
      printf("%d\n", b - (c - b));
    } else if (b == -1 && ((d - c) * 2 == c - a && (d - c) * 3 == d - a) && a + (d - c) >= 1 && a + (d - c) <= MAXN) {
      printf("%d\n", a + (d - c));
    } else if (c == -1 && ((b - a) * 2 == d - b && (b - a) * 3 == d - a) && b + (b - a) >= 1 && b + (b - a) <= MAXN) {
      printf("%d\n", b + (b - a));
    } else if (d == -1 && (b - a == c - b && (b - a) * 2 == c - a) && c + (c - b) >= 1 && c + (c - b) <= MAXN) {
      printf("%d\n", c + (c - b));
    } // Then check geometric progression.
    else if (a == -1 && (c/b)*b == c && (d/c)*c == d && c/b == d/c && (b/(c/b))*(c/b) == b && b/(c/b) >= 1 && b/(c/b) <= MAXN) {
      printf("%d\n", b/(c/b));
    } else if (b == -1 && (c/a)*a == c && (d/c)*c == d && c/a == (d/c)*(d/c) && (c/(d/c))*(d/c) == c && c/(d/c) >= 1 && c/(d/c) <= MAXN) {
      printf("%d\n", c/(d/c));
    } else if (c == -1 && (b/a)*a == b && (d/b)*b == d && d/b == (b/a)*(b/a) && b*(b/a) >= 1 && b*(b/a) <= MAXN) {
      printf("%d\n", b*(b/a));
    } else if (d == -1 && (c/b)*b == c && (b/a)*a == b && c/b == b/a && c*(c/b) >= 1 && c*(c/b) <= MAXN) {
      printf("%d\n", c*(c/b));
    } // Or else :)
    else {
      printf("-1\n");
    }
  }
  return 0;
}