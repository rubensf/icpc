#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <iostream>

using namespace std;

struct truck {
  truck(int id_, int time_) : id(id_), time(time_) {}
  int id, time;
};

struct truck_greater {
  inline bool operator() (const truck& t1, const truck& t2) {
    if (t1.time == t2.time)
      return t1.id > t2.id;
    return t1.time > t2.time;
  }
};

struct truck_comp_id {
  inline bool operator() (const truck& t1, const truck& t2) {
    return t1.id > t2.id;
  }
};

priority_queue<truck, vector<truck>, truck_greater> *before, *after;
int times[1005][1005];
int tottime[1005];

int main() {
  ios_base::sync_with_stdio(0);

  int n, m;
  while (cin >> n >> m && !cin.eof()) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> times[i][j];

    before = new priority_queue<truck, vector<truck>, truck_greater>;
    after  = new priority_queue<truck, vector<truck>, truck_greater>;
    for (int i = 0; i < n; i++)
      tottime[i] = 0, before->push(truck(i, 0));

    for (int i = 0; i < m; i++) {
      int currtime = before->top().time;

      for (int j = 0; j < n; j++) {
        truck curr = before->top();
        before->pop();
        currtime = max(currtime, curr.time);
        int needed = times[curr.id][i];
        after->push(truck(curr.id, currtime + needed));
        currtime += needed;
      }

      swap(before, after);
    }

    priority_queue<truck, vector<truck>, truck_comp_id> end;
    while (!before->empty()) {
      end.push(before->top());
      before->pop();
    }

    delete before;
    delete after;

    while (!end.empty()) {
      cout << end.top().time;
      if (end.size() > 1)
        cout << " ";
      end.pop();
    }
    cout << endl;
  }

  return 0;
}
