#include <deque>
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

ListNode *generate_list(vector<int> nums) {
  ListNode *head = new ListNode(nums[0]);

  ListNode *curr = head;
  for (int i = 1; i < nums.size(); i++) {
    curr->next = new ListNode(nums[i]);
    curr = curr->next;
  }

  return head;
}

void print_list(ListNode *head) {
  ListNode *curr = head;
  while (curr != nullptr) {
    cout << curr->val << " ";

    curr = curr->next;
  }

  cout << '\n';
}

// FIX: Optimize the algorithm for Time Limit Exceeded
ListNode *rotate_list(ListNode *head, int k) {
  if (head == nullptr)
    return nullptr;

  deque<ListNode *> dq;

  ListNode *curr = head;
  while (curr != nullptr) {
    dq.push_back(curr);
    curr = curr->next;
  }

  // rotate the deque
  for (int i = 0; i < k; i++) {
    // pop the item from the back and push it on the front
    ListNode *temp = dq.back();
    dq.pop_back();
    dq.push_front(temp);
  }

  ListNode *new_head = dq.front();
  dq.pop_front();

  ListNode *current_node = new_head;
  while (!dq.empty()) {
    current_node->next = dq.front();
    dq.pop_front();

    current_node = current_node->next;
  }

  current_node->next = nullptr;

  return new_head;
}

int main() {
  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len, k;
    cin >> len >> k;

    vector<int> nums(len, 0);
    for (int i = 0; i < len; i++)
      cin >> nums[i];

    ListNode *head = generate_list(nums);

    ListNode *new_head = rotate_list(head, k);

    print_list(new_head);
  }

  return 0;
}
