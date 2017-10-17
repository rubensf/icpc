#include <iostream>
#include <algorithm>

using namespace std;

bool is_triangle(int a, int b, int c) {
  int bigger = max(a, max(b, c));
  int others = a + b + c - bigger;
  return bigger < others;
}

int main() {
  int l1, l2, l3, l4, l5;
  cin >> l1 >> l2 >> l3 >> l4 >> l5;

  int total = 0;
  if (is_triangle(l1, l2, l3)) total++;
  if (is_triangle(l1, l2, l4)) total++;
  if (is_triangle(l1, l2, l5)) total++;
  if (is_triangle(l1, l3, l4)) total++;
  if (is_triangle(l1, l3, l5)) total++;
  if (is_triangle(l1, l4, l5)) total++;
  if (is_triangle(l2, l3, l4)) total++;
  if (is_triangle(l2, l3, l5)) total++;
  if (is_triangle(l2, l4, l5)) total++;
  if (is_triangle(l3, l4, l5)) total++;

  cout << total << endl;
}
