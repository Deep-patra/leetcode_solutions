#include <bits/stdc++.h>
using namespace std;

int dp[9][1 << 10];

int count_number_with_unqiue_digits(int n) {
  if (n <= 1)
    return n == 0 ? 1 : 9;

  memset(dp, 0, sizeof(dp));

  int res = 1;

  for (int i = 2; i <= n; i++)
    res += count_unique_digits(i);

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    int result = count_number_with_unique_digits(n);
    cout << result << '\n';
  }

  return 0;
}
