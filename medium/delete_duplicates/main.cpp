#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *delete_duplicates(ListNode *head) {

  if (head == nullptr)
    return nullptr;

  ListNode *new_curr = nullptr, *new_head = nullptr, *curr = head;

  while (curr != nullptr) {

    if (curr->next != nullptr && curr->val == curr->next->val) {
      // repeating values
      int rep = curr->val;

      while (curr != nullptr && curr->val == rep)
        curr = curr->next;

      continue;
    }

    if (new_head == nullptr) {
      new_head = curr;
      new_curr = new_head;
    } else {
      new_curr->next = curr;
      new_curr = new_curr->next;
    }

    curr = curr->next;
  }

  if (new_curr != nullptr)
    new_curr->next = nullptr;

  return new_head;
}

ListNode *generate_list(vector<int> &list) {
  if (list.size() == 0)
    return nullptr;

  ListNode *head = new ListNode(list[0]);
  ListNode *curr = head;

  for (int i = 1; i < list.size(); i++) {
    curr->next = new ListNode(list[i]);
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

  cout << endl;
}

int main() {
  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len;
    cin >> len;

    vector<int> list(len);
    for (int i = 0; i < len; i++)
      cin >> list[i];

    ListNode *head = generate_list(list);
    ListNode *new_head = delete_duplicates(head);

    print_list(new_head);
  }

  return 0;
}
