#include <bits/stdc++.h>
using namespace std;

// INFO: Use Depth First Search Approach
vector<int> lexical_order(int n) {}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> res = lexical_order(n);
    for (int val : res)
      cout << val << ' ';
  }

  return 0;
}
