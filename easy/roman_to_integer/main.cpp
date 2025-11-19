#include <bits/stdc++.h>
using namespace std;

constexpr unordered_map<string, int> initialize_map() {

  unordered_map<string, int> romans;

  romans.insert(make_pair("I", 1));
  romans.insert(make_pair("II", 2));
  romans.insert(make_pair("III", 3));
  romans.insert(make_pair("IV", 4));
  romans.insert(make_pair("V", 5));
  romans.insert(make_pair("VI", 6));
  romans.insert(make_pair("VII", 7));
  romans.insert(make_pair("VIII", 8));
  romans.insert(make_pair("IX", 9));

  romans.insert(make_pair("X", 10));
  romans.insert(make_pair("XX", 20));
  romans.insert(make_pair("XX", 30));
  romans.insert(make_pair("XL", 40));
  romans.insert(make_pair("L", 50));
  romans.insert(make_pair("LX", 60));
  romans.insert(make_pair("LXX", 70));
  romans.insert(make_pair("LXXX", 80));
  romans.insert(make_pair("XC", 90));

  romans.insert(make_pair("C", 100));
  romans.insert(make_pair("CC", 200));
  romans.insert(make_pair("CCC", 300));
  romans.insert(make_pair("CD", 400));
  romans.insert(make_pair("D", 500));
  romans.insert(make_pair("DC", 600));
  romans.insert(make_pair("DCC", 700));
  romans.insert(make_pair("DCCC", 800));
  romans.insert(make_pair("CM", 900));
  romans.insert(make_pair("M", 1000));

  return romans;
}

constexpr unordered_map<string, int> r = initialize_map();

int roman_to_int(string s) {

  int i = 0, res = 0;
  while (i < s.length()) {
    int j = i;

    while (j < s.length() && r.find(s.substr(i, j - i + 1)) != r.end()) {
      j++;
    }

    res += r[s.substr(i, j - i)];
    i = j;
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s;
    cin >> s;

    int res = roman_to_int(s);
    cout << res << '\n';
  }

  return 0;
}
