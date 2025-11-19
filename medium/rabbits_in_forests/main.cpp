#include <bits/stdc++.h>
using namespace std;

int freq[1001];

int num_rabbits(vector<int> &answers) {
  int result = 0;

  memset(freq, 0, sizeof(freq)); 

  for (int ans : answers) {
    freq[ans] ++;

    if (freq[ans] > ans + 1) {
      result += (ans + 1);

      freq[ans] = 1;
    }
  }

  for (int i = 0; i < 1001; i ++) 
    if (freq[i] > 0)
      result += (i + 1);

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<int> answers(n);
    for (int i = 0; i < n; i ++)
      cin >> answers[i];

    int result = num_rabbits(answers);
    cout << result << '\n';
  }

  return 0;
}
