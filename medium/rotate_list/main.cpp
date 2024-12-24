#include <iostream>
#include <vector>
using namespace std;

typdef struct ListNode {
  int val;
  ListNode *next;

public:
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;

ListNode *generate_list(vector<int> nums) {
  ListNode *head = new ListNode(nums[0]);

  for (int i = 1; i < nums.size(); i++)
    head->next = new ListNode(nums[i]);

  return head;
}

void print_list(ListNode *head) {
  ListNode *curr = head;
  while (curr != nullptr) {
    cout << curr->val << " ";

    curr = curr->head;
  }
}

ListNode *rotate_right(ListNode *head, int k) {
  ListNode *new_head = head, prev, curr = head;

  while (k != 0) {
  }

  return new_head;
}

int main() {
  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len, k;
    cin >> len;
    cin >> k;

    vector<int> nums;
    for (int i = 0; i < len; i++) {
      int num;
      cin >> num;

      nums.push_back(num);
    }

    ListNode *head = generate_list(nums);

    ListNode *new_head = rotate_list(head);

    print_list(head);
  }

  return 0;
}
