#include <iostream>
#include <set>
#include <vector>
using namespace std;

// INFO: has a runtime of 17ms
vector<int> find_the_prefix_common_array(vector<int> &A, vector<int> &B) {
  vector<int> result(A.size(), 0);
  set<int> s;

  for (int i = 0; i < A.size(); i++) {
    s.insert(A[i]);

    for (int j = 0; j <= i; j++) {

      if (s.find(B[j]) != s.end()) {
        result[i]++;
      }
    }
  }

  return result;
}

bool A_memo[51], B_memo[51];

// TODO: Implement a 0ms runtime algorithm
//
// INFO: Reached 7 ms runtime with this approach (can reach 0ms with bitmask
// technique bcoz the input "n" cannot be greater than 50)
vector<int> find_the_prefix_common_array_optimized(vector<int> &A,
                                                   vector<int> &B) {
  vector<int> result(A.size(), 0);

  memset(A_memo, 0, sizeof(A_memo));
  memset(B_memo, 0, sizeof(B_memo));

  A_memo[A[0]] = 1;
  B_memo[B[0]] = 1;

  if (A[0] == B[0])
    result[0] = 1;
  for (int i = 1; i < A.size(); i++) {
    A_memo[A[i]] = 1;
    B_memo[B[i]] = 1;

    result[i] += result[i - 1];

    if (A[i] == B[i]) {
      result[i]++;
      continue;
    }

    if (A_memo[B[i]])
      result[i]++;

    if (B_memo[A[i]])
      result[i]++;
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int len;
    cin >> len;

    vector<int> A(len, 0), B(len, 0);
    for (int i = 0; i < len; i++)
      cin >> A[i];

    for (int i = 0; i < len; i++)
      cin >> B[i];

    vector<int> result = find_the_prefix_common_array_optimized(A, B);

    for (int val : result)
      cout << val << " ";
    cout << '\n';
  }

  return 0;
}
