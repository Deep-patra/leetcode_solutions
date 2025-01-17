#include <iostream>
#include <vector>
using namespace std;

// TODO: Passed with very slow runtime, optimize it
int minimum_length(string s) {
  int len = s.length();

  if (len <= 2)
    return len;

  // array to keep the track of characters
  vector<bool> temp(len, 0);

  for (int i = 1; i < len - 1; i++) {

    if (temp[i])
      continue;

    char ch = s[i];

    int l = i - 1, r = i + 1;
    int left_found = -1, right_found = -1;

    while (left_found == -1 && l >= 0) {
      if (s[l] == ch && !temp[l])
        left_found = l;

      l--;
    }

    while (right_found == -1 && r < len) {
      if (s[r] == ch && !temp[r])
        right_found = r;

      r++;
    }

    if (right_found != -1 && left_found != -1) {
      temp[right_found] = 1;
      temp[left_found] = 1;
    }
  }

  int result = 0;

  for (int i = 0; i < len; i++)
    if (!temp[i])
      result++;

  return result;
}

// Optimized approach
int minimum_length_optimize(string s) {
  int len = s.length();

  if (len <= 2)
    return len;

  int characters[26];
  memset(characters, 0, sizeof(characters));

  for (int i = 0; i < len; i++) {
    int index = s[i] - 'a';

    characters[index] = (characters[index] + 1) & 1 ? 1 : 2;
  }

  int result = 0;

  for (int i = 0; i < len; i++)
    result += characters[i];

  return result;
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    string s;
    cin >> s;

    int result = minimum_length_optimize(s);
    cout << result << '\n';
  }

  return 0;
}
