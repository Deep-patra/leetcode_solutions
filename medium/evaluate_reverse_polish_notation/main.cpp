#include <bits/stdc++.h>  
using namespace std;

int eval_rpn(vector<string> &tokens) {
  int n = tokens.size();

  stack<int> st;

  for (int i = 0; i < n; i ++) {
    
    if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {

      int num1 = st.top();
      st.pop();

      int num2 = st.top();
      st.pop();

      // cout << num1 << " " << tokens[i] << " " << num2 << endl;

      switch(tokens[i][0]) {
        case '+': 
          st.push(num2 + num1);
          break;
        case '-':
          st.push(num2 - num1);
          break;
        case '*':
          st.push(num2 * num1);
          break;
        case '/':
          st.push(num2 / num1);
          break;
        default:
          break;
      }

    } else {
      st.push(stoi(tokens[i]));
    }

  }

  return st.top();
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<string> tokens(n);
    for (int i = 0; i < n; i ++)
      cin >> tokens[i];

    int res = eval_rpn(tokens);
    cout << res << '\n';
  }

  return 0;
}
