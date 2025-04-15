#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums) {
  vector<vector<int>> result;

  result.push_back(vector<int>(0));

  for (int i = 0; i < nums.size(); i++) {

    int size = result.size();
    for (int j = 0; j < size; j++) {

      vector<int> temp = result[j];
      temp.push_back(nums[i]);

      result.push_back(temp);
    }
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

    vector<vector<int>> result = subsets(nums);

    cout << '[';

    for (auto list : result) {
      cout << '[';

      for (int val : list)
        cout << val << " ";

      cout << "] ,";
    }

    cout << ']' << endl;
  }

  return 0;
}
