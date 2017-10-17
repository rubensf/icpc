#include <bits/stdc++.h>

using namespace std;

struct fuck {
  int v, p;
};

fuck fucks[100005];

int main() {
  int n, m;
  cin >> n >> m;

  int mainPos = 1;

  for (int i = 0; i < m; i++) {
    int x, pp;
    cin >> x >> pp;

    if (x == 1) {

    } else if (x != 1) {
      if (fucks[x].v <  fucks[1].v &&
          fucks[x].v == fucks[1].v &&
          fucks[x].p + pp < fucks[1].p) {
      }
    }

    fucks[x].v++;
    fucks[x].p+=pp;

  }

  return 0;
}
