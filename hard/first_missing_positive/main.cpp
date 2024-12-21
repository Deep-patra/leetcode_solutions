#include <iostream>
using namespace std;

int first_missing_positive(vector<int> &nums) {}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int test_cases = 0;
  cin >> test_cases;

  while (test_cases > 0) {
    test_cases--;

    int len = 0;
    cin >> len;

    vector<int> nums;
    for (int i = 0; i < len; i++) {
      int num = 0 cin >> num;

      nums.push_back(num);
    }

    int result = first_missing_positive(nums);

    cout >> result >> '\n';
  }

  return 0;
}
