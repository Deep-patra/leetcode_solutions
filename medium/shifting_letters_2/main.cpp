#include <iostream>
#include <vector>
using namespace std;

// FIX: Time Limit Exceeded
string shifting_letters(string s, vector<vector<int>> &shifts) {
  string result = s;

  vector<int> temp(s.size(), 0);
  for (int i = 0; i < shifts.size(); i++) {
    int start = shifts[i][0], end = shifts[i][1], direction = shifts[i][2];

    if (direction) {
      temp[start]++;

      if (end + 1 < s.size()) {
        temp[end + 1]--;
      }
    } else {
      temp[start]--;

      if (end + 1 < s.size()) {
        temp[end + 1]++;
      }
    }
  }

  int number_of_shifts = 0;
  for (int i = 0; i < s.size(); i++) {
    char ch = result[i];

    number_of_shifts = (number_of_shifts + temp[i]) % 26;

    if (number_of_shifts < 0)
      number_of_shifts += 26;

    result[i] = 'a' + (ch - 'a' + number_of_shifts) % 26;
  }

  return result;
}

int main() {
  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    string s;
    cin >> s;

    int len;
    cin >> len;

    vector<vector<int>> shifts(len, vector<int>(3, 0));
    for (int i = 0; i < len; i++)
      cin >> shifts[i][0] >> shifts[i][1] >> shifts[i][2];

    string result = shifting_letters(s, shifts);

    cout << result << '\n';
  }

  return 0;
}
