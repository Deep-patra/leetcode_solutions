#include <iostream>
#include <vector>
using namespace std;

typedef struct ListNode {

  int val;
  ListNode *next;

public:
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}

} ListNode;

ListNode *generate_list(vector<int> list) {
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
  while (head != nullptr) {
    cout << head->val << " ";
    head = head->next;
  }

  cout << '\n';
}

ListNode *merge_two_lists(ListNode *list1, ListNode *list2) {
  ListNode *head;

  ListNode *curr1 = list1;
  ListNode *curr2 = list2;

  // if one of them are null
  // or both of them are null
  if (list1 == nullptr && list2 == nullptr)
    return nullptr;
  else if (list1 == nullptr && list2 != nullptr)
    return list2;
  else if (list2 == nullptr && list1 != nullptr)
    return list1;

  if (curr1->val < curr2->val) {
    head = curr1;
    curr1 = curr1->next;
  } else {
    head = curr2;
    curr2 = curr2->next;
  }

  ListNode *curr_result = head;

  while (curr1 != nullptr && curr2 != nullptr) {
    if (curr1->val < curr2->val) {
      curr_result->next = curr1;
      curr_result = curr_result->next;

      curr1 = curr1->next;
    } else {
      curr_result->next = curr2;
      curr_result = curr_result->next;

      curr2 = curr2->next;
    }
  }

  // add the remaining elements, if there are any
  if (curr1 == nullptr && curr2 != nullptr)
    curr_result->next = curr2;
  else if (curr2 == nullptr && curr1 != nullptr)
    curr_result->next = curr1;

  return head;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len1, len2;
    cin >> len1;

    vector<int> list1(len1, 0);
    for (int i = 0; i < len1; i++)
      cin >> list1[i];

    cin >> len2;

    vector<int> list2(len2, 0);
    for (int i = 0; i < len2; i++)
      cin >> list2[i];

    ListNode *head1 = generate_list(list1);
    ListNode *head2 = generate_list(list2);

    ListNode *result = merge_two_lists(head1, head2);

    print_list(result);
  }

  return 0;
}
