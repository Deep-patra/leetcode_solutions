#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* generate_tree(vector<int> &nums, int i = 0) {
  if (nums.size() == 0 || i >= nums.size() || nums[i] == NULL)
    return nullptr;

  return new TreeNode(nums[i], generate_tree(nums, 2 * i + 1), generate_tree(nums, 2 * i + 2));
}

TreeNode* lowest_common_ancestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (root == nullptr) return nullptr;

  if (root->val == p->val || root->val == q->val)
    return root;

  TreeNode* left_lca = lowest_common_ancestor(root->left, p, q);
  TreeNode* right_lca = lowest_common_ancestor(root->right, p, q);

  if (left_lca && right_lca)
    return root;

  return left_lca ? left_lca : right_lca;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, p, q;
    cin >> n >> p >> q;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++) {
      string s;
      cin >> s;

      nums[i] = s == "null" ? NULL : stoi(s);
    }

    TreeNode* root = generate_tree(nums);
    TreeNode* p_node = new TreeNode(p);
    TreeNode* q_node = new TreeNode(q);

    TreeNode* res = lowest_common_ancestor(root, p, q);
    cout << res-> val << endl;
  }

  return 0;
}
