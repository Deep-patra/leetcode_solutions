#include <iostream>
#include <vector>
using namespace std;



int find_kth_positive(vector<int> &arr, int k) {
  if (k > (arr[arr.size() - 1] - arr.size())) 
    return arr[arr.size() - 1] + k;

  int low = 0, high = arr.size() - 1;

  while (low < high) {
    int mid = low + (high - low) / 2;

    if (missing_positive(arr, l, mid))
  }
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int k, len;
    cin >> len >> k;

    vector<int> arr(len);
    for (int i = 0; i < len; i++)
      cin >> arr[i];

    int result = find_kth_positive(arr, k);
    cout << result << '\n';
  }

  return 0;
}
