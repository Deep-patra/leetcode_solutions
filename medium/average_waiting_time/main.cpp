#include <bits/stdc++.h>  
using namespace std;

double average_waiting_time(vector<vector<int>> &customers) {
  int n = customers.size(), t = customers[0][0] + customers[0][1];

  double sum = (double)(customers[0][1]);
  for (int i = 1; i < n; i ++) {
    if (t <= customers[i][0]) {
      t = customers[i][0] + customers[i][1];
      sum += (double)(customers[i][1]);
    } else {
      sum += (double)(customers[i][1] + (t - customers[i][0]));
      t += customers[i][1];
    }
  }

  return (double) (sum / (double)(n));
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<vector<int>> customers(n, vector<int>(2));
    for (int i = 0; i < n; i ++)
      cin >> customers[i][0] >> customers[i][1];

    double res = average_waiting_time(customers);
    cout << fixed << setprecision(5) << res << endl;
  }

  return 0;
}
