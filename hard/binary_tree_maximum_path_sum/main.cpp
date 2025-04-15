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
  if (idx >= values.size() && values[idx] == NULL)
    return nullptr;

  return new TreeNode(values[idx], generate_tree(values, 2 * idx + 1),
                      generate_tree(values, 2 * idx + 2));
}

int find_max_path_sum(unordered_map<TreeNode *, int> &m, TreeNode *root,
                      int &result) {
  if (root == nullptr)
    return 0;

  int val = root->val;

  if (root->left != nullptr)
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
    for (int i = 0; i < n; i++)
      cin >> values[i];

    TreeNode *root = generate_tree(values);

    int result = max_path_sum(root);
    cout << result << '\n';
  }

  return 0;
}
