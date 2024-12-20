#include <iostream>
#include <vector>
using namespace std;

// TODO: Implement this problem
vector<int> sort_jumbled(vector<int> &mappings, vector<int> &nums) {

  vector<int> sorted(nums);

  return sorted;
}

int main() {

  int test_cases = 0;
  cin >> test_cases;

  while (test_cases > 0) {
    test_cases--;

    vector<int> mappings;
    vector<int> nums;

    // Get the mappings
    for (int i = 0; i < 10; i++) {
      int mapping = 0;
      cin >> mapping;

      mappings.push_back(mapping);
    }

    int len = 0;
    cin >> len; // get the length of the array

    for (int i = 0; i < len; i++) {
      int num = 0;
      cin >> num;

      nums.push_back(num);
    }

    vector<int> result = sort_jumbled(mappings, nums);

    for (int i = 0; i < result.size(); i++)
      cout << result[i] << ' ';

    cout << "\n";
  }

  return 0;
}
