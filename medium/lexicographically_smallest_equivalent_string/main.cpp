#include <bits/stdc++.h>
using namespace std;

void dfs(int graph[26][26], int min_map[26], int i, int j) {

  if (min_map[i] < j)
    return;

  min_map[i] = j;

  for (int k = 0; k < 26; k++) {
    if (graph[i][k] && min_map[k] > j)
      dfs(graph, min_map, k, j);
  }
}

string smallest_equivalent_string(string s1, string s2, string baseStr) {

  int graph[26][26], min_map[26];

  memset(graph, 0, sizeof(graph));

  for (int i = 0; i < 26; i++)
    min_map[i] = i;

  for (int i = 0; i < s1.length(); i++) {
    int x = s1[i] - 'a', y = s2[i] - 'a';

    graph[x][y] = graph[y][x] = 1;
  }

  for (int i = 0; i < 26; i++)
    if (min_map[i] >= i)
      dfs(graph, min_map, i, i);

  string res;

  for (int i = 0; i < baseStr.length(); i++)
    res.push_back(min_map[baseStr[i] - 'a'] + 'a');

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s1, s2, base_str;
    cin >> s1 >> s2 >> base_str;

    string res = smallest_equivalent_string(s1, s2, base_str);
    cout << res << '\n';
  }

  return 0;
}
