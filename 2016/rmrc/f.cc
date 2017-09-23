#include <string>
#include <iostream>

using namespace std;

int c[2][100005];

int main() {
  ios_base::sync_with_stdio(0);
  int x1, x2;
  while (cin >> x1 >> x2 && !cin.eof()) {
    if (x1 < x2)
      x1 += 4;
    else
      x2 += 4;

    int l1, l2;
    cin >> l1;
    for (int i = 0; i < l1; i++) cin >> c[0][i];
    cin >> l2;
    for (int i = 0; i < l2; i++) cin >> c[1][i];

    int i, j;
    bool m1, m2;
    bool hit;

    i = j = 0;
    m1 = m2 = false;
    hit = false;

    for (int k = 0; k < 3000000; k++) {
      if (m1) x1++;
      if (m2) x2++;

      if (i < l1 && k == c[0][i])
        m1 = !m1, i++;
      if (j < l2 && k == c[1][j])
        m2 = !m2, j++;

      //cout << "at time " << k << ": 1 is " << (!m1 ? "not" : "") << " moving and got to " << x1 << endl;
      //cout << "at time " << k << ": 1 is " << (!m2 ? "not" : "") << " moving and got to " << x2 << endl;

      if (x1 == x2) {
        cout << "bumper tap at time " << k << endl;
        hit = true;
        break;
      }
    }

    if (!hit)
      cout << "safe and sound" << endl;
  }

  return 0;
}

