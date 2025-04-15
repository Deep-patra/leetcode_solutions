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

// INFO: Solved
bool same_tree(TreeNode *p, TreeNode *q) {

  if (p == nullptr && q != nullptr || p != nullptr && q == nullptr)
    return false;

  if (p == nullptr && q == nullptr)
    return true;

  if (same_tree(p->left, q->left) && same_tree(p->right, q->right) &&
      p->val == q->val)
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
