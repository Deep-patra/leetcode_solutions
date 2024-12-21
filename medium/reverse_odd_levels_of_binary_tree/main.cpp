#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

public:
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}

  vector<int> generate_vector();
} TreeNode;

TreeNode *generate_tree(vector<int> &nums, int index = 0);

int tree_depth(TreeNode *root) {
  if (root->left == nullptr)
    return 1;

  return 1 + tree_depth(root->left);
}

TreeNode *reverse_odd_levels(TreeNode *root) {
  queue<pair<TreeNode *, int>> q;

  int depth = tree_depth(root);

  vector<vector<TreeNode *>> nodes;
  nodes.resize(depth + 1);

  q.push(make_pair(root, 1));

  // put the nodes corresponding to their levels
  while (!q.empty()) {
    auto front = q.front();
    q.pop();

    nodes[front.second].push_back(front.first);

    if (front.first->left != nullptr) {
      q.push(make_pair(front.first->left, front.second + 1));
      q.push(make_pair(front.first->right, front.second + 1));
    }
  }

  // Swap the node values in the even level of the tree
  for (int level = 1; level <= depth; level++) {

    if (level % 2 == 0) {
      vector<TreeNode *> level_nodes = nodes[level];

      int size = level_nodes.size() - 1;
      for (int i = 0; i <= size / 2; i++) {
        int temp = level_nodes[i]->val;
        level_nodes[i]->val = level_nodes[size - i]->val;
        level_nodes[size - i]->val = temp;
      }
    }
  }

  return root;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int test_cases = 0;
  cin >> test_cases;

  while (test_cases > 0) {
    test_cases--;

    int len = 0;
    cin >> len;

    vector<int> nums;
    for (int i = 0; i < len; i++) {
      int num = 0;
      cin >> num;

      nums.push_back(num);
    }

    TreeNode *tree = generate_tree(nums);
    TreeNode *reverse_tree = reverse_odd_levels(tree);

    vector<int> values = reverse_tree->generate_vector();
    for (auto val : values)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}

vector<int> TreeNode::generate_vector() {
  queue<TreeNode *> q;
  q.push(this);

  vector<int> nums;
  while (!q.empty()) {
    TreeNode *top = q.front();
    q.pop();

    nums.push_back(top->val);

    if (top->left != nullptr)
      q.push(top->left);

    if (top->right != nullptr)
      q.push(top->right);
  }

  return nums;
}

TreeNode *generate_tree(vector<int> &nums, int index) {
  if (index >= nums.size())
    return nullptr;

  TreeNode *root = new TreeNode(nums[index]);

  root->left = generate_tree(nums, 2 * index + 1);
  root->right = generate_tree(nums, 2 * index + 2);

  return root;
}
