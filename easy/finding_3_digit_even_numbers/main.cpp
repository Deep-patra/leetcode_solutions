#include <bits/stdc++.h>
using namespace std;

void generate_numbers(string &s, int idx, int freq[10], set<int> &st) {
  if (idx == 3) {
    string temp = s;
    reverse(temp.begin(), temp.end());

    int num = stoi(temp);

    if (st.find(num) == st.end())
      st.insert(num);

    return;
  }

  if (idx > 0) {

    int i = idx == 2 ? 1 : 0;

    while (i < 10) {
      if (freq[i] > 0) {
        s.push_back(i + '0');
        freq[i]--;

        generate_numbers(s, idx + 1, freq, st);

        s.pop_back();
        freq[i]++;
      }

      i++;
    }

    return;
  }

  for (int i = 0; i < 10; i += 2) {
    if (freq[i] > 0) {

      s.push_back(i + '0');
      freq[i]--;

      generate_numbers(s, idx + 1, freq, st);

      s.pop_back();
      freq[i]++;
    }
  }

  return;
}

vector<int> find_even_numbers(vector<int> &digits) {
  int freq[10];
  memset(freq, 0, sizeof(freq));

  for (int digit : digits)
    freq[digit]++;

  set<int> s;
  string num;

  generate_numbers(num, 0, freq, s);

  vector<int> result;
  for (int val : s)
    result.push_back(val);

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> digits(n);
    for (int i = 0; i < n; i++)
      cin >> digits[i];

    vector<int> result = find_even_numbers(digits);

    for (int res : result)
      cout << res << " ";
    cout << endl;
  }

  return 0;
}
