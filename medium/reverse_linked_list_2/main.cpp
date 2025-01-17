#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverse_between(ListNode *head, int left, int right) {
  stack<ListNode *> node_stack;

  int pos = 1;
  ListNode *prev = nullptr, *new_head = nullptr, *curr = head;

  while (curr != nullptr) {
    if (pos == left)
      prev = curr;

    if (pos >= left && pos <= right)
      node_stack.push(curr);

    curr = curr->next;
    pos++;
  }

  curr = node_stack.top();
  node_stack.pop();
  prev->next = curr;

  ListNode *end = curr->next;

  while (!node_stack.empty()) {
    ListNode *top = node_stack.top();
    node_stack.pop();

    curr->next = top;
  }

  curr->next = end;

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

    int len, left, right;
    cin >> len >> left >> right;

    vector<int> list(len);
    for (int i = 0; i < len; i++)
      cin >> list[i];

    ListNode *head = generate_list(list);
    ListNode *new_head = reverse_between(head, left, right);

    print_list(new_head);
  }

  return 0;
}
