#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool find_smallest_number(string pattern, vector<int> &result, int mask,
                          int index = -1) {

  if (index == pattern.length())
    return true;

  if (index == -1) {
    for (int i = 1; i <= 9; i++) {
      if (mask & (1 << i))
        continue;

      result[0] = i;

      if (find_smallest_number(pattern, result, mask | (1 << i), index + 1))
        return true;
    }
  }

  else if (pattern[index] == 'I' && result[index] + 1 <= 9) {
    for (int i = result[index] + 1; i <= 9; i++) {
      if (mask & (1 << i))
        continue;

      result[index + 1] = i;

      if (find_smallest_number(pattern, result, mask | (1 << i), index + 1))
        return true;
    }
  }

  else if (pattern[index] == 'D' && result[index] - 1 > 0) {
    for (int i = result[index] - 1; i > 0; i--) {
      if (mask & (1 << i))
        continue;

      result[index + 1] = i;

      if (find_smallest_number(pattern, result, mask | (1 << i), index + 1))
        return true;
    }
  }

  return false;
}

string smallest_number(string pattern) {
  vector<int> result(pattern.length() + 1, 0);

  find_smallest_number(pattern, result, 0);

  string sm = "";

  for (int val : result)
    sm.push_back(to_string(val)[0]);

  return sm;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string pattern;
    cin >> pattern;

    string result = smallest_number(pattern);
    cout << result << '\n';
  }

  return 0;
}
