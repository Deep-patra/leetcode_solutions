#include <bits/stdc++.h>  
using namespace std;

int power_of_2[32][10];
bool initialized = 0;

void get_digit_freq(int freq[10], int n) {
  while (n > 0) {
    freq[n % 10] ++;
    n /= 10;
  }
}

bool reordered_power_of_2(int n) {

  if (n == 1) return 1;

  if (!initialized) {

    memset(power_of_2, 0, sizeof(power_of_2));

    for (int i = 0; i < 32; i ++) 
      get_digit_freq(power_of_2[i], (1 << i));

    initialized = 1;
  }

  int freq[10];
  memset(freq, 0, sizeof(freq));

  for (int i = 1; i < 32; i ++) {

    bool matched = 1;

    for (int j = 0; j < 10; j ++) {
      if (power_of_2[i][j] != freq[j]) {
        matched = 0;
        break;
      }
    }

    if (matched) return 1;
  }

  return 0;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    bool res = reordered_power_of_2(n);
    cout << res << '\n';
  }

  return 0;
}
