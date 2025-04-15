#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

static int factors[100001];
static bool is_initialized = 0;

int generate_prime_factors() {
  for (int num = 1; num < 100001; num ++) {

    int res = 0, i = 2, n = num;

    while (i * i <= n) {
      if (n % i == 0)
        res ++;

      while (n % i == 0)
        n /= i;

      i ++;
    }    

    factors[num] = res;
  }
}

// TODO: Complete the implementation
int maximize_score(vector<int> &nums, int k) {
  if (!is_initailized)
    generate_prime_factors();


  
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
      cin >> nums[i];

    int result = maximize_score(nums, k);
    cout << result << '\n';
  }

  return 0;
}
