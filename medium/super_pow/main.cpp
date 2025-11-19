#include <bits/stdc++.h>  
using namespace std;


// TODO: Complete the Implementation
int super_pow(int a, vector<int> &b) {

}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int a, n;
    cin >> n >> a;

    vector<int> b(n)
    for (int i = 0; i < n; i ++)
      cin >> b[i];

    int p = super_pow(a, b);
    cout << p << endl;
  }

  return 0;
}
