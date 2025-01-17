#include <iostream>
#include <vector>
using namespace std;

int find_min_arrow_shots(vector<vector<int>> &points) {}

int main() {
  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len;
    cin >> len;

    vector<vector<int>> points(len, vector<int>(2, 0));
    for (int i = 0; i < len; i++)
      cin >> points[i][0] >> points[i][1];

    int result = find_min_arrow_shots(points);

    cout << result << '\n';
  }

  return 0;
}
