#include <bits/stdc++.h>
using namespace std;

#define fst first
#define sec second

pair<int, int> get_min_max(vector<vector<int>> &grid) {
  int minimum = grid[0][0], maximum = grid[0][0];

  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      minimum = min(minimum, grid[i][j]);
      maximum = max(maximum, grid[i][j]);
    }
  }

  return make_pair(minimum, maximum);
}

vector<int> max_points(vector<vector<int>> &grid, vector<int> &queries) {

  int m = grid.size(), n = grid[0].size();

  vector<int> result(queries.size(), 0);

  vector<pair<int, int>> sorted_queries(queries.size());
  for (int i = 0; i < queries.size(); i++)
    sorted_queries[i] = make_pair(queries[i], i);

  auto comparator = [](pair<int, int> &a, pair<int, int> &b) -> bool {
    return a.first < b.first;
  };

  sort(sorted_queries.begin(), sorted_queries.end(), comparator);

  pair<int, int> min_max = get_min_max(grid);

  if (min_max.second < sorted_queries[queries.size() - 1].first)
    return vector<int>(queries.size(), m * n);

  else if (min_max.first > sorted_queries[0].first)
    return result;

  auto pq_comparator = [&](pair<int, int> &a, pair<int, int> &b) -> bool {
    return grid[a.first][a.second] > grid[b.first][b.second];
  };

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 decltype(pq_comparator)>
      pq(pq_comparator);

  vector<vector<bool>> visited(m, vector<bool>(n, 0));

  pq.push({0, 0});
  visited[0][0] = 1;

  int val = 0;
  for (pair<int, int> q : sorted_queries) {

    while (!pq.empty() && grid[pq.top().first][pq.top().second] < q.first) {

      pair<int, int> top = pq.top();
      pq.pop();

      val++;

      if (top.first > 0 && !visited[top.first - 1][top.second]) {
        visited[top.first - 1][top.second] = 1;
        pq.push({top.first - 1, top.second});
      }

      if (top.first < m - 1 && !visited[top.first + 1][top.second]) {
        visited[top.first + 1][top.second] = 1;
        pq.push({top.first + 1, top.second});
      }

      if (top.second > 0 && !visited[top.first][top.second - 1]) {
        visited[top.first][top.second - 1] = 1;
        pq.push({top.first, top.second - 1});
      }

      if (top.second < n - 1 && !visited[top.first][top.second + 1]) {
        visited[top.first][top.second + 1] = 1;
        pq.push({top.first, top.second + 1});
      }
    }

    result[q.second] = val;
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> grid[i][j];

    int q;
    cin >> q;

    vector<int> queries(q, 0);
    for (int i = 0; i < q; i++)
      cin >> queries[i];

    vector<int> result = max_points(grid, queries);
    for (int val : result)
      cout << val << " ";
    cout << '\n';
  }

  return 0;
}
