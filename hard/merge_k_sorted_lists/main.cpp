#include <iostream>
#include <vector>
using namespace std;

typedef struct ListNode {
  int val;
  ListNode *next;

public:
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;

ListNode *merge_k_lists(vector<ListNode *> &lists) {}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len;
    cin >> len;

    vector<vector<int>> list(len, vector());
  }

  return 0;
}
