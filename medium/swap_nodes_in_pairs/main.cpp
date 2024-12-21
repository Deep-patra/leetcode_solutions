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

ListNode *generate_list_node(vector<int> &nums) {
  if (nums.size() == 0)
    return nullptr;

  ListNode *head = new ListNode(nums[0]);

  ListNode *curr = head;
  for (int i = 1; i < nums.size(); i++) {
    curr->next = new ListNode(nums[i]);
    curr = curr->next;
  }

  return head;
}

vector<int> generate_list(ListNode *head) {
  ListNode *curr = head;

  vector<int> list = {};
  while (curr != nullptr) {
    list.push_back(curr->val);
    curr = curr->next;
  }

  return list;
}

ListNode *swap_pairs(ListNode *head) {

  // Edge cases
  if (head == nullptr || head->next == nullptr)
    return head;

  ListNode *curr = head, *prev = nullptr;
  ListNode *new_head = head->next;

  while (curr != nullptr && curr->next != nullptr) {
    ListNode *first = curr;
    ListNode *second = curr->next;

    ListNode *temp = second->next;
    second->next = first;
    first->next = temp;

    if (prev != nullptr)
      prev->next = second;

    prev = first;
    curr = temp;
  }

  return new_head;
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len;
    cin >> len;

    vector<int> nums = {};
    for (int i = 0; i < len; i++) {
      int num;
      cin >> num;

      nums.push_back(num);
    }

    ListNode *head = generate_list_node(nums);
    head = swap_pairs(head);

    vector<int> list = generate_list(head);

    for (int val : list)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}
