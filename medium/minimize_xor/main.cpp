#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// INFO: WELL DONE! Oms runtime
int minimize_xor(int num1, int num2) {
  // number of set bits in the num2
  int set_bits = 0, temp = num2;
  while (temp > 0) {
    if (temp & 1)
      set_bits++;

    temp = temp >> 1;
  }

  // find the position of the set bits in the num1
  stack<int> s;
  int count = 0;

  for (int i = 0; i < 32; i++)
    if (num1 & 1 << i) {
      s.push(i);
      count++;
    }

  int result = 0;

  while (!s.empty() && set_bits > 0) {
    int pos = s.top();
    s.pop();

    result = result | 1 << pos;
    set_bits--;
  }

  // set_bits is not zero, then set the lowest zero in the result
  if (set_bits > 0) {
    int pos = 0;
    while (set_bits > 0 && pos < 32) {
      if (!(result & 1 << pos)) {
        result = result | 1 << pos;
        set_bits--;
      }

      pos++;
    }
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int num1, num2;
    cin >> num1 >> num2;

    int result = minimize_xor(num1, num2);
    cout << result << '\n';
  }

  return 0;
}
