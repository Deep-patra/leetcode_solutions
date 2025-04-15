#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> query_results(int limit, vector<vector<int>> &queries) {
  vector<int> result(queries.size(), 0);

  // current distinct colors
  unordered_map<int, int> assigned_color;
  unordered_map<int, int> assigned_ball;

  for (int i = 0; i < queries.size(); i++) {

    int ball = queries[i][0], color = queries[i][1];

    // if the ball already assigned color
    // remove the assigned color
    if (assigned_ball.find(ball) != assigned_ball.end()) {
      assigned_color[assigned_ball[ball]]--;

      // check if the color is assigned to any ball
      // if not then remove the color
      if (assigned_color[assigned_ball[ball]] == 0)
        assigned_color.erase(assigned_ball[ball]);

      assigned_ball[ball] = 0;
    }

    assigned_ball[ball] = color;

    assigned_color[assigned_ball[ball]]++;
    result[i] = assigned_color.size();
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int limit, len;
    cin >> limit >> len;

    vector<vector<int>> queries(len, vector<int>(2, 0));
    for (int i = 0; i < len; i++)
      cin >> queries[i][0] >> queries[i][1];

    vector<int> result = query_results(limit, queries);
    for (auto val : result)
      cout << val << " ";

    cout << "\n";
  }

  return 0;
}
