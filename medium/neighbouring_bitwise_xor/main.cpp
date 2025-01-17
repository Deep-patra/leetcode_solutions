#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// TODO: Implement a better 0ms runtime solution

// INFO: 12ms runtime
bool does_valid_array_exists(vector<int> &derived) {
  int len = derived.size();

  vector<int> result(len);

  // when the first element is 0 in the result
  result[0] = 0;

  int i = 0;
  while (i < len) {
    if (i == len - 1) {
      if (derived[i] == (result[0] ^ result[i]))
        return true;
      else
        break;
    } else
      result[i + 1] = derived[i] ^ result[i];

    i++;
  }

  // when the first element is 1 in the result
  i = 0;
  result[0] = 1;

  while (i < len) {
    if (i == len - 1) {
      if (derived[i] == (result[0] ^ result[i]))
        return true;
      else
        break;
    } else
      result[i + 1] = derived[i] ^ result[i];
    i++;
  }

  return false;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int len;
    cin >> len;

    vector<int> derived(len);
    for (int i = 0; i < len; i++)
      cin >> derived[i];

    bool result = does_valid_array_exists(derived);
    cout << result << '\n';
  }

  return 0;
}
