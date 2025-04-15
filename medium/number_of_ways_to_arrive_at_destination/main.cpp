#include <bits/stdc++.h>
using namespace std;

const int MOD = 10e9 + 7;

int graph[201][201];
bool visited[201];

// USE DJIKSTRA ALGORITHM

int find_minimum_time(int u, int end, unordered_map<int, int> &m,
                      int time = 0) {

  if (u == end) {
    m[time] = ++m[time] % MOD;
    return time;
  }

  int result = INT_MAX;

  visited[u] = 1;

  for (int i = 0; i < end + 1; i++)
    if (graph[u][i] != -1 && !visited[i]) {
      result = min(result, find_minimum_time(i, end, m, time + graph[u][i]));
    }

  visited[u] = 0;

  return result;
}

int count_paths(int n, vector<vector<int>> &roads) {
  memset(graph, -1, sizeof(graph));
  memset(visited, 0, sizeof(visited));

  for (vector<int> v : roads) {
    graph[v[0]][v[1]] = v[2];
    graph[v[1]][v[0]] = v[2];
  }

  unordered_map<int, int> m;

  int min_time = find_minimum_time(0, n - 1, m);

  return m[min_time];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> roads(m, vector<int>(3));
    for (int i = 0; i < m; i++)
      cin >> roads[i][0] >> roads[i][1] >> roads[i][2];

    int result = count_paths(n, roads);
    cout << result << '\n';
  }

  return 0;
}
