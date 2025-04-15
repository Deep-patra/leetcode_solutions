#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<int> parse_log(string log) {
  vector<int> result(3);

  if (log.find("end") != string::npos)
    result[1] = 1;

  int i = 0;
  string id = "";
  char curr = log[i];

  while (i < log.size() && curr != ':') {
    id.push_back(curr);
    curr = log[++i];
  }

  result[0] = stoi(id);

  id = "";
  i = log.size() - 1;
  curr = log[i];

  while (i >= 0 && curr != ':') {
    id.push_back(curr);
    curr = log[--i];
  }

  reverse(id.begin(), id.end());
  result[2] = stoi(id);

  return result;
}

vector<int> exclusive_time(int n, vector<string> &logs) {
  vector<vector<int>> p_logs(logs.size());
  vector<int> result(n);

  for (int i = 0; i < logs.size(); i++)
    p_logs[i] = parse_log(logs[i]);

  stack<int> s;
  s.push(p_logs[0][0]);

  for (int i = 1; i < p_logs.size(); i++) {
    vector<int> prev = p_logs[i - 1];
    vector<int> curr = p_logs[i];

    if (!prev[1] && curr[1] && prev[0] == curr[0])
      result[prev[0]] += curr[2] - prev[2] + 1;

    else if (!prev[1] && !curr[1])
      result[prev[0]] += curr[2] - prev[2];

    else if (prev[1] && curr[1])
      result[curr[0]] += curr[2] - prev[2];

    else if (prev[1] && !curr[1] && !s.empty()) {
      int top = s.top();

      result[top] += curr[2] - prev[2] - 1;
    }

    if (curr[1])
      s.pop();
    else
      s.push(curr[0]);
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m;
    cin >> n >> m;

    vector<string> logs(m, "");
    for (int i = 0; i < m; i++)
      cin >> logs[i];

    vector<int> result = exclusive_time(n, logs);

    for (auto val : result)
      cout << val << " ";
    cout << '\n';
  }

  return 0;
}
