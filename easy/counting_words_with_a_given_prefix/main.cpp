#include <iostream>
#include <vector>
using namespace std;

int prefix_count(vector<string> &words, string pref) {
  int result = 0;

  for (int i = 0; i < words.size(); i++) {
    string word = words[i];

    // check if the size of the word is greater than prefix
    if (word.size() < pref.size())
      continue;

    // check prefix
    int index = 0;
    while (index < pref.size()) {
      if (pref[index] != word[index])
        break;

      index++;
    }

    if (index == pref.size())
      result++;
  }

  return result;
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len;
    string prefix;

    cin >> len >> prefix;

    vector<string> words(len);
    for (int i = 0; i < len; i++)
      cin >> words[i];

    int result = prefix_count(words, prefix);

    cout << result << '\n';
  }

  return 0;
}
