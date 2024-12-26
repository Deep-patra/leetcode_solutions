#include <iostream>
using namespace std;

int find_first_occurence(string haystack, string needle) {


}

int main() {
  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases --;

    string haystack, needle;
    cin >> haystack >> needle;

    int result = find_first_occurrences(haystack, needle);

    cout << result << '\n';
  }

  return 0;
}
