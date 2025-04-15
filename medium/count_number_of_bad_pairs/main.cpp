#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

// INFO: Solved but a bit slow
ll count_pairs(vector<int> &nums) {
  vector<int> preprocess(nums.size(), 0);

  for (int i = 0; i < nums.size(); i++)
    preprocess[i] = nums[i] - i;

  sort(preprocess.begin(), preprocess.end());

  // for (auto val : preprocess)
  //   cout << val << " ";
  // cout << endl;

  long long result = 0;
  for (int i = 0; i < preprocess.size(); i++) {
    int pos = upper_bound(preprocess.begin(), preprocess.end(), preprocess[i]) -
              preprocess.begin();

    // cout << "positin => " << pos << endl;

    result += preprocess.size() - pos;
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    ll result = count_pairs(nums);
    cout << result << '\n';
  }

  return 0;
}
