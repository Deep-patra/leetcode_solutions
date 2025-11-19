#include <bits/stdc++.h>  
using namespace std;

vector<vector<int>> get_skyline(vector<vector<int>> &buildings) {
  int n = buildings.size(l);


}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<vector<int>> buildings(n, vector<int>(3, 0));
    for (int i = 0; i < n; i ++)
      cin >> buildings[i][0] >> buildings[i][1] >> buildings[i][2];  

    vector<vector<int>> res = get_skyline(buildings);

    for (vector<int> l : res) {
      for (int val : l)
        cout << val << " ";

      cout << endl;
    }
  }

  return 0;
}
