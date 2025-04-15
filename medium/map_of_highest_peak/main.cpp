#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// using bfs approach
// FAILED: Time Limit Exceeded
vector<vector<int>> _highest_peak(vector<vector<int>> &isWater) {
  int m = isWater.size(), n = isWater[0].size();

  vector<vector<int>> result(m, vector<int>(n, INT_MAX));
  vector<vector<bool>> visited(m, vector<bool>(n, 0));

  queue<pair<int, int>> q;

  stack<pair<int, int>> water_parts;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (isWater[i][j] == 1)
        water_parts.push({i, j});

  while (!water_parts.empty()) {

    pair<int, int> top = water_parts.top();
    int i = top.first, j = top.second;

    water_parts.pop();

    q.push(make_pair(i, j));
    result[i][j] = 0;

    while (!q.empty()) {
      pair<int, int> front = q.front();
      q.pop();
      int row = front.first;
      int col = front.second;

      visited[row][col] = 1;

      if (row - 1 >= 0 && !visited[row - 1][col]) {
        if (result[row - 1][col] > result[row][col] + 1) {
          result[row - 1][col] = result[row][col] + 1;
          q.push({row - 1, col});
        }
      }

      if (row + 1 < m && !visited[row + 1][col]) {
        if (result[row + 1][col] > result[row][col] + 1) {
          result[row + 1][col] = result[row][col] + 1;
          q.push({row + 1, col});
        }
      }

      if (col - 1 >= 0 && !visited[row][col - 1]) {
        if (result[row][col - 1] > result[row][col] + 1) {
          result[row][col - 1] = result[row][col] + 1;
          q.push({row, col - 1});
        }
      }

      if (col + 1 < n && !visited[row][col + 1]) {
        if (result[row][col + 1] > result[row][col] + 1) {
          result[row][col + 1] = result[row][col] + 1;
          q.push({row, col + 1});
        }
      }
    }

    visited = vector<vector<bool>>(m, vector<bool>(n, 0));
  }

  return result;
}

vector<vector<int>> highest_peak(vector<vector<int>> &isWater) {
  int m = isWater.size(), n = isWater[0].size();

  vector<vector<int>> cell_heights(m, vector<int>(n, -1));

  queue<pair<int, int>> q;

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (isWater[i][j]) 
        q.push({ i, j });


  int height = 0;
  while (!q.empty()) {

    int queue_size = q.size();

    for (int i = 0; i < queue_size; i++) {
      pair<int, int> front = q.front();
      int row = front.first, col = front.second;
      q.pop();

      if (cell_heights[row][col] == -1) {
        cell_heights[row][col] = height;

        if (row - 1 >= 0) q.push({ row - 1, col });
        if (row + 1 < m) q.push({ row + 1, col });
        if (col - 1 >= 0) q.push({ row, col - 1 });
        if (col + 1 < n) q.push({ row, col + 1 });
      }
    }

    height ++;
  }

  return cell_heights;
}

int main() {

  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m, n;
    cin >> m >> n;

    vector<vector<int>> isWater(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> isWater[i][j];

    vector<vector<int>> result = highest_peak(isWater);

    for (auto item : result) {
      for (int val : item)
        cout << val << " ";
      cout << endl;
    }
  }

  return 0;
}
