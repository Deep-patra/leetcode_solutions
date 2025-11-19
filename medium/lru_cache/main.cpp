#include <bits/stdc++.h>  
using namespace std;

class LRUCache {
  static time = 0;
  int capacity;
  int size;

  vector<int> key_map;
  map<int, int> m;
public:
    LRUCache(int capacity) : capacity(capacity) {
      size = 0;
      key_map = vector<int>(10001, -1);
    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) {

    }
};

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    LRUCache c = NULL;

    vector<string> ops(n);
    for (int i = 0; i < n; i ++)
      cin >> ops[i];

    for (int i = 0; i < n; i ++) {
      if (ops[i] == "LRUCache") {
        int cap;
        cin >> cap;

        c = LRUCache(cap);   
        cout << "null" << " ";

      } else if (ops[i] == "put") {
        int a, b;
        cin >> a >> b;

        c.put(a, b);
        cout << "null" << " ";

      } else {
        int a;
        cin >> a;

        cout << c.get(a) << " ";
      }
    }
  }

  return 0;
}
