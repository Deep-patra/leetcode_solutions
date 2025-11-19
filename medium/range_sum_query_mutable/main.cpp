#include <bits/stdc++.h>
using namespace std;

class NumArray {
  vector<int> bit, org_nums;
  int n;

public:
  NumArray() {}

  NumArray(vector<int> &nums) {

    n = nums.size() + 1;

    bit = vector<int>(nums.size() + 1, 0);
    org_nums = vector<int>(nums.size());

    for (int i = 0; i < nums.size(); i++) {
      update(i, nums[i]);
      org_nums[i] = nums[i];
    }
  }

  void update(int index, int val) {
    int idx = index + 1;

    // subtract the previous values
    for (int i = idx; i < n; i += (i & -i))
      bit[i] -= org_nums[index];

    org_nums[index] = val;

    for (int i = idx; i < n; i += (i & -i))
      bit[i] += val;
  }

  int query(int index) {

    int sum = 0;

    for (int i = index + 1; i > 0; i -= (i & -i))
      sum += bit[i];

    return sum;
  }

  int sumRange(int left, int right) { return query(right) - query(left - 1); }
};

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    NumArray nums;

    vector<string> operations(n);
    for (int i = 0; i < n; i++)
      cin >> operations[i];

    vector<int> res;

    for (int i = 0; i < n; i++) {
      if (operations[i] == "NumArray") {

        int n;
        cin >> n;

        vector<int> values(n);
        for (int i = 0; i < n; i++)
          cin >> values[i];

        nums = NumArray(values);

        res.push_back(NULL);
      } else if (operations[i] == "sumRange") {

        int left, right;
        cin >> left >> right;

        int sum = nums.sumRange(left, right);

        res.push_back(sum);
      } else {

        int i, val;
        cin >> i >> val;

        nums.update(i, val);

        res.push_back(NULL);
      }
    }

    for (int i = 0; i < res.size(); i++)
      cout << (res[i] == NULL ? "null" : to_string(res[i])) << " ";

    cout << endl;
  }

  return 0;
}
