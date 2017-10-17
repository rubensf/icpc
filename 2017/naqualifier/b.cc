#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>

#define mp make_pair
#define pb push_back

#define ll long long int

#define MAXN 50005
#define MAXM 150005
#define MAXF 1005
#define INF 9999999999L

using namespace std;

int n, m, f;
int s, t;

// 1: id, 2: cost
vector<pair<int, ll>> adj[MAXN];
vector<pair<int, int>> flights;

// Gets cleared every time
priority_queue<pair<ll, int>> distlist;
ll dists[MAXN];

ll dijkstra() {
  // Remember to invert sign here of the distance.
  for (int i = 0; i < n; i++)
    dists[i] = -1;
  distlist.push(mp(0, s));

  while (!distlist.empty()) {
    int at = -1;

    while (!distlist.empty() && dists[distlist.top().second] != -1)
      distlist.pop();

    if (distlist.empty()) break;

    at = distlist.top().second;
    dists[at] = distlist.top().first * -1;
    distlist.pop();

    for (unsigned long i = 0; i < adj[at].size(); i++) {
      int att = adj[at][i].first;
      ll d = adj[at][i].second;

      if (dists[att] == -1)
        distlist.push(mp((dists[at] + d) * -1, att));
    }
  }

  if (dists[t] == -1)
    return INF;
  return dists[t];
}

int main() {
  cin >> n >> m >> f >> s >> t;

  for (int i = 0; i < m; i++) {
    int a, b;
    ll v;
    cin >> a >> b >> v;
    adj[a].pb(mp(b, v));
    adj[b].pb(mp(a, v));
  }

  for (int i = 0; i < f; i++) {
    int a, b;
    cin >> a >> b;
    flights.pb(mp(a, b));
  }

  // Also try with no flights.
  ll bestDist = dijkstra();
  for (int i = 0; i < f; i++) {
    int p1, p2;
    p1 = flights[i].first;
    p2 = flights[i].second;

    adj[p1].pb(mp(p2, 0));

    bestDist = min(bestDist, dijkstra());

    adj[p1].erase(adj[p1].end() - 1);
  }

  cout << bestDist << endl;
  return 0;
}
