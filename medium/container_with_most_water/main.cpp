#include <bits/stdc++.h>
using namespace std;

// Thought It was a Monotonic Stack Problem, But turns out its a two pointer problem
int max_area(vector<int> &heights) {

  int n = heights.size(), area = 0;

  vector<int> st, dp(n, 0);

  st.push_back(0);

  auto bs = [&](int i) -> int {
    int l = 0, h = st.size() - 1, pos = i;

    while (l <= h) {
      int m = l + (h - l) / 2;

      if (heights[st[m]] >= heights[i]) {
        h = m - 1;
        pos = st[m];
      } else
        l = m + 1;
    }

    return pos;
  };

  // from left to right
  for (int i = 1; i < n; i++) {

    int j = bs(i);
    dp[i] = min(heights[i], heights[j]) * abs(i - j);

    if (heights[st.back()] < heights[i])
      st.push_back(i);
  }

  // from right to left
  st = vector<int>(0);
  st.push_back(n - 1);

  for (int i = n - 2; i >= 0; i--) {
    int j = bs(i);

    dp[i] = max(dp[i], min(heights[i], heights[j]) * abs(j - i));

    if (heights[st.back()] < heights[i])
      st.push_back(i);
  }

  for (int val : dp)
    area = max(area, val);

  return area;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++)
      cin >> heights[i];

    int area = max_area(heights);
    cout << area << endl;
  }

  return 0;
}
