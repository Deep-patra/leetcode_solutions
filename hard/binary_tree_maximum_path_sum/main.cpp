#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

TreeNode *generate_tree(vector<int> &values, int idx = 0) {
  if (values.size() == 0 || idx >= values.size() || values[idx] == NULL)
    return nullptr;

  return new TreeNode(values[idx], generate_tree(values, 2 * idx + 1),
                      generate_tree(values, 2 * idx + 2));
}

// TODO: Works! But is a bit slow, Implement a efficient algorithm, than the current one.
void find_max_path_sum(unordered_map<TreeNode *, int> &m, TreeNode *root,
                       int &result) {
  if (root == nullptr)
    return;

  if (m.find(root) != m.end())
    return;

  int val = root->val;

  int res = val, max_val = INT_MIN;

  if (root->left != nullptr) {
    find_max_path_sum(m, root->left, result);

    max_val = max(max_val, m[root->left]);

    if (m[root->left] > 0)
      res += m[root->left];
  }

  if (root->right != nullptr) {
    find_max_path_sum(m, root->right, result);

    max_val = max(max_val, m[root->right]);

    if (m[root->right] > 0)
      res += m[root->right];
  }

  result = max(result, res);

  m[root] = max_val + val;

  return;
}

int max_path_sum(TreeNode *root) {
  unordered_map<TreeNode *, int> m;

  int result = INT_MIN;
  find_max_path_sum(m, root, result);

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> values(n);
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;

      values[i] = s == "null" ? NULL : stoi(s);
    }

    TreeNode *root = generate_tree(values);

    int result = max_path_sum(root);
    cout << result << '\n';
  }

  return 0;
}
