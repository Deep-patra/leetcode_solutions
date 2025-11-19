#include <bits/stdc++.h>
using namespace std;

double max_average_ratio(vector<vector<int>> &classes, int extra_students) {
  int n = classes.size();

  typedef pair<double, int> pi;

  auto find_gain = [&](int idx) -> double {
    double gain =
        ((double)(classes[idx][0] + 1) / (double)(classes[idx][1] + 1)) -
        ((double)classes[idx][0] / (double)classes[idx][1]);
    return gain;
  };

  priority_queue<pi, vector<pi>> pq;

  for (int i = 0; i < n; i++)
    pq.push({find_gain(i), i});

  while (extra_students > 0) {

    pi top = pq.top();
    pq.pop();

    classes[top.second][0]++;
    classes[top.second][1]++;

    pq.push({find_gain(top.second), top.second});
    extra_students--;
  }

  double ratio = 0.0;

  for (int i = 0; i < n; i++)
    ratio += ((double)classes[i][0] / (double)classes[i][1]);

  return (double)ratio / (double)n;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, extra_students;
    cin >> n >> extra_students;

    vector<vector<int>> classes(n, vector<int>(2));
    for (int i = 0; i < n; i++)
      cin >> classes[i][0] >> classes[i][1];

    double max_ratio = max_average_ratio(classes, extra_students);
    cout << fixed << setprecision(5);
    cout << max_ratio << endl;
  }

  return 0;
}
