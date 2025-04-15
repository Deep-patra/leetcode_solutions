#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// INFO: TIME LIMIT EXCEEDED
vector<bool> check_if_prerequistic(int numCourses,
                                   vector<vector<int>> &prerequisites,
                                   vector<vector<int>> &queries) {

  vector<vector<int>> edges(numCourses, vector<int>(0));

  // initialize the graph edges
  for (int i = 0; i < prerequisites.size(); i++) {
    int a = prerequisites[i][0], b = prerequisites[i][1];
    edges[a].push_back(b);
  }

  vector<vector<int>> pre_comp(numCourses, vector<int>(numCourses, 0));

  // Pre-Compute the results
  for (int i = 0; i < edges.size(); i++) {
    queue<int> q;
    q.push(i);

    while (!q.empty()) {
      int front = q.front();
      q.pop();

      for (int j = 0; j < edges[front].size(); j++) {
        int v = edges[front][j];

        if (pre_comp[i][v])
          continue;

        pre_comp[i][v] = 1;
        q.push(v);
      }
    }
  }

  vector<bool> result(queries.size(), 0);
  for (int i = 0; i < queries.size(); i++) {
    int q1 = queries[i][0], q2 = queries[i][1];
    result[i] = pre_comp[q1][q2];
  }

  return result;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int numCourses;
    cin >> numCourses;

    int m;
    cin >> m;
    vector<vector<int>> prerequisties(m, vector<int>(2, 0));
    for (int i = 0; i < m; i++)
      cin >> prerequisties[i][0] >> prerequisties[i][1];

    int n;
    cin >> n;
    vector<vector<int>> queries(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
      cin >> queries[i][0] >> queries[i][1];

    vector<bool> result =
        check_if_prerequistic(numCourses, prerequisties, queries);

    for (auto val : result)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}
