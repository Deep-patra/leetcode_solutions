#include <iostream>
#include <vector>
using namespace std;

char next_greater_letter(vector<char> &letters, char target) {

  // if the last character is smaller than the target
  // return the first character in the letters array
  if (letters[letters.size() - 1] <= target)
    return letters[0];

  int low = 0, high = letters.size() - 1;

  while (low < high) {
    int mid = low + (high - low) / 2;

    if (letters[mid] <= target)
      low = mid + 1;

    else if (letters[mid] > target)
      high = mid;
  }

  return letters[low];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    char target;
    int len;

    cin >> len >> target;

    vector<char> letters(len);
    for (int i = 0; i < len; i++)
      cin >> letters[i];

    char result = next_greater_letter(letters, target);
    cout << result << '\n';
  }

  return 0;
}
