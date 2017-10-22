#include <bits/stdc++.h>

#define ff(i, n) for (int i = 0; i < n; i++)
#define ff1(i, n) for (int i = 1; i <= n; i++)

using namespace std;

char islands[55][55];
bool marked[55][55];

int x[] = {1, 0, -1, 0};
int y[] = {0, 1, 0, -1};

int dfs(int x0, int y0) {
  marked[x0][y0] = 1;

  int finalRet = 0;
  if (islands[x0][y0] == 'L')
    finalRet = 1;

  ff(i, 4)
    if (!marked[x0+x[i]][y0+y[i]] &&
        islands[x0+x[i]][y0+y[i]] != 'W')
      finalRet |= dfs(x0+x[i], y0+y[i]);

  return finalRet;
}

int main() {
  int n, m;
  ios_base::sync_with_stdio(0);

  while (cin >> n >> m && !cin.eof()) {
    int total = 0;

    for (int i = 0; i <= n+1; i++)
      islands[i][0] = islands[i][m+1] = 'W';
    for (int i = 0; i <= m+1; i++)
      islands[0][i] = islands[n+1][i] = 'W';

    ff1(i, n)
      ff1(j, m)
        marked[i][j] = 0, cin >> islands[i][j];

    ff1(i, n)
      ff1(j, m)
        if (islands[i][j] == 'C' && !marked[i][j]) {
          int v = dfs(i, j);
          if (v == 1) {
            //cout << "w00t found group at " << i << " - " << j << endl;
            total++;
          }
        }

    ff1(i, n)
      ff1(j, m)
        if (islands[i][j] == 'L' && !marked[i][j])
          total += dfs(i, j);

    cout << total << endl;
  }

  return 0;
}
