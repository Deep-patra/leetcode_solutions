#include <bits/stdc++.h>
using namespace std;

// INFO: BEATS 100% in memory and 99% in Runtime
int number_of_alternating_groups(vector<int> &colors, int k) {
  int n = colors.size(), prev = colors[0], l = 1, groups = 0;

  for (int i = 1; i < (n + k - 1); i++) {
    l = (prev == colors[i % n]) ? 1 : l + 1;
    groups = l >= k ? groups + 1 : groups;

    prev = colors[i % n];
  }

  return groups;
}

// INFO: Works But a bit slow Optimizing it
// int number_of_alternating_groups(vector<int> &colors, int k) {
//
//   int i = 0, j = 0, groups = 0, n = colors.size();
//
//   if (k > n)
//     return 0;
//
//   while (i < n) {
//
//     if (i <= j) {
//
//       if ((j - i + 1) < k) {
//         int next_index = j == n - 1 ? 0 : j + 1;
//
//         if (colors[j] != colors[next_index])
//           j = next_index;
//
//         else {
//           if (colors[j] == colors[next_index] && next_index == 0)
//             break;
//
//           i = j = next_index;
//         }
//
//         continue;
//       }
//
//       groups++;
//       i++;
//     } else {
//
//       if (((j + 1) + (n - i)) < k) {
//
//         if (colors[j] != colors[j + 1])
//           j++;
//
//         else
//           break;
//
//         continue;
//       }
//
//       groups++;
//       i++;
//     }
//   }
//
//  return groups;
// }

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, k;
    cin >> n >> k;

    vector<int> colors(n, 0);
    for (int i = 0; i < n; i++)
      cin >> colors[i];

    int result = number_of_alternating_groups(colors, k);
    cout << result << '\n';
  }

  return 0;
}
