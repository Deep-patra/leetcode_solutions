#include <bits/stdc++.h>
using namespace std;

int candy(vector<int> &ratings) {
  int n = ratings.size(), curr = 0, candies = 0;

  for (int i = 0; i < n - 1; i++) {

    if (ratings[i] < ratings[i + 1]) {
      candies += ++curr;
    } else if (ratings[i] == ratings[i + 1]) {
      candies += ++curr;
      curr = 0;
    } else {
      int max_candies = 0, j = i;

      while (j < n - 1 && ratings[j] > ratings[j + 1]) {
        max_candies++;
        j++;
      }

      candies += max(max_candies + 1, curr + 1);
      candies += ((max_candies - 1) * (2 * 2 + (max_candies - 2))) / 2;

      curr = 0;

      i = --j;
    }
  }

  candies += ++curr;

  return candies;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> ratings(n);
    for (int i = 0; i < n; i++)
      cin >> ratings[i];

    int result = candy(ratings);
    cout << result << '\n';
  }

  return 0;
}
