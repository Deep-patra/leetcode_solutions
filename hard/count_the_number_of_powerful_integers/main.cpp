#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[16][2][2], l, num, suff;
string num_str, suffix;

ll count_numbers(int pos, bool started, bool is_under, ll curr = 0) {

  if ((num_str.size() - pos) == suffix.size()) {
    if (is_under || !started)
      return 1;

    ll target = (curr * pow(10, suffix.size())) + suff;

    if (target > num) {
      return 0;
    }

    return 1;
  }

  ll result = 0;

  if (dp[pos][is_under][started] != -1)
    return dp[pos][is_under][started];

  for (int i = 0; i <= l; i++) {

    int digit_diff = num_str[pos] - '0';

    if (!is_under && i > digit_diff)
      break;

    bool under = is_under;

    if (i < digit_diff)
      under = 1;

    started = started || i > 0;

    result += count_numbers(pos + 1, started, under, curr * 10 + i);
  }

  return dp[pos][is_under][started] = result;
}

ll number_of_powerful_int(ll start, ll finish, int limit, string s) {

  memset(dp, -1, sizeof(dp));
  l = limit;

  suffix = s;
  suff = stol(suffix);

  // find the number, till start number
  num_str = to_string(start - 1);
  num = stol(num_str);

  ll result1 = start - 1 < suff ? 0 : count_numbers(0, 0, 0);

  cout << "result 1 => " << result1 << endl;

  memset(dp, -1, sizeof(dp));

  // find the numbers, till the finish number
  num_str = to_string(finish);
  num = stol(num_str);

  ll result2 = finish < suff ? 0 : count_numbers(0, 0, 0);

  cout << "result 2 => " << result2 << endl;

  return result2 - result1;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    ll start, finish;
    cin >> start >> finish;

    int limit;
    cin >> limit;

    string s;
    cin >> s;

    ll result = number_of_powerful_int(start, finish, limit, s);
    cout << result << '\n';
  }

  return 0;
}
