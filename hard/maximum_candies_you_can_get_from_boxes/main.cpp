#include <bits/stdc++.h>
using namespace std;

// INFO: Solved But a bit slow
int max_candies(vector<int> &status, vector<int> &candies,
                vector<vector<int>> &keys, vector<vector<int>> &containedBoxes,
                vector<in> &initialBoxes) {

  unordered_set<int> open_boxes, available_boxes;

  for (int i = 0; i < status.size(); i++)
    if (status[i])
      open_boxes.insert(i);

  for (int box : initialBoxes)
    available_boxes.insert(box);

  int res = 0;
  while (available_boxes.size() != 0) {

    bool valid = 0;

    unordered_set<int> temp = available_boxes;

    for (int box : temp) {

      if (open_boxes.find(box) == open_boxes.end())
        continue;

      valid = 1;

      // check if the current available open box has any keys
      for (int key : keys[box])
        open_boxes.insert(key);

      // check if the current box has any other contained boxes;
      for (int b : containedBoxes[box])
        available_boxes.insert(b);

      // remove this current box and add the candies
      available_boxes.erase(box);

      res += candies[box];
    }

    // if any available boxes is not open
    // no reason to iterate again, return the collected candies
    if (!valid)
      return res;
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> status(n);
    for (int i = 0; i < n; i++)
      cin >> status[i];

    vector<int> candies(n);
    for (int i = 0; i < n; i++)
      cin >> candies[i];

    vector<vector<int>> keys(n);
    for (int i = 0; i < n; i++) {
      int m;
      cin >> m;

      vector<int> k(m);
      for (int j = 0; j < m; j++)
        cin >> k[j];

      keys[i] = k;
    }

    vector<vector<int>> containedBoxes(n);
    for (int i = 0; i < n; i++) {
      int m;
      cin >> m;

      vector<int> boxes(m);
      for (int j = 0; j < m; j++)
        cin >> boxes[j];

      containedBoxes[i] = boxes;
    }

    int m;
    cin >> m;

    vector<int> initialBoxes(m);
    for (int i = 0; i < m; i++)
      cin >> initialBoxes[i];

    int res = max_candies(status, candies, keys, containedBoxes, initialBoxes);
    cout << res << '\n';
  }

  return 0;
}
