// TODO: Complete the Implementation

#include <iostream>
#include <vector>
using namespace std;

typedef struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

public:
  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
} Treenode;

void print_tree(TreeNode* root) {

}

TreeNode* generate_tree(vector<int> &values) {

}

int minimum_operations(TreeNode* root) {
  
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases --;

    int len;
    cin >> len;

    vector<int> nums;
    for (int i = 0; i < len; i++) {
      int num;
      cin >> num;

      nums.push_back(num);
    }

    TreeNode* root = generate_tree(nums);

    minimum_operations(root);

    print_tree(root);
  }

  return 0;
}
