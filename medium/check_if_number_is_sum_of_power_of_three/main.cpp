#include <bits/stdc++.h>
using namespace std;

static vector<int> pow_3;
static bool is_initialized = 0;

void initialize_values() {
  is_initialized = 1;

  int curr = 1;

  pow_3.push_back(curr);

  while (curr < 1000000) {
    curr *= 3;
    pow_3.push_back(curr);
  }
}

int get_pow_3(int n, int l, int r) {
  int mid, pos;

  while (l <= r) {
    mid = l + (r - l) / 2;

    if (pow_3[mid] == n)
      return mid;

    else if (pow_3[mid] < n) {
      pos = mid;
      l = mid + 1;
    }

    else
      r = mid - 1;
  }

  return pos;
}

bool check_power_of_threes(int n) {

  if (!is_initialized)
    initialize_values();

  int max_pos = pow_3.size();
  while (n > 0) {
    max_pos = get_pow_3(n, 0, max_pos - 1);

    n -= pow_3[max_pos];

    if (max_pos == 0 && n != 0)
      break;
  }

  if (n == 0)
    return true;

  return false;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    bool result = check_power_of_threes(n);
    cout << result << '\n';
  }

  return 0;
}
