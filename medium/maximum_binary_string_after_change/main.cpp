#include <bits/stdc++.h>
using namespace std;

// INFO: Using Greedy Approach
string maximum_binary_string(string binary) {
  int n = binary.length();

  vector<int> zpos(n + 1, -1);

  for (int i = n - 1; i >= 0; i --) 
    

  for (int i = 0; i < n; i ++) {

  }

  return binary;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string binary;
    cin >> binary;

    string res = maximum_binary_string(binary);
    cout << res << endl;
  }

  return 0;
}
