#include <bits/stdc++.h>  
using namespace std;

// INFO: Complete the Implementation
bool is_possible(vector<int> &cards, int mask) {

}

bool judge_point_24(vector<int> &cards) {
  
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    vector<int> cards(4);
    for(int i = 0; i < 4; i ++)
      cin >> cards[i];

    bool res = judge_point_24(cards);
    cout << res << '\n';
  }

  return 0;
}
