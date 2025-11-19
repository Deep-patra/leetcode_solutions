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

TreeNode *generate_tree(vector<int> &nums, int index = 0) {
  if (nums.size() == 0 || index >= nums.size())
    return nullptr;

  return new TreeNode(nums[index], generate_tree(nums, 2 * index + 1),
                      generate_tree(nums, 2 * index + 2));
}

int depth(TreeNode *root) {
  if (root == nullptr)
    return 0;
  return 1 + max(depth(root->left), depth(root->right));
}

bool is_present(TreeNode *root, int val, int depth) {
  if (root == nullptr)
    return false;

  if (root->val == val)
    return true;

  int curr_val = val / pow(2, depth - 1);

  if (curr_val & 1)
    return is_present(root->right, val, depth - 1);

  else
    return is_present(root->left, val, depth - 1);
}

// TODO: This algorithm depends on the value of the Tree nodes
// which is resulting in the WA, fix this.
int count_nodes(TreeNode *root) {

  int d = depth(root);

  if (d < 2)
    return d;

  int l = 0, h = pow(2, d - 1), mid, nodes;

  while (l <= h) {
    mid = l + (h - l) / 2;

    if (is_present(root, (pow(2, d - 1) - 1) + mid, d - 1)) {
      l = mid + 1;
      nodes = mid;
    } else
      h = mid - 1;
  }

  return nodes + (pow(2, d - 1) - 1);
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    TreeNode *root = generate_tree(nums);

    int result = count_nodes(root);
    cout << result << '\n';
  }

  return 0;
}
