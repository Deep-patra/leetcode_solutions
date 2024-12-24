#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> plus_one(vector<int> &digits) {
  vector<int> result;
  bool carry = 0;

  int i = digits.size() - 1;

  if (digits[i] == 9) {
    result.push_back(0);
    carry = 1;
  } else
    result.push_back(digits[i] + 1);

  i--;
  while (i >= 0) {
    if (digits[i] == 9 && carry)
      result.push_back(0);
    else if (digits[i] != 9 && carry) {
      result.push_back(digits[i] + 1);
      carry = 0;
    } else
      result.push_back(digits[i]);
    i--;
  }

  if (carry)
    result.push_back(1);

  reverse(result.begin(), result.end());

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len;
    cin >> len;

    vector<int> digits(len, 0);
    for (int i = 0; i < len; i++)
      cin >> digits[i];

    vector<int> result = plus_one(digits);

    for (auto val : result)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}
