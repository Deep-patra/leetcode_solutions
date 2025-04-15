#include <iostream>
#include <vector>
using namespace std;

// TODO: Complete the implmentation
int find_radius(vector<int> &houses, vector<int> &heaters) {
  int l = 0, h = 30000, res = 30000;

  auto check_if_possible = [&](int mid) -> bool {
    int heater_index = 0;

    for (int i = 0; i < houses.size(); i++) {

    }

    return false;
  }; 


  while (l <= h) {
    int mid = l + (h - l) / 2;


  }

  return res;
}

int main() {

  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int m;
    cin >> m;
    
    vector<int> houses(m, 0);
    for (int i = 0; i < m; i++)
      cin >> houses[i];

    int n;
    cin >> n;

    vector<int> heaters(n, 0);
    for (int i = 0; i < n; i++)
      cin >> heaters[i];

    int result = find_radius(houses, heaters);
    cout << result << '\n';
  }

  return 0;
}
