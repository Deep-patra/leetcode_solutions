#include <bits/stdc++.h>
using namespace std;

int num_rescue_boats(vector<int> &people, int limit) {

  int n = people.size();

  sort(people.begin(), people.end());

  int i = 0, j = n - 1, res = 0;

  while (i <= j) {
    if (i == j) {
      res++;
      break;
    }

    if (people[i] + people[j] > limit) {
      j--;
      res++;
      continue;
    }

    res++;
    i++;
    j--;
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, limit;
    cin >> n >> limit;

    vector<int> people(n);
    for (int i = 0; i < n; i++)
      cin >> people[i];

    int res = num_rescue_boats(people, limit);
    cout << res << endl;
  }

  return 0;
}
