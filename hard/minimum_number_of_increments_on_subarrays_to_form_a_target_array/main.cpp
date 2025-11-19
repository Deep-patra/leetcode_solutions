#include <bits/stdc++.h>
using namespace std;

// Range minimum with segment tree
pair<int, int> tree[2 * 100001];

// INFO: Runtime is 26ms which is a lot slower than the res
// TOOD: Use a better data structure for range min queries, it might speed up the algorithm

void generate_tree(vector<int> &target) {

  int n = target.size();

  for (int i = 0; i < 2 * n; i++)
    tree[i] = {INT_MAX, -1};

  for (int i = 0; i < n; i++)
    tree[n + i] = {target[i], i};

  for (int i = n - 1; i > 0; i--) {
    if (tree[2 * i].first < tree[2 * i + 1].first)
      tree[i] = tree[2 * i];
    else
      tree[i] = tree[2 * i + 1];
  }
}

pair<int, int> query(int n, int l, int r) {

  l += n;
  r += n;

  pair<int, int> min_val = {INT_MAX, -1};

  while (l < r) {
    if (l & 1) {
      if (min_val.first > tree[l].first)
        min_val = tree[l];

      l++;
    }

    if (r & 1) {
      r--;

      if (min_val.first > tree[r].first)
        min_val = tree[r];
    }

    l >>= 1;
    r >>= 1;
  }

  return min_val;
}

int min_operations(int n, int l, int r, int elem) {

  if (l >= r)
    return 0;

  pair<int, int> min_val = query(n, l, r);

  int res = min_val.first - elem;

  res += min_operations(n, l, min_val.second, min_val.first);
  res += min_operations(n, min_val.second + 1, r, min_val.first);

  return res;
}

int min_number_operations(vector<int> &target) {
  int n = target.size();

  generate_tree(target);

  int res = min_operations(n, 0, n, 0);

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> target(n);
    for (int i = 0; i < n; i++)
      cin >> target[i];

    int res = min_number_operations(target);
    cout << res << endl;
  }

  return 0;
}
