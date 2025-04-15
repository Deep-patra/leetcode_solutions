#include <iostream>
#include <vector>
using namespace std;

// TODO: Complete the Implementation
int tallest_building(vector<int> &rods) {
  int sum = 0;

  for (int i = 0; i < rods.size(); i++)
    sum += rods[i];

  // if sum is odd, the result is not possible
  if (sum & 1)
    return 0;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m;
    cin >> m;

    vector<int> rods(m, 0);
    for (int i = 0; i < m; i++)
      cin >> rods[i];

    int result = tallest_building(rods);
    cout << result << '\n';
  }

  return 0;
}
