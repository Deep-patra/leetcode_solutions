#include <iostream>
#include <vector>
using namespace std;

// INFO: Dunno what's the problem really is
bool construct_sequence(int n, vector<int> &sequence, int mask, int index = 0) {

  if (index == sequence.size())
    return true;

  if (sequence[index] != 0)
    return construct_sequence(n, sequence, mask, index + 1);

  int i = index;
  for (int num = n; num >= 1; num--) {

    // if the number is already in the sequence
    if (mask & (1 << num))
      continue;

    if (num == 1) {
      sequence[i] = 1;

      if (construct_sequence(n, sequence, mask | (1 << 1), index + 1))
        return true;

      sequence[i] = 0;
    }

    else if ((i + num) < sequence.size() && sequence[i + num] == 0) {
      sequence[i] = sequence[i + num] = num;

      if (construct_sequence(n, sequence, mask | (1 << num), index + 1))
        return true;

      sequence[i] = sequence[i + num] = 0;
    }
  }

  return false;
}

vector<int> construct_distance_sequence(int n) {
  if (n == 1)
    return vector<int>(1, 1);

  vector<int> result(2 * n - 1, 0);

  construct_sequence(n, result, 0);

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> result = construct_distance_sequence(n);

    for (int val : result)
      cout << val << " ";
    cout << endl;
  }

  return 0;
}
