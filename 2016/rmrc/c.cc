#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

bool greaterf (double a, double b) {
  return a > b;
}

int main() {
  ios_base::sync_with_stdio(0);

  int n;
  while (cin >> n && !cin.eof()) {
    double likely[505];
    string bs;
    for (int i = 0; i < n; i++)
      cin >> bs >> likely[i];

    sort(likely, likely + n, greaterf);

    double total = 0;
    for (int i = 0; i < n; i++) {
      //cout << "what " << likely[i] << " " << i+1 << " - " << likely[i]*(i+1) << endl;
      total += likely[i]*(i+1);
    }

    cout << fixed;
    cout << setprecision(4);
    cout << total << endl;
  }
}
