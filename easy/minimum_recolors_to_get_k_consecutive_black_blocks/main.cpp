#include <bits/stdc++.h>
using namespace std;


// INFO: Using sliding window technique,
int minimum_recolors(string blocks, int k) {
  
  int curr_blacks = blacks = blocks[0] == 'B' ? 1 : 0;

  int i = 0, j = 0;
  while (j < blocks.length() - 1) {
    if ((j - i + 1) < k) {
      if (blocks[++ j] == 'B') curr_blacks ++;
 
      blacks = curr_blacks;
      continue;
    }

    // slide the window
    if (blocks[++ j] == 'B')
      curr_blacks ++;

    if (blocks[i ++] == 'B')
      curr_blacks --;

    blacks = max(blacks, curr_blacks);
  }

  return k - blacks;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string blocks;
    int k;

    cin >> blocks >> k;

    int result = minimum_recolors(blocks, k);
    cout << result << '\n';
  }

  return 0;
}
