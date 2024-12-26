#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct TreeNode {

  int val;
  TreeNode *left;
  TreeNode *right;

public:
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right) {}

  static TreeNode *from_vector(vector<int> list);
} TreeNode;

void inorder(TreeNode *root, vector<int> &list) {

  if (root == nullptr)
    return;

  inorder(root->left, list);

  list.push_back(root->val);

  inorder(root->right, list);
}

vector<int> inorder_traversal(TreeNode *root) {
  vector<int> list;

  inorder(root, list);

  return list;
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len;
    cin >> len;

    vector<int> values(len, NULL);
    for (int i = 0; i < len; i++) {
      string num;
      cin >> num;

      if (num == "null")
        values[i] = NULL;
      else
        values[i] = stoi(num);
    }

    for (auto val : values)
      cout << val << ' ';

    cout << '\n';

    TreeNode *root = TreeNode::from_vector(values);

    vector<int> result = inorder_traversal(root);

    for (auto val : result)
      cout << val << ' ';

    cout << '\n';
  }

  return 0;
}

TreeNode *generate_tree(vector<int> list, int index = 0) {
  if (index >= list.size() || list[index] == NULL)
    return nullptr;

  return new TreeNode(list[index], generate_tree(list, 2 * index + 1),
                      generate_tree(list, 2 * index + 2));
}

void print_tree(TreeNode *root) {}

TreeNode *TreeNode::from_vector(vector<int> list) {
  if (list.size() == 0)
    return nullptr;

  TreeNode *root = generate_tree(list);

  return root;
}
