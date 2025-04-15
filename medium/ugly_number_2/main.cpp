#include <iostream>
#include <vector>
#include <set>
using namespace std;

// TODO: Implement the algorithm
int nth_ugly_number(int n) {

}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    int result = nth_ugly_number(n);
    cout << result << '\n';
  }

  return 0;
}
