#include <bits/stdc++.h>
using namespace std;

int get_sum(int n) {
  int sum = 0;

  while (n > 0) {
    sum += (n % 10);
    n /= 10;
  }

  return sum;
}

int count_largest_group(int n) {

  vector<int> group_sizes(37, 0);

  int max_size = 1;
  for (int i = 1; i <= n; i++) {
    int sum = get_sum(i);
    group_sizes[sum]++;

    max_size = max(max_size, group_sizes[sum]);
  }

  int groups = 0;
  for (int i = 1; i <= 36; i++)
    if (group_sizes[i] == max_size)
      groups++;

  return groups;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    int result = count_largest_group(n);
    cout << result << '\n';
  }

  return 0;
}
