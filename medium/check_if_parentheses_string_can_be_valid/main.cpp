#include <deque>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// INFO: Didn't work
bool can_be_valid_greedy(string s, string locked) {
  int n = s.length();

  // if the string length is 1 or string length is odd
  if (n == 1 || n % 2 != 0)
    return false;

  // first character should be '('
  if (s[0] == ')' && locked[0] == '1')
    return false;

  // last character should be ')'
  if (s[n - 1] == '(' && locked[n - 1] == '1')
    return false;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      s[i] = ')';
      sum++;
    } else if (s[i] == ')') {
      s[i] = '(';
      sum--;
    }

    if (sum < 0) {
      if (locked[i] == '1')
        return false;
      else
        sum++;
    }

    // if the sum is more than half the length of the string
    // then there are more '('
    // loop back and turn '(' to ')' until the sum is less than n / 2
    else if (sum > n / 2) {

      int j = i;
      while (sum > n / 2 && j >= 0) {
        if (s[j] == '(' && locked[j] == '0')
          sum--;
        j--;
      }

      // if no '(' can be flipped then return false
      if (sum < 0)
        return false;
    }
  }

  return true;
}

// INFO: Using deque
// FIX: Doesn't work
bool can_be_valid_dque(string s, string locked) {

  if (s.length() == 0 || s.length() % 2 != 0)
    return false;

  if (s[0] == ')' && locked[0] == '1')
    return false;

  if (s[s.length() - 1] == '(' && locked[s.length() - 1] == '1')
    return false;

  deque<char> open_queue, close_queue;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(')
      if (locked[i] == '1')
        open_queue.push_back('1');
      else
        open_queue.push_front('0');
    else if (locked[i] == '1')
      close_queue.push_back('1');
    else
      close_queue.push_front('0');
  }

  while (open_queue.size() != close_queue.size()) {
    int open_size = open_queue.size();
    int close_size = close_queue.size();

    // if open brackets are more than close brackets
    // pop a close bracket from close queue and push it in front
    if (open_size < close_size) {

      if (close_queue.front() == '0') {
        open_queue.push_front('0');
        close_queue.pop_front();
      } else
        return false;
    }

    else {
      if (open_queue.front() == '0') {
        close_queue.push_front('0');
        open_queue.pop_front();
      } else
        return false;
    }
  }

  return true;
}

// INFO: Stack based Approach
bool can_be_valid_stack(string s, string locked) {
  if (s.length() % 2 != 0)
    return false;

  stack<int> open_brackets, unlocked;

  for (int i = 0; i < s.length(); i++) {
    if (locked[i] == '0')
      unlocked.push(i);

    else if (s[i] == '(')
      open_brackets.push(i);

    else if (s[i] == ')') {

      if (!open_brackets.empty())
        open_brackets.pop();
      else if (!unlocked.empty())
        unlocked.pop();
      else
        return false;
    }
  }

  while (!open_brackets.empty() && !unlocked.empty() &&
         open_brackets.top() < unlocked.top()) {
    open_brackets.pop();
    unlocked.pop();
  }

  if (!open_brackets.empty())
    return false;

  return true;
}

// INFO: Oms runtime approach
bool can_be_valid_0ms(string s, string locked) {
  const int n = s.size();
  if (n & 1)
    return 0;
  int bMin = 0, bMax = 0;
  for (int i = 0; i < n; i++) {
    bool op = s[i] == '(', wild = locked[i] == '0';
    bMin += (!op | wild) ? -1 : 1;
    bMax += (op | wild) ? 1 : -1;
    if (bMax < 0)
      return 0;
    bMin = max(bMin, 0);
  }
  return bMin == 0;
}
}

bool can_be_valid(string s, string locked) {
  return can_be_valid_stack(s, locked);
}

int main() {
  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    string s, locked;
    cin >> s >> locked;

    bool result = can_be_valid(s, locked);
    cout << result << '\n';
  }

  return 0;
}
