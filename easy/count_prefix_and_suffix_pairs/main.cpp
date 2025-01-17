#include <iostream>
#include <vector>
using namespace std;

bool is_prefix_and_suffix(string word1, string word2) {

  for (int i = 0; i < word1.size(); i++) {

    if (word1[i] != word2[i])
      return false;

    if (word1[word1.size() - 1 - i] != word2[word2.size() - 1 - i])
      return false;
  }

  return true;
}

int count_prefix_suffix_pairs(vector<string> &words) {

  int result = 0;

  for (int i = 0; i < words.size(); i++) {
    for (int j = i + 1; j < words.size(); j++) {
      if (words[i] <= words[j] && is_prefix_and_suffix(words[i], words[j]))
        result++;
    }
  }

  return result;
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len;
    cin >> len;

    vector<string> words(len, "");
    for (int i = 0; i < len; i++)
      cin >> words[i];

    int result = count_prefix_suffix_pairs(words);
    cout << result << '\n';
  }

  return 0;
}
