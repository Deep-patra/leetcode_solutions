#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int max_envelopes(vector<vector<int>> &envelopes) {

  auto comparator = [&](vector<int> a, vector<int> b) -> bool {
    if (a[0] == b[0])
      return a[1] > b[1];
    return a[0] < b[0];
  };

  sort(envelopes.begin(), envelopes.end(), comparator);

  vector<int> result;
  result.push_back(envelopes[0][1]);

  for (int i = 1; i < envelopes.size(); i++) {
    if (envelopes[i][1] > result[result.size() - 1])
      result.push_back(envelopes[i][1]);

    else {
      int pos = lower_bound(result.begin(), result.end(), envelopes[i][1]) -
                result.begin();

      result[pos] = envelopes[i][1];
    }
  }

  return result.size();
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<vector<int>> envelopes(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
      cin >> envelopes[i][0] >> envelopes[i][1];

    int result = max_envelopes(envelopes);
    cout << result << '\n';
  }

  return 0;
}
