#include <iostream>
#include <vector>
using namespace std;

// FIX: Combine the subset words in to one word and re-implement the algorithm


bool is_subset(string word, vector<int> character_list) {
  for (int i = 0; i < word.size(); i++) {

    if (character_list[word[i] - 'a'] == 0)
      return false;

    character_list[word[i] - 'a']--;
  }

  return true;
}

vector<string> word_subsets(vector<string> &words1, vector<string> &words2) {
  vector<string> result;

  vector<vector<int>> characters(words1.size(), vector<int>(26, 0));

  for (int i = 0; i < words1.size(); i++) {
    string word = words1[i];

    for (int j = 0; j < word.length(); j++)
      characters[i][word[j] - 'a']++;
  }

  for (int i = 0; i < words1.size(); i++) {

    vector<int> character_list = characters[i];

    int res = 0;
    for (int j = 0; j < words2.size(); j++) {
      string word2 = words2[j];

      if (is_subset(word2, character_list))
        res++;
      else
        break;
    }

    if (res == words2.size())
      result.push_back(words1[i]);
  }

  return result;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len1;
    cin >> len1;

    vector<string> words1(len1);
    for (int i = 0; i < len1; i++)
      cin >> words1[i];

    int len2;
    cin >> len2;

    vector<string> words2(len2);
    for (int i = 0; i < len2; i++)
      cin >> words2[i];

    vector<string> result = word_subsets(words1, words2);
    for (auto val : result)
      cout << val << " ";

    cout << endl;
  }

  return 0;
}
