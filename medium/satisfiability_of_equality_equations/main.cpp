#include <bits/stdc++.h>  
using namespace std;


// INFO: Can be easily solved with DSU
bool equations_possible(vector<string>& equations) {

}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<string> equations(n);
    for (int i = 0; i < n; i ++)
      cin >> equations[i];

    bool res = equations_possible(equations);
    cout << res << '\n';
  }

  return 0;
}
