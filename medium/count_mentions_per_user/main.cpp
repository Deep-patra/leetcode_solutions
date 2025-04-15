#include <iostream>
#include <vector>
#include <set>
using namespace std;


// TODO: Implement the algorithm
vector<int> count_mentions(int numberOfUsers, vector<vector<string>> &events) {
  set<string> offline;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int users, m;
    cin >> users >> m;

    vector<vector<string>> events(m);
    for (int i = 0; i < m; i++) {
      int n; 
      cin >> n;

      vector<string> event(n, "");
      for (int j = 0; j < n; j++)
        cin >> event[i];

      events[i] = event;
    }

    vector<int> result = count_mentions(users, events);
    
    for (auto val: result)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}
