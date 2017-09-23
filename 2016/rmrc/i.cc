#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

struct cup {
  string color;
  int radius;

  bool operator<(const cup& rhs) const {
    return radius < rhs.radius;
  }
};

int main() {
  int n;
  while (cin >> n && n != 0) {
    string a, b;
    cup cups[25];

    for (int i = 0; i < n; i++) {
      cin >> a >> b;

      if (a.c_str()[0] >= 'a' && a.c_str()[0] <= 'z')
        cups[i].color = a, cups[i].radius = stoi(b);
      else
        cups[i].color = b, cups[i].radius = stoi(a)/2;
    }

    sort(cups, cups + n);

    for (int i = 0; i < n; i++)
      cout << cups[i].color << endl;
  }

  return 0;
}
