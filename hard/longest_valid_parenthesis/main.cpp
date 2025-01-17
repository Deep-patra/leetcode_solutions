#include <iostream>
#include <vector>
using namespace std;

/**
  Approach 1: Using the prefix sum array.
**/
int longest_valid_parenthesis(string s) {
  if (s.length() == 0)
    return 0;


}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    string input;
    cin >> input;

    bool result = longest_valid_parenthesis(input);

    cout << result << '\n';
  }

  return 0;
}
