#include <bits/stdc++.h>  
using namespace std;

int number_of_beams(vector<string> &bank) {
  int n = bank.size();

  auto get_count = [&](int i) -> int {
    int cnt = 0;

    for (char c : bank[i])
      if (c == '1') cnt ++;

    return cnt;
  };


  int prev = get_count(0), res = 0;

  for (int i = 1; i < n; i ++) {
    int curr = get_count(i);

    if (curr != 0) {
      res += (prev * curr);
      prev = curr;
    }

  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;
    i

    vector<string> bank(n);
    for (int i = 0; i < n; i ++)
      cin >> bank[i];

    int res = number_of_beams(bank);
    cout << res << endl;
  }

  return 0;
}
