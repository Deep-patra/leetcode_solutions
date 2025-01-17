#include <iostream>
#include <vector>
using namespace std;

// Greedy approach
bool can_construct(string s, int k) {
  if (k == s.length())
    return true;

  int characters_cnt[26];
  memset(characters_cnt, 0, sizeof(characters_cnt));

  for (int i = 0; i < s.size(); i++)
    characters_cnt[s[i] - 'a']++;

  // count the number of odd counts
  // if they are greater than k
  // then palindrome is not possible
  int odd_cnts = 0;
  for (int i = 0; i < 26; i++)
    if (characters_cnt[i] % 2 != 0)
      odd_cnts++;

  if (odd_cnts > k)
    return false;

  return true;
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    string s;
    int k;

    cin >> s >> k;

    bool result = can_construct(s, k);
    cout << result << '\n';
  }

  return 0;
}
