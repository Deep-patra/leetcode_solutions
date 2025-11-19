#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
static bool initialized = 0;

void dfs(int len, int max, vector<int> &freq, string &num) {

  if (num.length() == len) {
    nums.push_back(stoi(num));
    return;
  }

  for (int i = 0; i <= max; i++) {
    if (freq[i + 1] > 0) {
      num.push_back('0' + i + 1);

      freq[i + 1]--;
      dfs(len, max, freq, num);

      freq[i + 1]++;
      num.pop_back();
    }
  }
}

void generate_permutation(int mask) {
  vector<int> freq(9, 0);

  int len = 0, max = 0;
  for (int i = 0; i <= 7; i++) {
    if (mask & (1 << i)) {
      len += (i + 1);
      max = (i + 1);

      freq[i + 1] = i + 1;
    }
  }

  if (len > 7)
    return;

  string num;
  dfs(len, max, freq, num);
}

int next_beautiful_number(int n) {

  if (!initialized) {

    for (int i = 1; i < (1 << 7); i++) {
      generate_permutation(i);
    }

    sort(nums.begin(), nums.end());

    for (int val : nums)
      cout << val << ", ";
    cout << endl;

    cout << "size => " << nums.size() << endl;

    initialized = 1;
  }

  auto res = upper_bound(nums.begin(), nums.end(), n);

  return *res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    int res = next_beautiful_number(n);
    cout << res << endl;
  }

  return 0;
}
