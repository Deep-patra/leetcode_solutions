#include <iostream>
#include <vector>
using namespace std;

// FIX: Optimize the algorithm for time limit
int max_score_sight_seeing_pair(vector<int> &values) {
  int result = INT_MIN;

  for (int i = 0; i < values.size(); i++)
    for (int j = i + 1; j < values.size(); j++)
      result = max(result, values[i] + values[j] + (i - j));

  return result;
}

// INFO: Copied from the solutions
int max_score_sight_seeing_pair(vector<int> &values) {
  int n = values.size();
  // Initialize an array to store the maximum left scores up to each
  // index.
  vector<int> maxLeftScore(n);
  // The left score at the first index is just the value of the first
  // element.
  maxLeftScore[0] = values[0];

  int maxScore = 0;

  for (int i = 1; i < n; i++) {
    int currentRightScore = values[i] - i;
    // Update the maximum score by combining the best left score so far
    // with the current right score.
    maxScore = max(maxScore, maxLeftScore[i - 1] + currentRightScore);

    int currentLeftScore = values[i] + i;
    // Update the maximum left score up to the current index.
    maxLeftScore[i] = max(maxLeftScore[i - 1], currentLeftScore);
  }

  return maxScore;
}

int max_score_sight_seeing_pair_2(vector<int> &values) {
  int result = INT_MIN;

  vector<int> diff1(values.size(), INT_MIN);
  for (int i = 0; i < values.size(); i++)
    diff1[i] = values[i] - i;

  vector<int> diff2(values.size(), INT_MIN);
  for (int j = 0; j < values.size(); j++)
    diff2[j] = values[j] + j;

  // find the max index in the diff1 except the 0 index
  int index = 1;
  int greatest = diff1[index];
  for (int i = 1; i < values.size(); i++) {
    if (greatest < diff1[i]) {
      greatest = diff1[i];
      index = i;
    }
  }

  // find the largest in the diff2 array
  int maximum = diff2[0];
  for (int i = 0; i < index; i++)
    maximum = max(maximum, diff2[i]);

  result = maximum + greatest;

  return result;
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len;
    cin >> len;

    vector<int> values(len, 0);
    for (int i = 0; i < len; i++)
      cin >> values[i];

    int result = max_score_sight_seeing_pair(values);

    cout << result << "\n";
  }

  return 0;
}
