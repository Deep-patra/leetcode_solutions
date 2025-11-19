#include <bits/stdc++.h>  
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

TreeNode* generate_tree(vector<int> &nums, int idx = 0) {
  if (nums.size() == 0 || idx >= nums.size() || nums[idx] == NULL)
    return nullptr;

  return new TreeNode(nums[idx], generate_tree(nums, 2 * idx + 1), generate_tree(nums, 2 * idx + 2));
}

void find_max(TreeNode* curr, unordered_map<TreeNode*, int> &m1, unordered_map<TreeNode*, int> &m2) {
  
  if (curr == nullptr) return;

  int v = curr->val, w = 0;

  if (curr->left != nullptr) {
    find_max(curr->left, m1, m2);

    v += m2[curr->left];
    w += m1[curr->left];
  }

  if (curr->right != nullptr) {
    find_max(curr->right, m1, m2);

    v += m2[curr->right];
    w += m1[curr->right];
  }

  m2[curr] = max(m2[curr], w);
  m1[curr] = max(m1[curr], v);
}

// INFO: Needs to reach 0ms but getting 10ms runtime
// Dunno if using stack instead of recursion can improve the runtime
// But worth a try!
// 
// TODO: Complete the Implementation
int rob(TreeNode* root) {
  unordered_map<TreeNode*, int> m1, m2;

  find_max(root, m1, m2);

  return max(m1[root], m2[root]);
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++) {
      string s;
      cin >> s;

      nums[i] = s == "null" ? NULL : stoi(s);
    }

    TreeNode* root = generate_tree(nums);
    int res = rob(root);

    cout << res << endl;
  }

  return 0;
}
