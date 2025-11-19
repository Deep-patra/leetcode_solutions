#include <bits/stdc++.h>  
using namespace std;

int minimize_concatenated_length(vector<string> &words) {
  int n = words.size();

  
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i ++)
      cin >> words[i];

    int res = minimize_concatenated_length(words);
    cout << res << endl;
  }

  return 0;
}
