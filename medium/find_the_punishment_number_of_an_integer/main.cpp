#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int get_number(vector<int> &digits, int start, int end) {
  int diff = pow(10, end - start);

  int num = 0;
  while (start <= end) {
    num += digits[start] * diff;

    diff /= 10;
    start++;
  }

  return num;
}

// max the n will be 6 length
bool is_valid(vector<int> &digits, int target, int sum, int index = 0) {
  if (sum == target && index == digits.size())
    return true;

  if (index > digits.size() || sum > target)
    return false;

  for (int i = index; i < digits.size(); i++) {
    int num = get_number(digits, index, i);

    if (is_valid(digits, target, sum + num, i + 1))
      return true;
  }

  return false;
}

int punishment_number(int n) {
  int result = 1;

  if (n == 1)
    return 1;

  for (int i = 2; i <= n; i++) {
    int sq = i * i;

    vector<int> digits;

    int temp = sq;
    while (temp != 0) {
      digits.push_back(temp % 10);
      temp /= 10;
    }

    reverse(digits.begin(), digits.end());

    if (is_valid(digits, i, 0)) {
      // cout << "index => " << i << " and square => " << sq << endl;
      result += sq;
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

    int result = punishment_number(n);
    cout << result << '\n';
  }

  return 0;
}
