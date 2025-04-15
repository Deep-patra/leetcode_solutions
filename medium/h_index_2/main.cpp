#include <bits/stdc++.h>
using namespace std;

bool is_possible(vector<int> &citations, int h) {
  if (h > citations.size()) return false;

  int cnt = 0;
  for (int val : citations) 
    if (val >= h)
      cnt ++;

  return cnt >= h;
}

int h_index(vector<int> &citations) {

  if (citations.size() == 0) return 0;

  int l = 0, r = citations.size(), mid, result = 0;

  while (l <= r) {
    mid = l + (r - l) / 2;

    if (is_possible(citations, mid)) {
      result = max(result, mid);
      l = mid + 1;
    }

    else 
      r = mid - 1;
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int len;
    cin >> len;

    vector<int> citations(len, 0);
    for (int i = 0; i < len; i++)
      cin >> citations[i];

    int result = h_index(citations);
    cout << result << '\n';
  }

  return 0;
}
