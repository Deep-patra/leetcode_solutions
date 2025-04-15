#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* generate_tree(vector<in> &values, int index = 0) {
  if (values.size() == 0 || index >= values.size() || values[index] == NULL)
    return nullptr;

  return new TreeNode(values[index], generate_tree(values, 2 * index + 1), generate_tree(values, 2 * index + 2));
}

int find_depth(TreeNode* root) {
  if (root == nullptr) return 0;
  return 1 + max(find_depth(root->left), find_depth(root->right));
}

// INFO: Beats 100%, 0ms Runtime
TreeNode* find_lca(TreeNode* root, int depth, int curr_depth = 1) {
  if (root == nullptr) return nullptr;

  if (curr_depth == depth)
    return root;

  TreeNode* left_lca = find_lca(root->left, depth, curr_depth + 1);
  TreeNode* right_lca = find_lca(root->right, depth, curr_depth + 1);

  if (left_lca != nullptr && right_lca != nullptr)
    return root;

  return left_lca != nullptr ? left_lca : right_lca;
}

TreeNode* lca_deepest_leaves(TreeNode* root) {
  // find the depth of the tree
  int depth = find_depth(root);

  TreeNode* lca = find_lca(root, depth);

  return lca;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<int> values(n);
    for (int i = 0; i < n; i ++)
      cin >> values[i];

    TreeNode* root = generate_tree(values);

  }

  return 0;
}
