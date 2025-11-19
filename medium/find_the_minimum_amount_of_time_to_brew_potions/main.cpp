#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll min_time(vector<int> &skill, vector<int> &mana) {
  int n = skill.size(), m = mana.size();

  ll delay = 0;

  vector<ll> start_time(n + 1, 0);

  for (int i = 0; i < n; i++)
    start_time[i + 1] = start_time[i] + (skill[i] * mana[0]);

  for (int i = 1; i < m; i++) {

    ll curr_delay = 0;
    for (int j = 0; j < n; j ++) {  
     
      ll d = start_time[j + 1] - (start_time[j] + curr_delay);
      curr_delay += max(0, d);

      start_time[j + 1] = (start_time[j]) + (skill[j] * mana[i]); 
    } 

    delay += curr_delay;
  }

  return start_time[n] + delay;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m;
    cin >> n >> m;

    vector<int> skill(n), mana(m);
    for (int i = 0; i < n; i++)
      cin >> skill[i];

    for (int i = 0; i < m; i++)
      cin >> mana[i];

    ll res = min_time(skill, mana);
    cout << res << endl;
  }

  return 0;
}
