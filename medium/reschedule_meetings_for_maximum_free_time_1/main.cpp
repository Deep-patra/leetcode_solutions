#include <bits/stdc++.h>  
using namespace std;

// TODO: Complete the Implementation
int max_free_time(int eventTime, int k, vector<int> &startTime, vector<int> &endTime) {
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int event_time, k, n;
    cin >> event_time >> k >> n;

    vector<int> start_time(n), end_time(n);

    for (int i = 0; i < n; i ++)
      cin >> start_time[i];

    for (int i = 0; i < n; i ++)
      cin >> end_time[i];

    int time = max_free_time(event_time, k, start_time, end_time);
    cout << time << endl;
  }

  return 0;
}
