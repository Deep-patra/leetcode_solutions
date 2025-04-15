#include <iostream>
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

// FIX: Incorrect Implementation
bool is_same(TreeNode *root1, TreeNode *root2) {
  if (root1 == nulltpr && root2 != nullptr ||
      root1 != nullptr && root2 == nullptr)
    return false;

  if (root1 == nullptr && root2 == nullptr)
    return true;

  else if (root1->val == root2->val && is_same(root1->left, root2->left) &&
           is_same(root1->right, root2->right))
    return true;

  return false;
}

bool is_symmetric(TreeNode *root) {
  if (root->left == nullptr && root->right != nullptr ||
      root->left != nullptr && root->right == nullptr)
    return false;

  if (is_same(root->left, root->right))
    return true;

  return false;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;
  }

  return 0;
}
