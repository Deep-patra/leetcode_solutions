#include <bits/stdc++.h>
using namespace std;

int next_greater_element(int n) {

  vector<int> digits;

  int temp = n;
  while (temp > 0) {
    digits.push_back(temp % 10);
    temp /= 10;
  }

  // calculate next greater element
  stack<int> s;

  int i = 0;
  for (; i < digits.size(); i++) {

    if (!s.empty() && digits[i] < digits[s.top()]) {

      int j = s.top();
      while (!s.empty() && digits[i] < digits[s.top()]) {
        j = s.top();
        s.pop();
      }

      swap(digits[j], digits[i]);

      break;
    }

    s.push(i);
  }

  if (i >= digits.size())
    return -1;

  sort(digits.begin(), digits.begin() + i, greater<int>());

  long long res = 0;

  for (int i = 0, exp = 1; i < digits.size(); i++) {
    res += (exp * digits[i]);
    exp *= 10;
  }

  return res > INT_MAX ? -1 : (int)res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    int res = next_greater_element(n);
    cout << res << '\n';
  }

  return 0;
}
