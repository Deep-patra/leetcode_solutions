#include <bits/stdc++.h>
using namespace std;

int find_num(vector<int> &arr, int target, int start = 0) {
  if (start >= arr.size())
    return -1;

  if (start == arr.size() - 1)
    return target == arr[arr.size() - 1] ? start : -1;

  int low = start, high = arr.size() - 1, mid;

  while (low <= high) {
    mid = low + (high - low) / 2;

    if (arr[mid] == target)
      return mid;

    if (arr[mid] < target)
      low = mid + 1;

    else if (arr[mid] > target)
      high = mid - 1;
  }

  return -1;
}

int length_longest_fib_subseq(vector<int> &arr) {
  int longest = 0;

  for (int i = 0; i < arr.size() - 2; i++) {

    if (arr[i] + arr[i + 1] > arr[arr.size() - 1])
      break;

    for (int j = i + 1; j < arr.size(); j++) {

      int first = arr[i], second = arr[j], curr_len = 0;
      int pos = find_num(arr, first + second, j + 1);

      while (pos != -1) {

        int temp = first;

        first = second;
        second = temp + second;

        curr_len = curr_len == 0 ? 3 : curr_len + 1;

        pos = find_num(arr, first + second, pos + 1);
      }

      longest = max(longest, curr_len);
    }
  }

  return longest;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> sequence(n, 0);
    for (int i = 0; i < n; i++)
      cin >> sequence[i];

    int result = length_longest_fib_subseq(sequence);
    cout << result << '\n';
  }

  return 0;
}
