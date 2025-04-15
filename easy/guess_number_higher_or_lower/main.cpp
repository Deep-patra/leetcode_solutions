#include <iostream>
#include <vector>
using namespace std;

int guess(int n) {

}

int guess_number(int n) {
  int low = 0, high = n, mid;

  while ( low <= high ) {
    mid = low + ( high - low ) / 2;

    int g = guess(mid);

    if (g == 0)
      break;

    else if (g == 1)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return mid;
}

int main() {
  int t;
  cin >> t;

  while ( t > 0 ) {
    t --;

    int n, pick;
    cin >> n >> pick;

    int result = guess_number(n);
    cout << result << '\n';
  } 

  return 0;
}
