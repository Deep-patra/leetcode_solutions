#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll smallest_number(ll num) {
  int freq[10];
  memset(freq, 0, sizeof(freq));

  ll temp = num < 0 ? num * -1 : num;
  while (temp > 0) {
    freq[temp % 10]++;
    temp /= 10;
  }

  string new_num;

  if (num < 0) {

    for (int i = 9; i >= 0; i--) {

      int j = freq[i];
      while (j > 0) {
        new_num.push_back('0' + i);
        j--;
      }
    }

    return -1 * stol(new_num);
  }

  // if the frequency of digit zero is not none,
  // then push a single second smallest number in the new num
  if (freq[0] > 0) {
    for (int i = 1; i < 10; i++) {
      if (freq[i] > 0) {
        new_num.push_back('0' + i);
        freq[i]--;
        break;
      }
    }
  }

  for (int i = 0; i < 10; i++) {
    int j = freq[i];
    while (j > 0) {
      new_num.push_back('0' + i);
      j--;
    }
  }

  return stol(new_num);
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    ll num;
    cin >> num;

    ll res = smallest_number(num);
    cout << res << '\n';
  }

  return 0;
}
