#include <bitset>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

string find_different_binary_string(vector<string> &nums) {
  unordered_set<int> s;

  for (int j = 0; j < nums.size(); j++) {
    string num = nums[j];
    int val = 0;

    reverse(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {
      if (num[i] == '1')
        val |= 1 << i;
    }

    s.insert(val);
  }

  int result = 0;
  for (int i = 0; i <= (1 << nums.size()); i++) {
    if (s.find(i) == s.end()) {
      result = i;
      break;
    }
  }

  string b_string = bitset<16>(result).to_string();
  return b_string.substr(b_string.length() - nums.size());
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<string> nums(n, "");
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    string result = find_different_binary_string(nums);
    cout << result << '\n';
  }

  return 0;
}
