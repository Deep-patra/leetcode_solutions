#include <iostream>
#include <vector>
using namespace std;

vector<int> vowels_strings(vector<string> &words,
                           vector<vector<int>> &queries) {
  vector<int> result(queries.size());

  // lambda to check if the current char is vowel or not
  auto is_vowel = [](char ch) -> bool {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
      return true;

    return false;
  };

  vector<int> preprocessed_words(words.size() + 1, 0);
  for (int i = 0; i < words.size(); i++)
    if (is_vowel(words[i][0]) && is_vowel(words[i][words[i].size() - 1]))
      preprocessed_words[i + 1] = 1;

  for (int i = 1; i <= words.size(); i++)
    preprocessed_words[i] += preprocessed_words[i - 1];

  // calculate the queries
  for (int i = 0; i < queries.size(); i++) {
    int l = queries[i][0], r = queries[i][1];
    result[i] = preprocessed_words[r + 1] - preprocessed_words[l];
  }

  return result;
}

int main() {
  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int word_len, queries_len;
    cin >> word_len;

    vector<string> words(word_len);
    for (int i = 0; i < word_len; i++)
      cin >> words[i];

    cin >> queries_len;
    vector<vector<int>> queries(queries_len, vector<int>(2));
    for (int i = 0; i < queries_len; i++)
      cin >> queries[i][0] >> queries[i][1];

    vector<int> result = vowels_strings(words, queries);

    for (auto val : result)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}
