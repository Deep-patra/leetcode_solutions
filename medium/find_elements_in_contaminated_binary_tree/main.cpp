#include <assert.h>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

typedef struct TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
} TreeNode;

TreeNode *generate_root(vector<int> values, int index = 0);

class FindElements {
  set<int> values;

private:
  void initialize_values(TreeNode *root, int value = 0) {
    if (root == nullptr)
      return;

    values.insert(value);

    initialize_values(root->left, 2 * value + 1);
    initialize_values(root->right, 2 * value + 2);
  }

public:
  FindElements(TreeNode *root) { initialize_values(root); }

  bool find(int target) {
    if (values.find(target) != values.end())
      return true;

    return false;
  }
};

int main() {
  vector<int> values = {-1, NULL, -1};

  TreeNode *root = generate_root(values);

  FindElements f(root);

  assert(f.find(1) == false);
  assert(f.find(2) == true);

  return 0;
}

TreeNode *generate_root(vector<int> values, int index) {
  if (index >= values.size() || values[index] == NULL)
    return nullptr;

  return new TreeNode(values[index], generate_root(values, 2 * index + 1),
                      generate_root(values, 2 * index + 2));
}
