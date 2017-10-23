#include <stdio.h>
#include <utility>
#include <queue>

#define MAXSIZE 60

using namespace std;

typedef bool (*voidfunc)(int, int, int, int, int[][MAXSIZE]);

int w, h;
char city[MAXSIZE][MAXSIZE]; // City map.
int distk[MAXSIZE][MAXSIZE]; // Distances from K to all points.
int diste[MAXSIZE][MAXSIZE]; // Distances from Es to all points.
int distt[MAXSIZE][MAXSIZE]; // Marcs of visited places from T.
pair<int, int> k; // K start.
pair<int, int> t; // T start.
queue<pair <int, int> > e; // All E exits.
bool reachedexit;

void bfs(pair<int, int> initV, int dist[][MAXSIZE], voidfunc verify) {
  queue< pair<int, int> > bfsq;
  pair<int, int> xy[] = {make_pair(-1, 0), 
                         make_pair(1, 0), 
                         make_pair(0, -1), 
                         make_pair(0, 1)};

  bfsq.push(initV);
  dist[initV.first][initV.second] = 0;

  while (!bfsq.empty()) {
    pair<int, int> curr = bfsq.front();
    bfsq.pop();

    for (int i = 0; i < 4; i++) {
      int nextX = curr.first + xy[i].first;
      int nextY = curr.second + xy[i].second;

      if (verify(curr.first, curr.second, nextX, nextY, dist)) {
        dist[nextX][nextY] = dist[curr.first][curr.second] + 1;
        bfsq.push(make_pair(nextX, nextY));
      }
    }
  }
}

bool simpleVerify(int currX, int currY, int nextX, int nextY, int dist[][MAXSIZE]) {
  return city[nextX][nextY] != 'X' && dist[nextX][nextY] == -1;
}

bool verifyT(int currX, int currY, int nextX, int nextY, int dist[][MAXSIZE]) {
  if (city[nextX][nextY] != 'X' && dist[nextX][nextY] == -1 &&
      2*(distt[currX][currY] + 1) + diste[nextX][nextY] <
      2*distk[nextX][nextY]) {
    if (city[nextX][nextY] == 'E')
      reachedexit = true;
    return true;
  }
  return false;
}

int main() {
  while (scanf(" %d %d", &w, &h) != EOF && w >= 3 && h >= 3) {
    reachedexit = false;
    // Read the input
    while (!e.empty()) e.pop();
    for (int i = 1; i <= h; i++) {
      scanf("%*c"); // Scan the newline.
      for (int j = 1; j <= w; j++) {
          scanf("%c", &city[i][j]);

          if (city[i][j] == 'K')
            k = make_pair(i, j);
          if (city[i][j] == 'T')
            t = make_pair(i, j);
          if (city[i][j] == 'E')
            e.push(make_pair(i, j));

          // "Unmark"
          distk[i][j] = -1;
      }
    }

    // Get the distances from K.
    bfs(k, distk, simpleVerify);

    // Try for all exits.
    while (!e.empty()) {
      for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
          diste[i][j] = -1, distt[i][j] = -1;

      bfs(e.front(), diste, simpleVerify);
      e.pop();

      // Try to find a path from T - test if very first spot is safe.
      if (diste[t.first][t.second] < 2*distk[t.first][t.second])
        bfs(t, distt, verifyT);
    }

    if (reachedexit == true)
      printf("KEEP IT\n");
    else
      printf("DROP IT\n");
  }

  return 0;
}