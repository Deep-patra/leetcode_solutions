#include <iostream>
#include <stack>
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

  static TreeNode *generate(vector<int> values);
} TreeNode;

TreeNode *generate_recurse(vector<int> values, int index = 0) {
  if (index >= values.size())
    return nullptr;

  if (values[index] == NULL)
    return nullptr;

  return new TreeNode(values[index], generate_recurse(values, 2 * index + 1),
                      generate_recurse(values, 2 * index + 2));
}

TreeNode *TreeNode::generate(vector<int> values) {
  if (values.size() == 0)
    return nullptr;

  return generate_recurse(values);
}

void inorder_recurse(TreeNode *root, vector<int> &result) {
  if (root == nullptr)
    return;

  inorder_recurse(root->left, result);

  result.push_back(root->val);

  inorder_recurse(root->right, result);
}

// Inorder Traversal for the Binary tree
vector<int> inorder_traversal(TreeNode *root) {
  vector<int> result;

  inorder_recurse(root, result);

  return result;
}

// Inorder Traversal Iteratively for the Binary tree
vector<int> inorder_traversal_iterative(TreeNode *root) {
  vector<int> result;

  stack<TreeNode *> s;
  s.push(root);

  while (!s.empty()) {
    auto front = s.top();
    s.pop();
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len;
    cin >> len;

    vector<int> values(len);
    for (int i = 0; i < len; i++) {
      string val;
      cin >> val;
      values[i] = val == "null" ? NULL : stoi(val);
    }

    TreeNode *root = TreeNode::generate(values);
    vector<int> result = inorder_traversal(root);

    for (auto val : result)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}
