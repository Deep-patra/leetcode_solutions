#include <iostream>
#include <vector>
using namespace std;

// TODO: Optimise the algorithm
vector<int> min_operations(string boxes) {
  vector<int> result(boxes.size(), 0), left(boxes.size(), 0),
      right(boxes.size(), 0);

  for (int i = 1; i < boxes.size(); i++) {
    if (boxes[i - 1] == '1')
      left[i] += left[i - 1] + 1;
    else
      left[i] += left[i - 1];
  }

  cout << "Left => ";
  for (int val : left)
    cout << val << " ";
  cout << "\n";

  for (int i = boxes.size() - 2; i <= 0; i--) {
    if (boxes[i + 1] == '1')
      right[i] += right[i + 1] + 1;
    else
      right[i] += right[i + 1];
  }

  cout << "Right => ";
  for (int val : right)
    cout << val << " ";
  cout << "\n";

  for (int i = 0; i < boxes.size(); i++)
    if (boxes[i] == '1')
      result[i] = left[i] + right[i];

  return result;
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    string boxes;
    cin >> boxes;

    vector<int> result = min_operations(boxes);

    for (auto val : result)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}
