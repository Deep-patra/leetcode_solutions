#include <iostream>
#include <queue>
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

void preprocess_string(string t, queue<pair<int, int>> &q) {
  int level = 0, i = 0;
  string num = "";

  while (i < t.length()) {
    if (t[i] == '-') {
      if (num.length() != 0) {
        q.push(make_pair(level, stoi(num)));

        // reset the states
        level = 0;
        num = "";
      }

      level++;
    }

    else
      num.push_back(t[i]);

    i++;
  }

  if (num.length() != 0)
    q.push(make_pair(level, stoi(num)));
}

void generate_tree(TreeNode *root, queue<pair<int, int>> &q, int level = 0) {

  while (!q.empty()) {

    pair<int, int> front = q.front();

    if (level == front.first - 1) {
      if (root->left == nullptr) {
        root->left = new TreeNode(front.second);
        q.pop();

        generate_tree(root->left, q, level + 1);

      } else {
        root->right = new TreeNode(front.second);
        q.pop();

        generate_tree(root->right, q, level + 1);
      }
    }

    else
      break;
  }

  return;
}

// INFO: Solved, Beats 100% in runtime 😁
TreeNode *recover_from_preorder(string traversal) {
  queue<pair<int, int>> q;

  preprocess_string(traversal, q);

  pair<int, int> front = q.front();
  q.pop();

  TreeNode *root = new TreeNode(front.second);

  generate_tree(root, q);

  return root;
}

void print_tree(TreeNode *root) {
  if (root == nullptr) {
    cout << "null" << " ";
    return;
  }

  cout << root->val << " ";

  if (root->left == nullptr && root->right == nullptr)
    return;

  print_tree(root->left);
  print_tree(root->right);
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s;
    cin >> s;

    TreeNode *root = recover_from_preorder(s);

    print_tree(root);
    cout << '\n';
  }

  return 0;
}
