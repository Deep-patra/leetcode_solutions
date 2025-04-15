#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int find_content_children(vector<int> &g, vector<int> &s) {
  priority_queue<int, vector<int>, greater<int>> greed(g.begin(), g.end());
  priority_queue<int, vector<int>, greater<int>> cookies(s.begin(), s.end());

  int result = 0;

  while (!cookies.empty() && !greed.empty()) {

    int c = greed.top();
    int cookie = cookies.top();

    if (cookie >= c) {
      result++;
      greed.pop();
    }

    cookies.pop();
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m;
    cin >> n;

    vector<int> g(n, 0);
    for (int i = 0; i < n; i++)
      cin >> g[i];

    cin >> m;

    vector<int> s(m, 0);
    for (int i = 0; i < m; i++)
      cin >> s[i];

    int result = find_content_children(g, s);
    cout << result << '\n';
  }

  return 0;
}
