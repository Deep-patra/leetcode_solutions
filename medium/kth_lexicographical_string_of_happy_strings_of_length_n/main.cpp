#include <iostream>
#include <set>
#include <vector>
using namespace std;

char ch[3] = { 'a', 'b', 'c' };

bool generate_all_combinations(int n, int k, string s,
                               vector<string> &combinations, int index = 0) {

  if (index == s.length()) {
    combinations.push_back(s);
    return true;
  }

  for (auto c : ch) {
    if (s[index] != c) {
      s[index] = c;
      if (generate_all_combinations(n, k, s, combinations, index + 1))
        return true;

      s[index] = '.';
    }
  }

  return false;
}

string get_happy_string(int n, int k) {
  vector<string> combinations;
  string s(n, '.');

  generate_all_combinations(n, k, s, combinations);

  for (auto item : combinations)
    cout << item << endl;


  if (k > combinations.size())
    return "";

  return combinations[k - 1];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, k;
    cin >> n >> k;

    string result = get_happy_string(n, k);
    cout << result << '\n';
  }

  return 0;
}
