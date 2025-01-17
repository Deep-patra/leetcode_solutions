#include <iostream>
#include <vector>
using namespace std;

#define mod 1000000007

int ways(vector<string> &pizza, int k) {

}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int len, k;
    cin >> len >> k;

    vector<string> pizza(len);
    for (int i = 0; i < len; i++)
      cin >> pizza[i];

    int result = ways(pizza, k);
    cout << result << '\n';
  }

  return 0;
}
