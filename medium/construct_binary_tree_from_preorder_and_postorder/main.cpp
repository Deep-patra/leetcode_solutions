#include <iostream>
#include <vector>
using namespace std;


typedef struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
} TreeNode;


pair<int, int> find_slice(vector<int> values, int l, int r) {
  pair<int, int> pos = { -1 , -1 };

  for (int i = 0; i < values.size(); i++) {
    if (l == values[i])
      pos.first = i + 1;

    if (r == values[i])
      pos.second = i - 1;
  }

  return pos;
}

void populate_node(TreeNode* root, vector<int> &preorder, vector<int> &postorder, pair<int, int> pre_slice, pair<int, int> post_slice) {
  
  // left node
  if (pre_slice.first <= pre_slice.second && pre_slice != -1) {
    root->left = new TreeNode(preorder[pre_slice.first]);

    pair<int, int> left_pre = find_slice(preorder[pre_slice.first], postorder[post_slice.second]);
    pair<int, int> left_post = find_slice(postorder[post_slice.first], preorder[pre_slice.first]);

    populate_node(root->left, preorder, postorder, left_pre, left_post);
  }
  // right node
  if (post_slice.first <= post_slice.second && post_slice != -1) {
    root->right = new TreeNode(postorder[post_slice.second]);

    pair<int, int> right_pre = find_slice(postorder[post_slice.second], preorder[pre_slice.second]);
    pair<int, int> right_post = find_slice(preorder[pre_slice.first], postorder[post_slice.second]);

    populate_node(root->right, preorder, postorder, right_pre, right_post);
  }
}

TreeNode* construct_from_prepost(vector<int> &preorder, vector<int> &postorder) {
  // get the root
  TreeNode* root = new TreeNode(preorder[0]);

  populate_node(root, preorder, postorder, make_pair(1, preorder.size() - 1), make_pair(0, postordser.size() - 2));

  return root;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<int> preorder(n, 0);
    for (int i = 0; i < n; i++)
      cin >> preorder[i];

    vector<int> postorder(n, 0);
    for (int i = 0; i < n; i++)
      cin >> postorder[i];


    TreeNode* root = construct_from_prepost(preorder, postorder);
  }

  return 0;
}
