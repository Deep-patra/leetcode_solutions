#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

double my_pow(double x, int n) {
  double result = 1.0;

  if (x == 1.0)
    return 1.0;

  if (n < 0) {
    for (int i = 0; i < abs(n); i++)
      result *= (1 / x);
  } else {
    for (int i = 0; i < n; i++)
      result *= x;
  }

  return result;
}

int main() {
  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    double x;
    int n;

    cin >> x >> n;

    double result = my_pow(x, n);
    cout << fixed << setprecision(5) << result << '\n';
  }

  return 0;
}
