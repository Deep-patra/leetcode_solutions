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

void print_lists(ListNode *list) {
  ListNode *curr = list;

  while (curr != nullptr) {
    cout << curr->val << " ";
    curr = curr->next;
  }

  cout << endl;
}

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

vector<ListNode *> generate_lists(vector<vector<int>> values) {
  vector<ListNode *> lists(values.size(), nullptr);

  for (int i = 0; i < values.size(); i++)
    lists[i] = generate_list(values[i]);

  return lists;
}

template <typename T> vector<T> slice(vector<T> &lists, int start, int end) {
  vector<T> result(lists.begin() + start, lists.begin() + end);

  // cout << "start => " << start << " end => " << end << endl;
  // cout << "slice size => " << result.size() << endl;

  return result;
}

ListNode *merge_sort(vector<ListNode *> &lists) {
  if (lists.size() == 1)
    return lists[0];

  int l = 0, r = lists.size();
  int mid = l + (r - l) / 2;

  // cout << "l => " << l << " mid => " << mid << " r => " << r << endl;

  vector<ListNode *> list1 = slice(lists, 0, mid);
  vector<ListNode *> list2 = slice(lists, mid, r);

  ListNode *curr1 = merge_sort(list1);
  ListNode *curr2 = merge_sort(list2);

  // cout << "list 1 => " << endl;
  // print_lists(curr1);
  //
  // cout << "list 2 => " << endl;
  // print_lists(curr2);

  ListNode *head = nullptr;

  // Initialize the head for the result linked list
  if (curr1 != nullptr && curr2 != nullptr) {
    if (curr1->val < curr2->val) {
      head = curr1;
      curr1 = curr1->next;
    } else {
      head = curr2;
      curr2 = curr2->next;
    }
  } else if (curr1 != nullptr) {
    head = curr1;
    curr1 = curr1->next;
  } else if (curr2 != nullptr) {
    head = curr2;
    curr2 = curr2->next;
  }

  ListNode *curr = head;

  while (curr1 != nullptr && curr2 != nullptr) {

    if (curr1->val < curr2->val) {
      curr->next = curr1;
      curr1 = curr1->next;
    } else {
      curr->next = curr2;
      curr2 = curr2->next;
    }

    curr = curr->next;
  }

  if (curr1 != nullptr)
    curr->next = curr1;

  if (curr2 != nullptr)
    curr->next = curr2;

  // cout << "Printing list => " << endl;
  // print_lists(head);

  return head;
}

// using merge sort approach
ListNode *merge_k_lists(vector<ListNode *> &lists) {
  ListNode *result = merge_sort(lists);
  return result;
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len, sub_len;
    cin >> len;

    vector<vector<int>> list(len);
    for (int i = 0; i < len; i++) {
      cin >> sub_len;

      list[i].resize(sub_len);

      for (int j = 0; j < sub_len; j++)
        cin >> list[i][j];
    }

    vector<ListNode *> lists = generate_lists(list);

    // cout << "Generated Lists" << endl;

    ListNode *result = merge_k_lists(lists);

    print_lists(result);
  }

  return 0;
}
