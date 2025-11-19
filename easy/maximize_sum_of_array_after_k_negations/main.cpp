#include <bits/stdc++.h>
using namespace std;

int largest_sum_after_k_negations(vector<int> &nums, int k) {
  int n = nums.size(), sum = 0;

  vector<int> freq(201, 0);

  for (int val : nums)
    freq[val + 100]++;

  int i = 0;
  while (k > 0 && i < 201) {

    if (i < 100) {
      if (freq[i] == 0) {
        i++;
        continue;
      }

      freq[i]--;
      freq[(100 - i) + 100]++;
      k--;
      continue;
    }

    if (freq[100] > 0 || !(k & 1))
      break;

    if (k & 1) {
      int j = 101;
      while (j < 201) {
        if (freq[j] > 0) {
          freq[j]--;
          freq[200 - j]++;
          break;
        }

        j++;
      }

      break;
    }
  }

  for (int i = 200; i >= 0; i--) {
    sum += ((i - 100) * freq[i]);
  }

  return sum;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int res = largest_sum_after_k_negations(nums, k);
    cout << res << '\n';
  }

  return 0;
}
