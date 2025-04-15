#include <iostream>
#include <vector>
using namespace std;

int rabbits[1001];

int num_rabbits(vector<int> &answers) {

  memset(rabbits, 0, sizeof(rabbits));

  int result = 0;
  for (int i = 0; i < answers.size(); i++) {
    ++rabbits[answers[i]];

    if (answers[i] + 1 < rabbits[answers[i]]) {
      result += answers[i] + 1;

      rabbits[answers[i]] = 1;
    }
  }

  for (int i = 0; i < 1001; i++)
    if (rabbits[i] > 0)
      result += (i + 1);

  return result;
}

int main() {
  int t;
  cin >> t;

  while ( t > 0 ) {
    t --;

    int n;
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int result = num_rabbits(nums);
    cout << result << '\n';
  }

  return 0;
}
