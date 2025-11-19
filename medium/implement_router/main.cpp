#include <bits/stdc++.h>
using namespace std;
class Router {

  int size;
  deque<vector<int>> dq;

  set<vector<int>> uniq;
  map<int, multiset<int>> dst_map;

public:
  Router(int memoryLimit) { size = memoryLimit; }

  bool addPacket(int source, int destination, int timestamp) {

    if (uniq.find(vector<int>({source, destination, timestamp})) != uniq.end())
      return 0;

    if (dq.size() == size) {
      vector<int> b = dq.back();
      uniq.erase(b);

      auto it = dst_map[b[1]].find(b[2]);
      dst_map[b[1]].erase(it);

      dq.pop_back();
    }

    uniq.insert(vector<int>{source, destination, timestamp});
    dst_map[destination].insert(timestamp);
    dq.push_front(vector<int>({source, destination, timestamp}));

    return 1;
  }

  vector<int> forwardPacket() {

    if (dq.size() == 0)
      return vector<int>(0);

    vector<int> p = dq.back();
    dq.pop_back();

    auto it = dst_map[p[1]].find(p[2]);
    dst_map[p[1]].erase(it);

    uniq.erase(p);

    if (dst_map[p[1]].empty())
      dst_map.erase(p[1]);

    return p;
  }

  int getCount(int destination, int startTime, int endTime) {

    if (!dst_map.count(destination))
      return 0;

    auto s = dst_map[destination].lower_bound(startTime);
    auto e = dst_map[destination].lower_bound(endTime);

    if (e == dst_map[destination].end())
      return distance(s, e);

    while ((*e) > endTime) {
      if (e == dst_map[destination].begin()) {

        if (*e > endTime)
          return 0;

        break;
      }

      e--;
    }

    return distance(s, e);
  }
};

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    Router r = NULL;

    vector<string> ops(n);
    for (int i = 0; i < n; i++)
      cin >> ops[i];

    for (string o : ops) {
      if (o == "Router") {
        int m;
        cin >> m;

        r = Router(m);
        cout << "null" << " ";
      }

      else if (o == "addPacket") {
        int source, destination, timestamp;
        cin >> source >> destination >> timestamp;

        bool res = r.addPacket(source, destination, timestamp);
        cout << (res ? "true" : "false") << " ";
      }

      else if (o == "forwardPacket") {
        vector<int> packet = r.forwardPacket();

        if (packet.size() > 0)
          cout << packet[0] << " " << packet[1] << " " << packet[2] << " ";
      }

      else if (o == "getCount") {
        int start, end, destination;
        cin >> destination >> start >> end;
        int res = r.getCount(destination, start, end);

        cout << res << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
