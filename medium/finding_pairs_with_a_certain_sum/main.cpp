#include <bits/stdc++.h>
using namespace std;

class FindSumPairs {

  vector<int> nums1, nums2;
  unordered_map<int, int> freq;

public:
  FindSumPairs(vector<int> &nums1, vector<int> &nums2) {
    this->nums1 = nums1;
    this->nums2 = nums2;

    for (int val : nums2)
      this->freq[val]++;
  }

  void add(int index, int val) {
    // update the frequencies
    freq[nums2[index]]--;

    if (freq[nums2[index]] == 0)
      freq.erase(nums2[index]);

    nums2[index] += val;
    freq[nums2[index]]++;
  }

  int count(int tot) {

    int res = 0;

    for (int val : nums1) {
      int diff = tot - val;

      if (diff < 0)
        continue;

      if (freq.find(diff) != freq.end())
        res += freq[diff];
    }

    return res;
  }
};

int main() {
  int n;
  vector<string> operations(n);

  for (int i = 0; i < n; i++)
    cin >> operations[i];

  vector<vector<int>> arrs(n, vector<int>(0));
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;

    for (int j = 0; j < l; j++) {
      int d;
      cin >> d;

      arrs[i].push_back(d);
    }
  }

  FindSumPairs f(arrs[0], arrs[1]);

  for (int i = 2; i < n; i++) {

    if (operations[i] == "add")
      f.add(arrs[i][0], arrs[i][1]);

    else if (operations[i] == "count") {
      int res = f.count(arrs[i][0]);
      cout << res << '\n';
    }
  }

  return 0;
}
