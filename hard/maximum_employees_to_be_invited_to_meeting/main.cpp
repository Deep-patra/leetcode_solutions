#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maximum_invitations(vector<int> &favourite) {
  
  if (favourite.size() <= 3) return 3;

  vector<int> visited(favourite.size(), -1);
  
  stack<int> s;

  int max_emp = 0;
  for (int i = 0; i < favourite.size(); i++) {
    if (visited[i] != -1) continue;

    s.push(i);
    while (!s.empty()) {
      
    }
  }

  return max_emp;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int m;
    cin >> m;

    vector<int> favourite(m, 0);
    for (int i = 0; i < m; i++)
      cin >> favourite[i];

    int result = maximum_invitations(favourite);
    cout << result << '\n';
  }

  return 0;
}
