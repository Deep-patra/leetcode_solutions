#include <iostream>
#include <vector>
using namespace std;

int peak_index_mountain_array(vector<int> &arr) {
  int low = 0, high = arr.size() - 1, mid, peak = 0;

  while (low < high) {
    mid = low + (high - low) / 2;


    if (arr[peak] < arr[mid])
      peak = mid;

    if (mid > 0 && arr[mid - 1] < arr[mid])
      low = mid + 1;

    else if (mid < arr.size() - 1 && arr[mid] > arr[mid + 1])
      high = mid;
  }

  return peak;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
      cin >> arr[i];

    int result = peak_index_mountain_array(arr);
    cout << result << endl;
  }

  return 0;
}
