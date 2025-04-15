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

ListNode *generate_list(vector<int> &nums) {
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

void print_list(ListNode *head) {
  ListNode *curr = head;

  while (curr != nullptr) {
    cout << curr->val << ' ';
    curr = curr->next;
  }

  cout << '\n';
}

int get_size(ListNode* head) {
  int size = 0;
  ListNode* curr = head;

  while (curr != nullptr) {
    size ++;
    curr = curr->next;
  }

  return size;
}

ListNode* reverse(ListNode* start, ListNode* end) {
  ListNode* next = end->next, *head = end, *last = end, *curr = start;

  while (last != start) {
    
    while (curr->next != last) 
      curr = curr->next;

    last->next = curr;
    last = curr;

    curr = start;
  }

  start->next = next;

  return head;
}


ListNode* reverse_k_group(ListNode* head, int k) {

  if (k == 1) return head;

  int size = get_size(head);

  ListNode* next, *end, *curr = head, *start = head, *prev = head;

  int i = 1;
  while (curr != nullptr && i <= k) {
    i++;
    curr = curr->next;
  }
  
  next = curr->next;
  head = reverse(start, curr);

  if ((size / k) == 1) return head;

  size -= k;
  curr = next;
  start = next;

  while (curr != nullptr && size >= k) {
    i = 1;
    while (curr != nullptr && i <= k) {
      i ++;
      curr = curr->next;
    }

    next = curr->next;
    end = curr;
    
    prev->next = reverse(start, curr);

    curr = next;
    size -= k;
  }

  return head;
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

    ListNode *result = reverse_k_group(head, k);

    print_list(head);
  }

  return 0;
}
