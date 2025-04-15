#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int num_of_subarrays(vector<int> &arr) {
  long result = 0, even_count = 0, odd_count = 0;

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] & 1) {
      int temp = odd_count;
      odd_count = even_count + 1;
      even_count = temp;
    } else 
      even_count ++;

    result += odd_count;
  }

  return (int)result % MOD;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
      cin >> arr[i];

    int result = num_of_subarrays(arr);
    cout << result << '\n';
  }

  return 0;
}
