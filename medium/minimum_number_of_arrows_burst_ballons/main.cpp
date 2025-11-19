#include <bits/stdc++.h>
using namespace std;

int find_min_arrow_shots(vector<vector<int>> &points) {
  int n = points.size(), arrows = 0;

  sort(points.begin(), points.end());

  int i = 0;
  while (i < n) {

    vector<int> start = points[i++];

    int end = start[1];
    while (i < n && points[i][0] <= end) {
      end = min(end, points[i][1]);
      i ++;
    }

    arrows ++;

    if (i == n) 
      break;
  }

  return arrows;
}

int main() {
  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len;
    cin >> len;

    vector<vector<int>> points(len, vector<int>(2, 0));
    for (int i = 0; i < len; i++)
      cin >> points[i][0] >> points[i][1];

    int result = find_min_arrow_shots(points);
    cout << result << '\n';
  }

  return 0;
}
