#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}

  static TreeNode *generate_tree(vector<int> values, int index = 0);
};

int tree_depth(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }

  return max(1 + tree_depth(root->left), 1 + tree_depth(root->right));
}

vector<int> largest_values(TreeNode *root) {

  if (root == nullptr)
    return vector<int>(0);

  queue<pair<TreeNode *, int>> levels;

  int depth = tree_depth(root);

  levels.push({root, 0});

  vector<int> result(depth, INT_MIN);
  while (!levels.empty()) {

    pair<TreeNode *, int> front = levels.front();
    levels.pop();

    result[front.second] = max(result[front.second], front.first->val);

    if (front.first->left != nullptr)
      levels.push({front.first->left, front.second + 1});

    if (front.first->right != nullptr)
      levels.push({front.first->right, front.second + 1});
  }

  return result;
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len;
    cin >> len;

    vector<int> values;
    for (int i = 0; i < len; i++) {
      string num;
      cin >> num;

      if (num == "null")
        values.push_back(NULL);
      else
        values.push_back(stoi(num));
    }

    TreeNode *root = TreeNode::generate_tree(values);

    vector<int> result = largest_values(root);

    for (auto val : result)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}

TreeNode *TreeNode::generate_tree(vector<int> values, int index) {
  if (values.size() == 0 || index >= values.size() || values[index] == NULL)
    return nullptr;

  return new TreeNode(values[index], generate_tree(values, 2 * index + 1),
                      generate_tree(values, 2 * index + 2));
}
