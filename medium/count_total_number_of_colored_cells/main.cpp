#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

static ll result[100001];
static bool is_initialized = 0;

ll colored_cells(int n) {
  if (!is_initialized) {
    is_initialized = 1;
    
    result[0] = 0;
    result[1] = 1;

    for (int i = 2; i <= 100000; i++) 
       result[i] = result[i - 1] + (4 * (i - 1));
  }

  return result[n];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    ll res = colored_cells(n);
    cout << res << '\n';
  }

  return 0;
}
