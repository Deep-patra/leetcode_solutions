#include <iostream>
#include <string>
using namespace std;

string count_and_say(int n) {
  if (n == 1)
    return "1";

  string result = "";
  string rle = count_and_say(n - 1);

  char character = rle[0]; // current character
  int occurences = 1;      // occurences of the current character

  int i = 1; // current index
  while (i <= rle.length()) {

    if (i == rle.length()) {
      result += to_string(occurences) + character;
      break;
    }

    if (character == rle[i])
      occurences++;

    if (character != rle[i]) {
      result += to_string(occurences) + character;
      character = rle[i];
      occurences = 1;
    }

    i++;
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

    int num;
    cin >> num;

    string result = count_and_say(num);
    cout << result << '\n';
  }

  return 0;
}
