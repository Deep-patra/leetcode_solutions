#include <iostream>
#include <vector>
using namespace std;

// Greedy approach
string push_dominoes(string dominoes) {

  int n = dominoes.length();

  auto set_direction = [&](int start, int end) {
    char left = start == 0 ? '.' : dominoes[start - 1];
    char right = end == n - 1 ? '.' : dominoes[end + 1];

    if (left == '.' && right == '.' || left == 'L' && right == 'R')
      return;

    else if (left != 'R' && right == 'L')
      while (start <= end)
        dominoes[start++] = 'L';

    else if (right != 'L' && left == 'R')
      while (start <= end)
        dominoes[start++] = 'R';

    else if (left == 'R' && right == 'L') {
      while (start < end) {
        dominoes[start++] = 'R';
        dominoes[end--] = 'L';
      }
    }
  };

  int i = 0, start = -1;

  while (i < n) {
    if (dominoes[i] == '.') {
      if (start == -1)
        start = i;
    } else {
      if (start != -1) {
        set_direction(start, i - 1);
        start = -1;
      }
    }

    i++;
  }

  if (start != -1)
    set_direction(start, n - 1);

  return dominoes;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string dominoes;
    cin >> dominoes;

    string result = push_dominoes(dominoes);
    cout << result << '\n';
  }

  return 0;
}
