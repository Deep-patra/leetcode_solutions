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

ListNode* generate_list(vector<int> list) {
  if (list.size() == 0)
    return nullptr;

  ListNode* head = new ListNode(list[0]);
  ListNode* curr = head;

  for (int i = 1; i < list.size(); i++) {
    curr->next = new ListNode(list[i]);
    curr = curr->next;
  }

  return head;
}

vector<ListNode*> generate_lists(vector<vector<int>> values) {
  vector<ListNode*> lists(values.size(), nullptr);

  for (int i = 0; i < values.size(); i++) 
    lists[i] = generate_list(values[i]);

  return lists;
}

ListNode *merge_k_lists(vector<ListNode *> &lists) {
  vector<ListNode*> curr(lists.size(), nullptr);

  for (int i = 0; i < lists.size(); i++)
    curr[i] = lists[i];

  ListNode* head = nullptr;

  // set the minimum node to the head
  int min_index = -1, min_val = values[0]->val;
  for (int i = 0; i < lists.size(); i++) {
    if (min_val > values[i]->val) {
      min_index = i;
      min_val = values[i]->val;
    }
  }

  head = curr[min_index];
  curr[min_index] = curr[min_index]->next;
 


  return head;
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len;
    cin >> len;

    vector<vector<int>> list(len);
    for (int i = 0; i < len; i++) {
      cin >> sub_len;

      vector<int> subarray(sub_len, 0);
      for (int j = 0; j < sub_len; j++) 
        cin >> subarray[i];

      list.push_back(subarray);

      vector<ListNode*> lists = generate_lists(list);
    }

  }

  return 0;
}
