#inlcude <bits/stdc++.h>
using namespace std;

// Using Dynamic programming appraoch
vector<string> full_justify(vector<string> &words, int maxWidth) {

}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, maxWidth;
    cin >> n >> maxWidth;

    vector<string> words(n);
    for (int i = 0; i < n; i++) 
      cin >> words[i];

    vector<string> result = full_justify(words, maxWidth);

    for (string word : result)
      cout << word << " ";
    cout << '\n';
  }

  return 0;
}
