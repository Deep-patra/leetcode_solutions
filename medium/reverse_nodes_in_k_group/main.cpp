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
  ListNode *head = new ListNode(nums[0]), *curr = head;

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

  cout << endl;
}

ListNode *reverse_k_group(ListNode *head, int k) {

  if (k <= 1 || head == nullptr)
    return head;

  ListNode *curr = head, *curr_head = nullptr, *prev = nullptr;

  stack<ListNode *> st;

  while (curr != nullptr) {

    ListNode *next = curr->next;

    st.push(curr);

    if (st.size() == k) {

      ListNode *c = st.top(), *h = st.top();
      st.pop();

      while (!st.empty()) {
        ListNode *t = st.top();

        c->next = t;
        c = t;

        st.pop();
      }

      if (curr_head == nullptr)
        curr_head = h;

      if (prev != nullptr)
        prev->next = h;

      prev = c;
      prev->next = next;
    }

    curr = next;
  }

  return curr_head;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];
    ListNode *head = generate_list(nums);

    ListNode *res = reverse_k_group(head, k);

    print_list(res);
  }

  return 0;
}
