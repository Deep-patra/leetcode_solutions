#include <bits/stdc++.h>
using namespace std;

int min_score_triangulation(vector<int> &values) {
  int n = values.size();

  sort(values.begin(), values.end());

  priority_queue<int> pq;

  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {

        int prod = values[i] * values[j] * values[k];

        pq.push(prod);

        if (pq.size() > n - 2)
          pq.pop();
      }
    }
  }

  int score = 0;
  while (!pq.empty()) {

    cout << pq.top() << " ";

    score += pq.top();
    pq.pop();
  }

  return score;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> values(n);
    for (int i = 0; i < n; i++)
      cin >> values[i];

    int res = min_score_triangulation(values);
    cout << res << endl;
  }

  return 0;
}
