#include <bits/stdc++.h>
using namespace std;

auto sort_by_x = [](vector<int> &a, vector<int> &b) -> bool {
  if (a[0] == b[0])
    return a[2] > b[2];

  return a[0] < b[0];
};

auto sort_by_y = [](vector<int> &a, vector<int> &b) -> bool {
  if (a[1] == b[1])
    return a[3] > b[3];

  return a[1] < b[1];
};

bool check_valid_cuts(int n, vector<vector<int>> &rectangles) {
  if (rectangles.size() == 0) return false;

  // check if the vertical cuts are possible
  sort(rectangles.begin(), rectangles.end(), sort_by_x);

  int latest_end = rectangles[0][2], cuts = 0;
  for (int i = 1; i < rectangles.size(); i++) {
    int start = rectangles[i][0], end = rectangles[i][2];

    if (latest_end <= start) {
      cuts ++;
    }

    latest_end = max(latest_end, end);
    if (cuts >= 2) return true;
  }

  // check if the horizontal cuts are possible
  sort(rectangles.begin(), rectangles.end(), sort_by_y);

  latest_end = rectangles[0][3];
  cuts = 0;

  for (int i = 1; i < rectangles.size(); i++) {
    int start = rectangles[i][1], end = rectangles[i][3];

    if (latest_end <= start)
      cuts ++;

    latest_end = max(latest_end, end);
    if (cuts >= 2) return true;
  }

  return false;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> rectangles(m, vector<int>(4, 0));
    for (int i = 0; i < m; i++)
      cin >> rectangles[i][0] >> rectangles[i][1] >> rectangles[i][2] >> rectangles[i][3]; 

    bool result = check_valid_cuts(n, rectangles);
    cout << result << '\n';
  }

  return 0;
}
