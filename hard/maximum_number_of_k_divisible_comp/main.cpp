#include <iostream>
#include <vector>
using namespace std;

int max_divisible_components(int n, vector<vector<int>> &edges,
                             vector<int> &values, int k) {}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int n, k;
    cin >> n;
    cin >> k;

    int len;
    cin >> len;

    vector<vector<int>> edges;
    for (int i = 0; i < len; i++) {
      vector<int> temp;

      int first, second;
      cin >> first;
      cin >> second;

      temp.push_back(first);
      temp.push_back(second);

      edges.push_back(temp);
    }

    int values_len;
    cin >> values_len;

    vector<int> values;
    for (int i = 0; i < values_len; i++) {
      int num;
      cin >> num;

      values.push_back(num);
    }

    int result = max_divisible_components(n, edges, values, k);
    cout << result << '\n';
  }

  return 0;
}
