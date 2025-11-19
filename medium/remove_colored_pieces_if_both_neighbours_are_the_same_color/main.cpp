#include <bits/stdc++.h>  
using namespace std;

bool winner_of_game(string colors) {
  int l = colors.length(), a_count = 0, b_count = 0;

  for (int i = 1; i < l - 1; i ++) {
    
    if (colors[i] == 'A' && colors[i - 1] == 'A' && colors[i - 1] == colors[i + 1])
      a_count ++;

    if (colors[i] == 'B' && colors[i - 1] == 'B' && colors[i - 1] == colors[i + 1])
      b_count ++;
  }

  if (a_count > b_count) return 1;

  return 0;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string colors;
    cin >> colors;

    bool res = winner_of_game(colors);
    cout << res << '\n';
  }

  return 0;
}
