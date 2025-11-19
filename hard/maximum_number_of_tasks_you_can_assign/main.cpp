#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// try to solve it with binary search
int max_task_assign(vector<int> &tasks, vector<int> &workers, int pills,
                    int strength) {

  // sort the tasks and workers
  sort(tasks.begin(), tasks.end());
  sort(workers.begin(), workers.end());

  set<int> workers_set, tasks_set;

  int i = 0, j = 0, res = 0;

  while (i < workers.size() && j < tasks.size()) {
    if (workers[i] >= tasks[j]) {

      workers_set.insert(i);
      tasks_set.insert(j);

      i++;
      j++;
      res++;

    } else {
      i++;
      j++;
    }
  }

  i = 0, j = 0;
  while (i < workers.size() && j < tasks.size() && pills > 0) {
    if (workers_set.find(i) != workers_set.end()) {
      i++;
      continue;
    }

    if (tasks_set.find(j) != tasks_set.end()) {
      j++;
      continue;
    }

    if (workers[i] + strength >= tasks[j]) {

      res++;
      i++;
      j++;

      pills--;

    } else
      i++;
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m, pills, strength;
    cin >> n >> m >> pills >> strength;

    vector<int> tasks(n);
    for (int i = 0; i < n; i++)
      cin >> tasks[i];

    vector<int> workers(m);
    for (int i = 0; i < m; i++)
      cin >> workers[i];

    int res = max_task_assign(tasks, workers, pills, strength);
    cout << res << '\n';
  }

  return 0;
}
