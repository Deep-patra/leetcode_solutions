#include <algorithm>
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
  if (index >= values.size() || values[index] == NULL)
    return nullptr;

  return new TreeNode(values[index], generate_tree(values, 2 * index + 1),
                      generate_tree(values, 2 * index + 2));
}

void binary_tree_paths_recurse(TreeNode *root, vector<string> &paths,
                               int index = 0) {

  if (paths.size() <= index) {
    paths.resize(index + 1);
    paths[index] = "";
  }

  paths[index] += to_string(root->val);

  if (root->left != nullptr && root->right == nullptr) {
    paths[index] += "->";

    binary_tree_paths_recurse(root->left, paths, index);
  }

  else if (root->left == nullptr && root->right != nullptr) {
    paths[index] += "->";

    binary_tree_paths_recurse(root->right, paths, index);
  }

  else if (root->left != nullptr && root->right != nullptr) {

    string s = paths[index];

    paths[index] += "->";
    binary_tree_paths_recurse(root->left, paths, index);

    paths.push_back(s);
    paths[paths.size() - 1] += "->";
    binary_tree_paths_recurse(root->right, paths, paths.size() - 1);
  }

  return;
}

vector<string> binary_tree_paths(TreeNode *root) {
  vector<string> result(0);

  binary_tree_paths_recurse(root, result);

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m;
    cin >> m;

    vector<int> values(m, NULL);
    for (int i = 0; i < m; i++) {
      string s;
      cin >> s;

      values[i] = s == "null" ? NULL : stoi(s);
    }

    TreeNode *root = generate_tree(values);
    vector<string> result = binary_tree_paths(root);

    for (string val : result)
      cout << val << " ";
    cout << '\n';
  }

  return 0;
}
