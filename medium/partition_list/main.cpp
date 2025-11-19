#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *generate_list(vector<int> &nums) {
  ListNode *head = new ListNode(), curr = head;

  for (int val : nums) {
    curr->val = val;
    curr->next = new ListNode();
    curr = curr->next;
  }

  return head;
}

ListNode *partition(ListNode *head, int k) {
  ListNode *curr = head, *c = nullptr, *t = nullptr;
  ListNode *h1 = nullptr, *h2 = nullptr;

  while (curr != nullptr) {

    if (curr->val < x) {

      if (h1 == nullptr) {
        h1 = curr;
        c = curr;
      } else {
        c->next = curr;
        c = c->next;
      }

    } else {

      if (h2 == nullptr) {
        h2 = curr;
        t = curr;
      } else {
        t->next = curr;
        t = t->next;
      }
    }

    curr = curr->next;
  }

  if (t != nullptr)
    t->next = nullptr;
  if (c != nullptr)
    c->next = nullptr;

  if (h1 == nullptr)
    h1 = h2;
  else
    c->next = h2;

  return h1;
}

int main() {
  e int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    ListNode *head = generate_list(nums);
  }

  return 0;
}
