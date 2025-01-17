#include <iostream>
#include <vector>
using namespace std;

vector<string> string_matching(vector<string> &words) {
  vector<string> result;

  for (int i = 0; i < words.size(); i++) {
    string word = words[i];

    for (int j = 0; j < words.size(); j++) {
      string word1 = words[j];

      if (i == j || word.size() > word1.size())
        continue;
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

    vector<string> result = string_matching(words);

    for (auto val : result)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}
