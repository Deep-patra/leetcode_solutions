#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
} TreeNode;

TreeNode *generate_tree(vector<int> values, int index = 0) {
  if (values.size() == 0 || index >= values.size() || values[index] == NULL)
    return nullptr;

  return new TreeNode(values[index], generate_tree(values, 2 * index + 1),
                      generate_tree(values, 2 * index + 2));
}

bool path_sum_recurse(TreeNode *root, int target_sum, int curr = 0) {
  if (root == nullptr)
    return false;

  curr += root->val;

  if (root->left == nullptr && root->right == nullptr && curr == target_sum)
    return true;

  else if (path_sum_recurse(root->left, target_sum, curr) ||
           path_sum_recurse(root->right, target_sum, curr))
    return true;

  return false;
}

bool has_path_sum(TreeNode *root, int target_sum) {
  return path_sum_recurse(root, target_sum);
}

int main() {
  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len, target_sum;
    cin >> len >> target_sum;

    vector<int> values(len);
    for (int i = 0; i < len; i++) {
      string val;
      cin >> val;

      values[i] = val == "null" ? NULL : stoi(val);
    }

    TreeNode *root = generate_tree(values);
    bool result = has_path_sum(root, target_sum);

    cout << result << '\n';
  }

  return 0;
}
