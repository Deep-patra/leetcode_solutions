#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

static char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
static int characters[26];

bool is_vowel(char ch) {
  switch (ch) {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
    return true;
  default:
    break;
  }

  return false;
}

bool are_all_vowels_present_once() {
  for (int i = 0; i < 5; i++)
    if (characters[vowels[i] - 'a'] == 0)
      return false;

  return true;
}

// INFO: Solved Beats 99%
ll count_substrings(string word, int k) {
  memset(characters, 0, sizeof(characters));

  if (k + 5 > word.length())
    return 0;

  int i = 0, j = 0, consonants = 0, last_cons = -1;

  ll res = 0;

  if (is_vowel(word[0]))
    characters[word[0] - 'a']++;
  else
    consonants++;

  while (j <= word.length()) {

    if (((j - i) + 1 >= (5 + k)) && are_all_vowels_present_once() &&
        consonants == k) {

      res++;

      if (last_cons < j) {
        last_cons = j;

        while ((last_cons + 1) < word.length() && is_vowel(word[last_cons + 1])) 
          last_cons++;
      }


      if (last_cons > j) 
        res += (last_cons - j);

      if (is_vowel(word[i]))
        characters[word[i] - 'a']--;

      else
        consonants--;

      i++;
    } else {

      // if consonant is greater than k
      if (consonants > k) {
        while (consonants != k && i <= j) {
          if (is_vowel(word[i]))
            characters[word[i] - 'a']--;
          else
            consonants--;

          i++;
        }
      }

      else {
        j++;

        if (j >= word.length())
          break;

        if (is_vowel(word[j]))
          characters[word[j] - 'a']++;
        else
          consonants++;
      }
    }
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string word;
    int k;

    cin >> word >> k;

    ll result = count_substrings(word, k);
    cout << result << '\n';
  }

  return 0;
}
