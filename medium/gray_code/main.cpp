#include <bits/stdc++.h>  
using namespace std;

vector<int> gray_code(int n) {
   
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<int> res = gray_code(n);

    for (int val : res)
      cout << val " ";
    cout << '\n';
  }

  return 0;
}
