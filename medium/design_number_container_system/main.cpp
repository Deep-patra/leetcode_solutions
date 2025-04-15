#include <assert.h>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class NumberContainers {
private:
  unordered_map<int, set<int>> *values;
  unordered_map<int, int> assigned_number;

public:
  NumberContainers() { this->values = new unordered_map<int, set<int>>(); }

  void change(int index, int number) {

    auto values_it = values->find(number);

    if (values_it != values->end()) {

      if (assigned_number.find(index) != assigned_number.end())
        values->find(assigned_number[index])->second.erase(index);

      assigned_number.insert({index, number});
      values_it->second.insert(index);
      return;
    }

    assigned_number.insert({index, number});
    values->insert({number, {index}});

    return;
  }

  int find(int number) {
    auto it = values->find(number);

    if (it != values->end()) {
      set<int> s = (*it).second;

      if (!s.empty())
        return *s.begin();
    }

    return -1;
  }
};

int main() {
  NumberContainers *n = new NumberContainers();

  cout << "assert(n->find(10) == -1);" << endl;
  assert(n->find(10) == -1);

  n->change(2, 10);
  n->change(1, 10);
  n->change(3, 10);

  cout << "assert(n->find(10) == 1);" << endl;
  assert(n->find(10) == 1);

  n->change(1, 20);

  cout << "assert(n->find(10) == 2);" << endl;
  assert(n->find(10) == 2);

  return 0;
}
